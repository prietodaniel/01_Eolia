/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
 */
#include <xc.h>

#define HIGH    1
#define LOW     0
#define INPUT   1
#define OUTPUT  0
#define ANALOG      1
#define DIGITAL     0
#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

#define SLAVE_STATUS_SetHigh()    do { LATBbits.LATB0 = HIGH; } while(0)
#define SLAVE_STATUS_SetLow()   do { LATBbits.LATB0 = LOW; } while(0)
#define SLAVE_STATUS_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SLAVE_STATUS_SetDigitalInput()    do { TRISBbits.TRISB0 = INPUT; } while(0)
#define SLAVE_STATUS_SetDigitalOutput()   do { TRISBbits.TRISB0 = OUTPUT; } while(0)

#define GENERAL_STATUS_SetHigh()    do { LATBbits.LATB1 = HIGH; } while(0)
#define GENERAL_STATUS_SetLow()   do { LATBbits.LATB1 = LOW; } while(0)
#define GENERAL_STATUS_Toggle()   do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define GENERAL_STATUS_SetDigitalInput()    do {  TRISBbits.TRISB1 = INPUT; } while(0)
#define GENERAL_STATUS_SetDigitalOutput()   do {  TRISBbits.TRISB1  = OUTPUT; } while(0)

#define SD_CS_TRIS               TRISC0
#define SD_CS_LAT                LATC0
#define SD_CS_PORT               PORTCbits.RC0

#define SD_CS_SetHigh()          _LATB11 = 1
#define SD_CS_SetLow()           _LATB11 = 0
#define SD_CS_Toggle()           _LATB11 ^= 1
#define SD_CS_GetValue()         _RB11
#define SD_CS_SetDigitalInput()  _TRISB11 = 1
#define SD_CS_SetDigitalOutput() _TRISB11 = 0


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
