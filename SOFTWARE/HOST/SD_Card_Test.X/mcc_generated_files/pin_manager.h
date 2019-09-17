/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.45
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.32
        MPLAB             :  MPLAB X 3.61

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
/**
    Section: Device Pin Macros
*/

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

/*
  @Example
    <code>
    // Set RB11 high (1)
    SS1OUT_SetHigh();
    </code>
*/

#define SD_CS_TRIS               TRISC0
#define SD_CS_LAT                LATC0
#define SD_CS_PORT               PORTCbits.RC0

#define SD_CS_SetHigh()          _LATB11 = 1
#define SD_CS_SetLow()           _LATB11 = 0
#define SD_CS_Toggle()           _LATB11 ^= 1
#define SD_CS_GetValue()         _RB11
#define SD_CS_SetDigitalInput()  _TRISB11 = 1
#define SD_CS_SetDigitalOutput() _TRISB11 = 0

/*
  @Example
    <code>
    // Set RB13 high (1)
    SDO1_SetHigh();
    </code>

*/
#define SDO1_SetHigh()          _LATB13 = 1
/*
  @Example
    <code>
    // Set RB13 low (0)
    SDO1_SetLow();
    </code>

*/
#define SDO1_SetLow()           _LATB13 = 0
/*
  @Example
    <code>
    // Toggle RB13
    SDO1_Toggle();
    </code>

*/
#define SDO1_Toggle()           _LATB13 ^= 1
/*
  @Example
    <code>
    uint16_t portValue;

    // Read RB13
    postValue = SDO1_GetValue();
    </code>

*/
#define SDO1_GetValue()         _RB13
/*
  @Example
    <code>
    // Sets the RB13 as an input
    SDO1_SetDigitalInput();
    </code>

*/
#define SDO1_SetDigitalInput()  _TRISB13 = 1
/*
  @Example
    <code>
    // Sets the RB13 as an output
    SDO1_SetDigitalOutput();
    </code>

*/
#define SDO1_SetDigitalOutput() _TRISB13 = 0
/*
  @Example
    <code>
    // Set RB14 high (1)
    SDI1_SetHigh();
    </code>

*/
#define SDI1_SetHigh()          _LATB14 = 1
/*
  @Example
    <code>
    // Set RB14 low (0)
    SDI1_SetLow();
    </code>

*/
#define SDI1_SetLow()           _LATB14 = 0
/*
  @Example
    <code>
    // Toggle RB14
    SDI1_Toggle();
    </code>

*/
#define SDI1_Toggle()           _LATB14 ^= 1
/*
  @Example
    <code>
    uint16_t portValue;

    // Read RB14
    postValue = SDI1_GetValue();
    </code>

*/
#define SDI1_GetValue()         _RB14
/*

  @Example
    <code>
    // Sets the RB14 as an input
    SDI1_SetDigitalInput();
    </code>

*/
#define SDI1_SetDigitalInput()  _TRISB14 = 1
/*
  @Example
    <code>
    // Sets the RB14 as an output
    SDI1_SetDigitalOutput();
    </code>

*/
#define SDI1_SetDigitalOutput() _TRISB14 = 0
/*
  @Example
    <code>
    // Set RB15 high (1)
    SCK1OUT_SetHigh();
    </code>

*/
#define SCK1OUT_SetHigh()          _LATB15 = 1
/*
  @Example
    <code>
    // Set RB15 low (0)
    SCK1OUT_SetLow();
    </code>

*/
#define SCK1OUT_SetLow()           _LATB15 = 0
/*
  @Example
    <code>
    // Toggle RB15
    SCK1OUT_Toggle();
    </code>

*/
#define SCK1OUT_Toggle()           _LATB15 ^= 1
/*
    // Read RB15
    postValue = SCK1OUT_GetValue();
    </code>

*/
#define SCK1OUT_GetValue()         _RB15
/*
  @Example
    <code>
    // Sets the RB15 as an input
    SCK1OUT_SetDigitalInput();
    </code>

*/
#define SCK1OUT_SetDigitalInput()  _TRISB15 = 1
/*
  @Example
    <code>
    // Sets the RB15 as an output
    SCK1OUT_SetDigitalOutput();
    </code>

*/
#define SCK1OUT_SetDigitalOutput() _TRISB15 = 0

/*
  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize(void);

#endif
