/**
  UART1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart1.c

  @Summary
    This is the generated driver implementation file for the UART1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for UART1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB             :  MPLAB X v5.10
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

/**
  Section: Included Files
 */
#include "uart1.h"

/**
  Section: UART1 APIs
 */

void UART1_Initialize(void) {
    /**    
         Set the UART1 module to the options selected in the user interface.
         Make sure to set LAT bit corresponding to TxPin as high before UART initialization
     */
    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; RXINV disabled; UEN TX_RX; 
    // Data Bits = 8; Parity = None; Stop Bits = 1;
    U1MODE = (0x8008 & ~(1 << 15)); // disabling UARTEN bit
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U1STA = 0x00;
    // BaudRate = 9600; Frequency = 4000000 Hz; BRG 103; 
    U1BRG = 0x67;

    UART1_Enable(); // enabling UARTEN bit
}

uint8_t UART1_Read(void) {
    while (!(U1STAbits.URXDA == 1)) {
    }
    if ((U1STAbits.OERR == 1)) {
        U1STAbits.OERR = 0;
    }
    return U1RXREG;
}

void UART1_Write(uint8_t txData) {
    while (U1STAbits.UTXBF == 1) {
    }
    U1TXREG = txData; // Write the data byte to the USART.
}

unsigned int UART1_ReadBuffer(char *buffer, int crCount) {
    unsigned int countCarryReturn = 0;
    unsigned int numBytesRead = 0;
    while (countCarryReturn < crCount) {
        buffer[numBytesRead] = UART1_Read();
        if (buffer[numBytesRead] == '\r') {
            countCarryReturn++;
        }
        numBytesRead++;
    }
    return numBytesRead;
}

unsigned int UART1_WriteBuffer(const char *buffer) {
    unsigned int numBytesWritten = 0;
    do {
        UART1_Write(buffer[numBytesWritten++]);
    } while (buffer[numBytesWritten] != '\0');
    return numBytesWritten;
}

uint16_t UART1_StatusGet(void) {
    return U1STA;
}

void UART1_Enable(void) {
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}

void UART1_Disable(void) {
    U1MODEbits.UARTEN = 0;
    U1STAbits.UTXEN = 0;
}

