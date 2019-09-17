/*
 * File:   i2c.c
 * Author: Daniel Prieto
 *
 * Created on February 4, 2019, 8:38 PM
 */
#include "i2c.h"
#include "mcc_generated_files/pin_manager.h"

extern I2C_SLAVE_STATUS slave_estado_previo;
extern uint16_t convertedValue[100];

Measurement medicion;

char* measurementFrame;
int dataIndex = 0;
int txCounter = 0;

extern I2C_MASTER_STATUS master_estado_previo;
extern int LMP_Read;
uint8_t registro;
uint8_t data_to_send;
extern uint8_t data_received;
extern uint8_t data_read_ready;


void I2C_Master_Init(const unsigned long c) { //Para controlar el LMP.
    SSP2CON1 = 0b00101000; //Master Mode without enable.
    SSP2CON2 = 0;
    SSP2ADD = 19;
    SSP2STAT = 0b00000000;
    ANSELB = 0x00; //SDA 
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB7 = 1;
    PIR4bits.SSP2IF = 0;
    PIE4bits.SSP2IE = 1;
    SSP2CON1bits.SSPEN = 1;
}

void I2C_Slave_Init(short address) {
    SSP1STAT = 0x80;
    SSP1ADD = address;
    //7 bits, con interrupciones en START y STOP.
    SSP1CON1 = 0b00010110;
    SSP1CON2 = 0x01;
    ANSELB = 0x30; //0b00110000 y esto???? b4(sda) en 1 y b6 (scl)en 0....
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB6 = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.SSP1IF = 0;
    PIE1bits.SSP1IE = 1;
    SSP1CON1bits.SSPEN = 1;
}

void I2C_Master_Wait() {
    while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F));
}

void LMP91000_Write(uint8_t reg, uint8_t data) {
    registro = reg;
    data_to_send = data;
    LMP_Read = 0;
    I2C_Master_Init(100000);
    I2C_Master_Wait();
    SSP2CON2bits.SEN = 1;
}

void LMP91000_Read(uint8_t reg) {
    data_received = 0;
    MENB_SetLow();
    registro = reg;
    LMP_Read = 1;
    I2C_Master_Init(100000);
    I2C_Master_Wait();
    SSP2CON2bits.SEN = 1;
}

