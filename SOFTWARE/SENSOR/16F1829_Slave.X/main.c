/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1829
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

char VERSION_SLAVE[] = "1.0";

I2C_SLAVE_STATUS slave_estado_previo;
I2C_MASTER_STATUS master_estado_previo;
const short SLAVE_ADDRESS = 0x30;
uint16_t convertedValue[100];

int LMP_Read;
uint8_t data_received;
uint8_t data_read_ready;
uint8_t LMP91000_ready = 0;


void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    //INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();
    
    MENB_SetLow();

    //DAC_Initialize();
    //LATCbits.LATC6 = 0;

    do {
        LMP91000_Read(0x00);
        while (!data_read_ready);
        LMP91000_ready = data_received;
    } while (LMP91000_ready == 0);

    LMP91000_Write(0x01, 0); //registro, dato. Aca le saco el LOCK.
    __delay_ms(10);
    LMP91000_Write(0x10, 0b10111); //4:2 = Ganangcia; 1:0 = Rload
    __delay_ms(10);
    LMP91000_Read(0x10);
    __delay_ms(10);
    LMP91000_Write(0x11, 0b00100100); //REF EXTERNA, 20%, NEGATIVE, BIAS 0.
    __delay_ms(10);
    LMP91000_Read(0x11);
    __delay_ms(10);
    LMP91000_Write(0x12, 0b111); //00000011
    __delay_ms(10);
    
    __delay_ms(1000);
    slave_estado_previo = I2C_SLAVE_IDLE;
    I2C_Slave_Init(SLAVE_ADDRESS);
    int i = 0;
    while (1) {
        while (i < 100) {
            ADC_StartConversion();
            while (ADC_IsConversionDone());
            convertedValue[i] = ADC_GetConversionResult();
            i++;
            __delay_ms(10);
        }
        i = 0;
    }
}
