
/* 
 * File:  i2c_master     
 * Author: Daniel Prieto    
 * Comments: I2C Library
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>
#include <p24FJ64GB002.h>
#include "extended_protocol.h"

typedef enum {
    I2C_MASTER_IDLE,
    I2C_MASTER_PUT_ADDRESS,
    I2C_MASTER_ENVIANDO_DIRECCION,
    I2C_MASTER_RECIBIENDO_DATO,
    I2C_MASTER_ENVIANDO_ACK,
    I2C_MASTER_CERRANDO_COMUNICACION
} I2C_MASTER_STATUS;

void i2c_masterInit(void);
void i2c_masterStart(char address);
char* i2c_waitToRecibeDataFromSlave(void);
void i2c_masterDisable(void);
//    void __interrupt() I2C_Master_Read_ISR(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

