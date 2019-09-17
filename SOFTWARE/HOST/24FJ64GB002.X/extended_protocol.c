/*
 * File:   extended_protocol.c
 * Author: mleon
 *
 * Created on 01 de septiembre de 2018, 20:19
 */

#include "extended_protocol.h"

#define VERSION_EXTENDED_PROTOCOL "1.4"

const char MAX_SEQUENCE_NUMBER = 0xFF;
const char MIN_SEQUENCE_NUMBER = 0x81;
const char ETX = 0x03;
const char STX = 0x02;
const char ESC = 0x1b;
const char FLD = 0x1c;
const char RI = 0x80;
const char NACK = 0x15;
const char ACK = 0x06;

const int MAX_DATA_FRAME_LENTH = 74;
const int DATA_FRAME_WITHOUT = 69;
const int CHECKSUM_LENTH = 4;

int sequenceNumber = 0;
char dataFrame[74] = {};
char frameWithoutCS[69] = {};
char checksum[4] = {};

/**
 * El frame de datos para enviar un comando se arma de la siguiente manera:
 *
 * STX | secuenseNumber | command | ETX | checksum[0] | checksum[1] | checksum[2] | checksum[3]
 *
 * @param command
 * @return
 */
char * protocol_createCommandFrame(char command) {
    protocol_initFrame(dataFrame, MAX_DATA_FRAME_LENTH, protocol_getSequenceNumber());
    char data[1] = {command};
    protocol_addData(dataFrame, data);
    dataFrame[4] = ETX;
    char * cs = protocol_calculateChecksum(dataFrame);
    strcat(dataFrame, cs);
    dataFrame[9] = '\0';
    return dataFrame;
}

/**
 * Crea el frame de datos a enviar a a dispositivos de terceros.
 * 
 * STX | secuenseNumber | FLD | field_0 | FLD | field_1 | ... | FLD | field_n | 
 * ETX | checksum[0] | checksum[1] | checksum[2] | checksum[3]
 * 
 * Donde field_n son la informacion a transmitir. Estan permitidos todos los ascii 
 * menos ETX, STX, ESC, FLD. 
 * 
 * @param measurement
 * @param secuenseNumber tiene que ser el mismo que se envio con el comando.
 * @return 
 */
char * protocol_createMasterFrame(Measurement measurement) {
    protocol_initFrame(dataFrame, MAX_DATA_FRAME_LENTH, protocol_getSequenceNumber());
    protocol_addData(dataFrame, measurement.sensor);
    protocol_addData(dataFrame, measurement.valor);
    protocol_addData(dataFrame, measurement.longitud);
    protocol_addData(dataFrame, measurement.latitud);
    protocol_addData(dataFrame, measurement.fecha);
    dataFrame[67] = ETX;
    char * cs = protocol_calculateChecksum(dataFrame);
    strcat(dataFrame, cs);
    dataFrame[72] = '\0';
    return dataFrame;
}

/**
 * Crea el frame de datos a enviar al maestro.
 * 
 * STX | secuenseNumber | FLD | field_0 | FLD | field_1 | ... | FLD | field_n | 
 * ETX | checksum[0] | checksum[1] | checksum[2] | checksum[3]
 * 
 * Donde field_n son la informacion a transmitir. Estan permitidos todos los ascii 
 * menos ETX, STX, ESC, FLD. 
 * 
 * @param measurement
 * @param secuenseNumber tiene que ser el mismo que se envio con el comando.
 * @return 
 */
char * protocol_createSlaveFrame(Measurement measurement) {
    protocol_initFrame(dataFrame, MAX_DATA_FRAME_LENTH, protocol_getSequenceNumber());
    protocol_addData(dataFrame, measurement.sensor);
    protocol_addData(dataFrame, measurement.valor);
    dataFrame[25] = ETX;
    char * cs = protocol_calculateChecksum(dataFrame);
    strcat(dataFrame, cs);
    dataFrame[30] = '\0';
    return dataFrame;
}

