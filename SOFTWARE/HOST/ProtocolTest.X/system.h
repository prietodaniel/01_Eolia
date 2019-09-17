/* 
 * File:   system.h
 * Author: quitusl
 *
 * Created on April 29, 2017, 12:12 PM
 */
#ifndef systemH
#define systemH

#include <xc.h> 

#define TRUE 1
#define FALSE 1

#define OSC_1_MHZ 0b100
#define OSC_4_MHZ 0b110
#define OSC_250_KHZ 0b010

void system_configureOscillator(void);

#endif




