/*
 * File:   utils.c
 * Author: mleon
 *
 * Created on 10 de octubre de 2018, 16:51
 */


#include <xc.h>

void putch(char data) {
    while (!PIR1bits.TXIF) // wait until the transmitter is ready
        continue;
    TXREG = data; // send one character
}