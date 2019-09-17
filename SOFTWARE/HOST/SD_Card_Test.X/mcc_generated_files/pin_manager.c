/**
    Section: Includes
 */
#include <xc.h>
#include <p24FJ64GB002.h>
#include "pin_manager.h"

/**
    void PIN_MANAGER_Initialize(void)
 */
void PIN_MANAGER_Initialize(void) {
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0xC6FF;
    TRISB = 0x0FBF;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPU1 = 0x0000;
    CNPU2 = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    AD1PCFG = 0x0203; //CS, PGC y PGD como digitales.

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPOR6bits.RP13R = 0x0008;   //RB13->SPI1:SCK1OUT;
    RPOR7bits.RP15R = 0x0009;   //RB15->SPI1:SS1OUT;
    RPOR7bits.RP14R = 0x0007;   //RB14->SPI1:SDO1;
    RPINR20bits.SDI1R = 0x000B;   //RB11->SPI1:SDI1;

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

}

