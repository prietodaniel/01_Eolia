/*
 * File:   sim808.c
 * author: mleon
 *
 * Created on February 16, 2019, 1:41 PM
 */


#include "sim808.h"

#define VERSION_SIM808 "1.5"

char response[160] = {};
Measurement measurement;

bool sim808_sendATCommandAndWaitResponse(char command[], int delay_ms, int crCount) {
    __delay_ms(delay_ms);
    int timeOut_ms = 3000;
    int count = 0;
    UART1_WriteBuffer(command);
    protocol_clearArray(response, 160);
    do {
        UART1_ReadBuffer(response, crCount);
        if ((response[35] != 'O' && response[36] != 'K') || (response[2] == 'O' && response[3] == 'K')
                || (response[2] != 'E' && response[3] != 'R')) {
            return true;
        }
        __delay_ms(1);
        count++;
    } while (count < timeOut_ms);
    return false;
}

bool sim808_sendATCommandAndWaitResponseDefault(char command[], int delay_ms) {
    return sim808_sendATCommandAndWaitResponse(command, delay_ms, 2);
}

bool sim808_init() {
    __delay_ms(30000);
    return sim808_sendATCommandAndWaitResponseDefault("AT + CGNSPWR = 1\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + CIPSHUT\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + CIPMUX = 0\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + CSTT = <gprs.personal.com>, <gprs>, <gprs>\r", 5000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + CIICR\r", 5000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + CIFSR\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + SAPBR = 3, 1, Contype, GPRS\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + SAPBR = 3, 1, APN, gprs.personal.com\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + SAPBR = 1, 1\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + SAPBR = 2, 1\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + HTTPINIT\r", 3000) &&
            sim808_sendATCommandAndWaitResponseDefault("AT + HTTPPARA = cid, 1\r", 3000);
}

bool sim808_httpGET(Measurement measurement) {
    protocol_clearArray(response, 160);
    char urlSeparator[] = {0x2f, '\0'};
    char cr[] = {0x0d, '\0'};
    strcat(response, "AT + HTTPPARA = url, http://35.190.137.150:8080/Eolia/resource/rest/maps/addMeasurement/");
    strcat(response, measurement.sensor);
    strcat(response, urlSeparator);
    strcat(response, measurement.valor);
    strcat(response, urlSeparator);
    strcat(response, measurement.latitud);
    strcat(response, urlSeparator);
    strcat(response, measurement.longitud);
    strcat(response, urlSeparator);
    strcat(response, measurement.fecha);
    strcat(response, cr);
    return sim808_sendATCommandAndWaitResponseDefault(response, 3000) &&
            sim808_sendATCommandAndWaitResponse("AT + HTTPACTION = 0\r", 3000, 4) &&
            sim808_sendATCommandAndWaitResponse("AT + HTTPREAD\r", 3000, 4);
}

bool sim808_waitGPSReady() {
    int count = 0;
    int reintentos = 120;
    Measurement measurement;
    //Espera 120000 ms como maximo para que el GPS tome minimo 4 satelites.
    while (reintentos > count) {
        measurement = sim808_readGPS();
        if (measurement.gpsFixStatus[0] == '1') {
            return true;
        }
        count++;
        __delay_ms(3000);
    }
    return false;
}

Measurement sim808_readGPS() {
    sim808_sendATCommandAndWaitResponseDefault("AT + CGNSINF\r", 3000);
    return sim08_parseGPSResponse();
}

Measurement sim08_parseGPSResponse() {
    char * pch;
    pch = strtok(response, ",");
    int parseIndex = 0;
    while (pch != NULL) {
        if (parseIndex == 1) {
            strcpy(measurement.gpsFixStatus, pch);
        }
        if (parseIndex == 2) {
            strcpy(measurement.fecha, pch);
        }
        if (parseIndex == 3) {
            char fixLat[12] = {};
            strcpy(measurement.latitud, fillWithZeros(pch, "%-10s", fixLat, 12));
        }
        if (parseIndex == 4) {
            char fixLong[12] = {};
            strcpy(measurement.longitud, fillWithZeros(pch, "%-11s", fixLong, 12));
        }
        pch = strtok(NULL, ",");
        parseIndex++;
    }
    return measurement;
}

char* fillWithZeros(char stringTofill[], char formatFill[], char resultStore[], int resultStoreLenght) {
    int i;
    sprintf(resultStore, formatFill, stringTofill);
    for (i = 0; i < resultStoreLenght; i++) {
        if (resultStore[i] == ' ') {
            resultStore[i] = '0';
        }
    }
    resultStore[resultStoreLenght] = '\0';
    return resultStore;
}