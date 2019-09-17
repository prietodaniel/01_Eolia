/*
 * File:   system.c
 * Author: quitusl
 * 
 * Voy a agregar en este archivo funciones de sistema. Por ejemplo, una función para
 * determinar el origen de un reset, la conmutación entre fuentes de reloj, el salto a un
 * modo de bajo consumo, etc, son el tipo de funciones consideradas como funciones a
 * nivel de sistema.
 * 
 * Created on April 29, 2017, 12:15 PM
 */

#include "system.h" 

void system_configureOscillator(void) {
    //selecciono oscilador interno
    OSCCONbits.SCS = TRUE;
    //lo configuro para 4 MHz   
    OSCCONbits.IRCF = OSC_4_MHZ;
}
