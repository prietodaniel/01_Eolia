/*
 * File:   main.c
 * Author: mleon
 *
 * Created on 11 de septiembre de 2018, 11:38
 */


#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "utils.h"
#include "../Protocol.X/dist/default/../../extended_protocol.h"

/* CONFIG1 */
#pragma config FOSC = INTRC_NOCLKOUT  /* uso de oscilador interno - E/S en pines RA6 y RA7 */
#pragma config WDTE = OFF             /* deshabilita Watchdog Timer */
#pragma config PWRTE = OFF            /* deshabilita Power-up Timer */
#pragma config MCLRE = ON            /* RE3 E/digital - MCLR conectado internamente a VDD */
#pragma config CP = OFF               /* deshabilita protección de código                  */
#pragma config CPD = OFF              /* deshabilita protección de memoria de datos */
#pragma config BOREN = OFF            /* deshabilita Brown Out Detect */
#pragma config IESO = OFF             /* desactiva Internal External Switchover */
#pragma config FCMEN = OFF            /* desactiva Fail-Safe Clock Monitor */
#pragma config LVP = OFF              /* RB3 E/S digital, HV on MCLR usado para programado */
/* CONFIG2 */
//#pragma config BOR4V = BOR40V         /* Brown-out Reset configurada a 4.0V              */
#pragma config WRT = OFF              /* protección de auto escritura de Flash deshab. */

#define _XTAL_FREQ  4000000 
#define TEST_PROTOCOL_VERSION "1.2"

char* fillWithZeros(char[], char[], char[], int);

//char slaveFrameTest[] = {0x02, 0x81, 0x31, 0x5f, 0x43, 0x4f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x1c, 0x31, 0x32, 0x33, 0x34, 0x2e, 0x35, 0x36, 0x37, 0x1c, 0x03, 0x30, 0x36, 0x44, 0x31};

//char response[] = "\n\r\n+CGNSINF: 1,1,20190227024639.000,-31.411728,-64.207940,434.300,0.00,337.2,1,,1.3,2.3,1.9\r";

void main(void) {
    system_configureOscillator();
    TXSTAbits.TXEN = 1; // enable transmitter
    RCSTAbits.SPEN = 1;
    for (;;) {
        bool isChecksumOK;

        Measurement measurement;
        strcpy(measurement.sensor, "1_CO_________");
        strcpy(measurement.valor, "0010.560");
        strcpy(measurement.latitud, "-31.415195");
        strcpy(measurement.longitud, "-64.2081239");
        strcpy(measurement.fecha, "20190213000850.000");

        //      char command[] = "AT + HTTPPARA = url, http://35.190.137.150:8080/Eolia/resource/rest/maps/addMeasurement/nombre_sensor/11111111/-31.4151959/-64.2081239/20190213000850.000\r";
        //
        //
        //*******************************Request**************************************** 
        //                char * commandFrame = protocol_createCommandFrame('a');
        //                isChecksumOK = protocol_verifyChecksum(commandFrame);
        //                if (isChecksumOK == true) {
        //                    char message[] = "OK";
        //                }
        //                protocol_printFrame(commandFrame);


        //*******************************Response Master**************************************** 
        //        char * masterFrame = protocol_createMasterFrame(measurement);
        //        isChecksumOK = protocol_verifyChecksum(masterFrame);
        //        if (isChecksumOK == true) {
        //            char message[] = "OK";
        //        }
        //        protocol_printFrame(masterFrame);

        //*******************************Response Slave****************************************

        char * slaveFrame = protocol_createSlaveFrame(measurement);
        isChecksumOK = protocol_verifyChecksum(slaveFrame);
        if (isChecksumOK == true) {
            char message[] = "OK";
        }
        protocol_printFrame(slaveFrame);


        //*******************************Parse Slave Protocol****************************************

        //        measurement = protocol_parseSlaveFrame(measurement, slaveFrameTest);
        //        protocol_printFrame(measurement.sensor);
        //        printf("\n");
        //        protocol_printFrame(measurement.valor);

    }
}
