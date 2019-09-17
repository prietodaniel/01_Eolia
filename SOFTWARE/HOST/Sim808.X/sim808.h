/* 
 * File:   sim808.h
 * author: mleon
 *
 * Created on February 16, 2019, 1:42 PM
 */

#ifndef SIM808_H
#define	SIM808_H

#include "xc.h"
#include "stdbool.h"
#include "../Protocol.X/dist/default/../../extended_protocol.h"
#include "../24FJ64GB002.X/dist/default/../../mcc_generated_files/uart1.h"
#include "../24FJ64GB002.X/dist/default/../../mcc_generated_files/clock.h"
#include <libpic30.h>
#include <string.h>

char* fillWithZeros(char[], char[], char[], int);
bool sim808_sendATCommandAndWaitResponse(char[], int, int);
bool sim808_sendATCommandAndWaitResponseDefault(char[], int);
bool sim808_init(void);
bool sim808_httpGET(Measurement);
bool sim808_waitGPSReady(void);
Measurement sim808_readGPS(void);
Measurement sim08_parseGPSResponse(void);

#endif	/* SIM808_H */

