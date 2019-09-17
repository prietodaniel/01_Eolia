/* 
 * File: extended_protocol.h   
 * Author: mleon
 * Comments:
 * Revision history: v1.0 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  


#ifndef EXTENDED_PROTOCOL_H
#define	EXTENDED_PROTOCOL_H

#include "stdio.h"
#include "stdbool.h"
#include "string.h"

typedef struct {
    char sensor[14]; //"nombre_sensor" -> 13 + '\0'
    char latitud[11]; //4316.64500 -> 10 + '\0'  
    char longitud[12]; //257.667700 -> 11 + '\0'
    char valor[9]; //1111.111 -> 8  + '\0' 
    char fecha[19]; //20170117141311.000 -> 18 + '\0'
    char gpsFixStatus[2]; //0-1 -> 1 + '\0'
} Measurement;

void protocol_clearArray(char[], int);
void protocol_initFrame(char[], int, char);
void protocol_addData(char [], char []);
void protocol_printFrame(char[]);
char * protocol_createCommandFrame(char);
char * protocol_createMasterFrame(Measurement);
char * protocol_createSlaveFrame(Measurement);
char * protocol_calculateChecksum(char[]);
char protocol_getSequenceNumber(void);
bool protocol_verifyChecksum(char[]);
Measurement protocol_parseSlaveFrame(Measurement, char []);

#endif

