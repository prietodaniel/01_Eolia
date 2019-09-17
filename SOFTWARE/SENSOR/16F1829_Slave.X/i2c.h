/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: Daniel Prieto
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <pic16f1829.h>
#include "mcc_generated_files/device_config.h"
#include "../Protocol.X/dist/../extended_protocol.h"
#include "mcc_generated_files/adc.h"
#include <stdint.h>


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef enum {
        I2C_MASTER_IDLE,
        I2C_MASTER_ENVIANDO_ADDRESS,
        I2C_MASTER_ENVIANDO_REGISTRO,
        I2C_MASTER_ENVIANDO_DATO,
        I2C_MASTER_ENVIANDO_RESTART,
        I2C_MASTER_ENVIANDO_ADRESS_PARA_LEER,
        I2C_MASTER_RECIBIENDO_DATO,
        I2C_MASTER_ENVIANDO_NACK,
        I2C_MASTER_STOP
    } I2C_MASTER_STATUS;

    typedef enum {
        I2C_SLAVE_IDLE,
        I2C_SLAVE_ENVIANDO_DATO,
        I2C_SLAVE_TO_TRANSMIT_DATA,
        I2C_SLAVE_ACK_RECEIVED,
        I2C_SLAVE_STOP
    } I2C_SLAVE_STATUS;

    void I2C_Master_Init(const unsigned long);
    void I2C_Master_Wait(void);
    void I2C_Slave_Init(short);

    void LMP91000_Write(uint8_t reg, uint8_t data);
    void LMP91000_Read(uint8_t reg);

    void returnToIdleState(void);

    void __interrupt() I2C_Master_ISR(void);
    void __interrupt() I2C_Slave_Read(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

