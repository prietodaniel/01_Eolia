/**
  ADC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.c

  @Summary
    This is the generated driver implementation file for the ADC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1829
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
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

/**
  Section: Included Files
 */
#include "adc.h"

/**
  Section: Macro Declarations
 */

#define ACQ_US_DELAY 5

/**
  Section: ADC Module APIs
 */

extern uint16_t convertedValue[100];

void ADC_Initialize(void) {
    // set the ADC to the options selected in the User Interface

    // GO_nDONE stop; ADON enabled; CHS AN0; 
    ADCON0 = 0x01;

    // ADFM right; ADNREF VSS; ADPREF VDD; ADCS FOSC/2; 
    ADCON1 = 0x80;

    // ADRESL 0; 
    ADRESL = 0x00;

    // ADRESH 0; 
    ADRESH = 0x00;

}

void ADC_SelectChannel(adc_channel_t channel) {
    // select the A/D channel
    ADCON0bits.CHS = channel;
    // Turn on the ADC module
    ADCON0bits.ADON = 1;
}

void ADC_StartConversion() {
    // Start the conversion
    ADCON0bits.GO_nDONE = 1;
}

bool ADC_IsConversionDone() {
    // Start the conversion
    return ((bool) (!ADCON0bits.GO_nDONE));
}

adc_result_t ADC_GetConversionResult(void) {
    // Conversion finished, return the result
    return ((adc_result_t) ((ADRESH << 8) + ADRESL));
}

adc_result_t ADC_GetConversion(adc_channel_t channel) {
    // select the A/D channel
    ADCON0bits.CHS = channel;

    // Turn on the ADC module
    ADCON0bits.ADON = 1;

    // Acquisition time delay
    __delay_us(ACQ_US_DELAY);

    // Start the conversion
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.GO_nDONE) {
    }

    // Conversion finished, return the result
    return ((adc_result_t) ((ADRESH << 8) + ADRESL));
}

void ADC_TemperatureAcquisitionDelay(void) {
    __delay_us(200);
}

char * adcToMeasurementValue() {
    int acumulador = 0;
    for (int i = 0; i < 100; i++) {
        acumulador += convertedValue[i];
    }
    float promedio = (float) (acumulador / 100);
    float valor_en_V = 0;
    float valor_en_ppm = 0;
    float v_error = 0; //FIJO
    float v_ref = 3.0; //FIJO
    float SR = 14.43; //S*R Fijo CO

    valor_en_V = promedio * (v_ref / 1023.0); //Cuentas de AD * Tension de Referencia / 2 a la N.
    valor_en_ppm = (valor_en_V - v_error) * SR; //Ppm = valor en V - tension de error  / S*R... S = 6.93 nA / ppm. R = 10 ^ 7. 

    static char ppm_string[8] = {}; //Arreglo para el valor de la medición en string.
    sprintf(ppm_string, "%8.3f", valor_en_ppm);

    for (int i = 0; i < 8; i++) { //Función para rellenar ceros a la izquierda.
        if (ppm_string[i] == ' ') {
            ppm_string[i] = '0';
        }
    }
    return ppm_string;
}

/**
 End of File
 */