/**
 * Calcula el Checksum del frame de datos.
 * 
 * @param frame
 * @return 
 */
char * protocol_calculateChecksum(char frame[]) {
    int sum = 0, i = 0;
    int frameLenght = strlen(frame);
    for (i = 0; i < frameLenght; i++) {
        sum += (unsigned char) frame[i];
    }
    i = 0;
    protocol_clearArray(checksum, CHECKSUM_LENTH);
    for (i = 0; i < 4; i++) {
        int iAux = (sum >> (12 - (i * 4))) & 15;
        if (iAux < 10) {
            checksum[i] = iAux + 48;
        } else {
            checksum[i] = (iAux + 65) - 10;
        }
    }
    return checksum;
}

/**
 * Dado el frame de datos, verifica que el checksum sea correcto.
 * @param frame
 * @return 
 */
bool protocol_verifyChecksum(char frame[]) {
    int frameLenght = strlen(frame);
    protocol_clearArray(frameWithoutCS, DATA_FRAME_WITHOUT);
    strncpy(frameWithoutCS, frame, frameLenght - 4);
    char * checksum = protocol_calculateChecksum(frameWithoutCS);
    if (frame[frameLenght - 1] == checksum[3] && frame[frameLenght - 2] == checksum[2] &&
            frame[frameLenght - 3] == checksum[1] && frame[frameLenght - 4] == checksum[0]) {
        return true;
    } else {
        return false;
    }
}

/**
 * Retorna el numero de secuencia, incremental en cada requerimiento.
 * 
 * @return sequenceNumber
 */
char protocol_getSequenceNumber() {
    if ((sequenceNumber < MIN_SEQUENCE_NUMBER) || (sequenceNumber >= MAX_SEQUENCE_NUMBER)) {
        return sequenceNumber = MIN_SEQUENCE_NUMBER;
    } else {
        ++sequenceNumber;
    }
    return 0x81;
}

/**
 * Añade un campo al frame y agrega el separador FS [1c].
 * 
 * @param dataFrame
 * @param data
 */
void protocol_addData(char dataFrame[], char data[]) {
    strcat(dataFrame, data);
    dataFrame[strlen(dataFrame)] = FLD;
}

/**
 * Inicializa el frame con los datos comunes a todos.
 * 
 * @param frame
 * @param arrayLength
 * @param seq
 */
void protocol_initFrame(char frame[], int arrayLength, char seq) {
    protocol_clearArray(frame, arrayLength);
    frame[0] = STX;
    frame[1] = seq;
}

/**
 *  Limpiamos el array. Podria tener datos de una llamada anterior.
 * @param array
 * @param length
 */
void protocol_clearArray(char array[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        array[i] = '\0';
        //        printf("%d %c\n", i, array[i]);
    }
}

/**
 * parsea el frame de respuesta enviado por el esclavo.
 * 
 * @param slaveFrame
 * @param measurement
 */
Measurement protocol_parseSlaveFrame(Measurement measurement, char slaveFrame []) {
    char fsDelimiter[] = {0x1c};
    char seqDelimiter[] = {0x81};
    char * pch;
    pch = strtok(slaveFrame, seqDelimiter);
    int parseIndex = 0;
    while (pch != NULL) {
        if (parseIndex == 1) {
            strcpy(measurement.sensor, pch);
        }
        if (parseIndex == 2) {
            strcpy(measurement.valor, pch);
        }
        pch = strtok(NULL, fsDelimiter);
        parseIndex++;
    }
    return measurement;
}

/**
 * Imprime un frame en hexa y en cadena de caracteres.
 * 
 * @param frame
 */
void protocol_printFrame(char * frame) {
    int frameLenght = strlen(frame);
    int index;
    for (index = 0; index < frameLenght; index++) {
        if (frame[index] == '\0') {
            break;
        }
        printf("%s", "0x");
        printf("%02x", (unsigned char) frame[index]);
        printf("%s", " ");
    }
    printf("\n\n");
    printf("%s", frame);
    printf("\n\n");
}