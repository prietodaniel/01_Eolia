/*
 * File:   i2c.c
 * Author: dani_
 *
 * Created on February 11, 2019, 10:19 PM
 */

#include "i2c_master.h"

extern const char ETX;
extern const int MAX_DATA_FRAME_LENTH;

char direccion;
char frame[75];
int frameIndex = 0;
int lastFrameIndex = -1;
I2C_MASTER_STATUS estado_previo;
bool recibeDataFinished = false;

void i2c_masterInit(void) {
    I2C1CONbits.I2CEN = 0;
    I2C1CONbits.I2CSIDL = 1;
    I2C1CONbits.IPMIEN = 0;
    I2C1CONbits.A10M = 0;
    I2C1CONbits.DISSLW = 0;
    I2C1CONbits.SMEN = 0;

    I2C1BRG = 0x27; //100 Khz y 8 MHz Clock.

    I2C1STAT = 0;
    TRISBbits.TRISB9 = 1;
    TRISBbits.TRISB8 = 1;

    IFS1bits.MI2C1IF = 0;
    IEC1bits.MI2C1IE = 1;

    I2C1CONbits.I2CEN = 1;
}

void i2c_masterStart(char address) {
    i2c_masterInit();
    I2C1CONbits.SEN = 1;
    direccion = address;
}

void __attribute__((interrupt, auto_psv)) _MI2C1Interrupt() {
    if (IFS1bits.MI2C1IF == 1) {
        IFS1bits.MI2C1IF = 0;
        if (estado_previo == I2C_MASTER_IDLE) {
            recibeDataFinished = false;
            I2C1TRN = direccion;
            estado_previo = I2C_MASTER_ENVIANDO_DIRECCION;
        } else if (estado_previo == I2C_MASTER_ENVIANDO_DIRECCION) {
            while (I2C1STATbits.ACKSTAT);
            if (I2C1STATbits.ACKSTAT == 0) {
                I2C1CONbits.RCEN = 1;
                estado_previo = I2C_MASTER_RECIBIENDO_DATO;
            } else {
                I2C1CONbits.PEN = 1;
                estado_previo = I2C_MASTER_CERRANDO_COMUNICACION;
            }
        } else if (estado_previo == I2C_MASTER_RECIBIENDO_DATO) {
            while (!I2C1STATbits.RBF);
            frame[frameIndex] = I2C1RCV;
            //Una vez recibido el caracter ETX solo queda recibir el checkSum que son 4 caracteres mas.
            if (frame[frameIndex] == ETX) {
                lastFrameIndex = frameIndex + 4;
            }
            if ((frameIndex == lastFrameIndex) || (frameIndex > MAX_DATA_FRAME_LENTH)) {
                recibeDataFinished = true;
                I2C1CONbits.ACKDT = 1;
            } else {
                frameIndex++;
                I2C1CONbits.ACKDT = 0;
            }

            I2C1CONbits.ACKEN = 1;
            estado_previo = I2C_MASTER_ENVIANDO_ACK;
        } else if (estado_previo == I2C_MASTER_ENVIANDO_ACK) {
            if (I2C1CONbits.ACKDT == 1) {
                I2C1CONbits.PEN = 1;
                estado_previo = I2C_MASTER_CERRANDO_COMUNICACION;
            } else {
                I2C1CONbits.RCEN = 1;
                estado_previo = I2C_MASTER_RECIBIENDO_DATO;
            }
        } else { //I2C_MASTER_CERRANDO_COMUNICACION.
            estado_previo = I2C_MASTER_IDLE;
            frameIndex = 0;
            lastFrameIndex = -1;
        }
    }
}

char * i2c_waitToRecibeDataFromSlave() {
    while (!recibeDataFinished);
    return frame;
}