void __interrupt() I2C_ISR() {
    if (PIR1bits.SSP1IF == 1) {
        if (txCounter > 0x1F) {
            returnToIdleState();
            return;
        }
        txCounter++;
        PIR1bits.SSP1IF = 0;
        if (slave_estado_previo == I2C_SLAVE_IDLE) {
            //Mando el primer dato
            //medicion.sensor = "1_CO_________";
            strcpy(medicion.sensor, "1_CO_________");
            //medicion.valor = adcToMeasurementValue();
            strcpy(medicion.valor, adcToMeasurementValue());
            measurementFrame = protocol_createSlaveFrame(medicion);
            dataIndex = 0;
            SSP1CON1bits.CKP = 0;
            //SSP1BUF = measurementFrame[dataIndex];
            SSP1BUF = 
            dataIndex++;
            SSP1CON1bits.CKP = 1;
            slave_estado_previo = I2C_SLAVE_ENVIANDO_DATO;
        } else if (slave_estado_previo == I2C_SLAVE_ENVIANDO_DATO) {
            if (SSP1CON2bits.ACKSTAT) {
                //Se cierra la comunicacion
                returnToIdleState();
            } else {
                //Se envian los siguientes datos.
                SSP1CON1bits.CKP = 0;
                SSP1BUF = measurementFrame[dataIndex];
                dataIndex++;
                while (!SSP1STATbits.BF);
                SSP1CON1bits.CKP = 1;
                slave_estado_previo = I2C_SLAVE_ENVIANDO_DATO;
            }
        }
    }
    if (PIR4bits.SSP2IF == 1) {
        PIR4bits.SSP2IF = 0;
        if (master_estado_previo == I2C_MASTER_IDLE) {
            while (SSP2CON2bits.SEN);
            SSP2BUF = 0x90; //Direccion del LMP91000  = 1001000....
            master_estado_previo = I2C_MASTER_ENVIANDO_ADDRESS;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_ADDRESS) {
            if (SSP2CON2bits.ACKSTAT == 0) {
                SSP2BUF = registro; //Aca iria el registro a leer/escribir.
                master_estado_previo = I2C_MASTER_ENVIANDO_REGISTRO;
            } else {
                SSP2CON2bits.PEN = 1; //No recibi un ACK por lo que detengo la comunicacion. 
                master_estado_previo = I2C_MASTER_STOP;
            }
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_REGISTRO) {
            if (SSP2CON2bits.ACKSTAT == 0) {
                if (LMP_Read == 0) {
                    SSP2BUF = data_to_send;
                    master_estado_previo = I2C_MASTER_ENVIANDO_DATO;
                } else {
                    SSP2CON2bits.RSEN = 1;
                    master_estado_previo = I2C_MASTER_ENVIANDO_RESTART;
                }
            }
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_RESTART) {
            while (SSP2CON2bits.RSEN);
            SSP2BUF = 0x91; //ahora si escribo la direccion con Read
            master_estado_previo = I2C_MASTER_ENVIANDO_ADRESS_PARA_LEER;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_ADRESS_PARA_LEER) {
            //Aca pongo modo lectura
            if (SSP2CON2bits.ACKSTAT == 0) {
                SSP2CON2bits.RCEN = 1; //Esto genera los clocks para que el esclavo mande datos. 
                master_estado_previo = I2C_MASTER_RECIBIENDO_DATO;
            } else {
                SSP2CON2bits.PEN = 1; //No recibi un ACK por lo que detengo la comunicacion. 
                master_estado_previo = I2C_MASTER_STOP;
            }
        } else if (master_estado_previo == I2C_MASTER_RECIBIENDO_DATO) {
            while (!SSP2STATbits.BF);
            data_received = SSP2BUF;
            SSP2CON2bits.ACKDT = 0;
            SSP2CON2bits.ACKEN = 1;
            data_read_ready = 1;
            master_estado_previo = I2C_MASTER_ENVIANDO_NACK;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_DATO || master_estado_previo == I2C_MASTER_ENVIANDO_NACK) {
            //I2C_MASTER_STOP
            SSP2CON2bits.PEN = 1; //Despues de mandar el dato o recibir el dato paro la comunicaion.
            master_estado_previo = I2C_MASTER_STOP;
        } else { //Se cierra la comunicacion, ultima interrupcion. 
            master_estado_previo = I2C_MASTER_IDLE;
        }
    }
}
/*
void __interrupt() I2C_Master_ISR(){
    if (PIR4bits.SSP2IF == 1) {
        PIR4bits.SSP2IF = 0;
        if (master_estado_previo == I2C_MASTER_IDLE) {
            while (SSP2CON2bits.SEN);
            SSP2BUF = 0x90; //Direccion del LMP91000  = 1001000....
            master_estado_previo = I2C_MASTER_ENVIANDO_ADDRESS;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_ADDRESS) {
            if (SSP2CON2bits.ACKSTAT == 0) {
                SSP2BUF = registro; //Aca iria el registro a leer/escribir.
                master_estado_previo = I2C_MASTER_ENVIANDO_REGISTRO;
            } else {
                SSP2CON2bits.PEN = 1; //No recibi un ACK por lo que detengo la comunicacion. 
                master_estado_previo = I2C_MASTER_STOP;
            }
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_REGISTRO) {
            if (SSP2CON2bits.ACKSTAT == 0) {
                if (LMP_Read == 0) {
                    SSP2BUF = data_to_send;
                    master_estado_previo = I2C_MASTER_ENVIANDO_DATO;
                } else {
                    SSP2CON2bits.RSEN = 1;
                    master_estado_previo = I2C_MASTER_ENVIANDO_RESTART;
                }
            }
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_RESTART) {
            while (SSP2CON2bits.RSEN);
            SSP2BUF = 0x91; //ahora si escribo la direccion con Read
            master_estado_previo = I2C_MASTER_ENVIANDO_ADRESS_PARA_LEER;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_ADRESS_PARA_LEER) {
            //Aca pongo modo lectura
            if (SSP2CON2bits.ACKSTAT == 0) {
                SSP2CON2bits.RCEN = 1; //Esto genera los clocks para que el esclavo mande datos. 
                master_estado_previo = I2C_MASTER_RECIBIENDO_DATO;
            } else {
                SSP2CON2bits.PEN = 1; //No recibi un ACK por lo que detengo la comunicacion. 
                master_estado_previo = I2C_MASTER_STOP;
            }
        } else if (master_estado_previo == I2C_MASTER_RECIBIENDO_DATO) {
            while (!SSP2STATbits.BF);
            data_received = SSP2BUF;
            SSP2CON2bits.ACKDT = 0;
            SSP2CON2bits.ACKEN = 1;
            data_read_ready = 1;
            master_estado_previo = I2C_MASTER_ENVIANDO_NACK;
        } else if (master_estado_previo == I2C_MASTER_ENVIANDO_DATO || master_estado_previo == I2C_MASTER_ENVIANDO_NACK) {
            //I2C_MASTER_STOP
            SSP2CON2bits.PEN = 1; //Despues de mandar el dato o recibir el dato paro la comunicaion.
            master_estado_previo = I2C_MASTER_STOP;
        } else { //Se cierra la comunicacion, ultima interrupcion. 
            master_estado_previo = I2C_MASTER_IDLE;
        }
    }
}
*/
    
void returnToIdleState() {
    slave_estado_previo = I2C_SLAVE_IDLE;
    txCounter = 0;
    dataIndex = 0;
}
