/*
 * File:   status_indicator.c
 * Author: quitu
 *
 * Created on February 28, 2019, 10:05 PM
 */

#include "status_indicator.h"

void status_indicator_onInitSuccessful() {
    GENERAL_STATUS_SetHigh();
}

void status_indicator_onSlaveTxFinished(int slavesAddressIndex) {
    int i;
    for (i = 0; i < slavesAddressIndex + 1; i++) {
        SLAVE_STATUS_SetHigh();
        __delay_ms(250);
        SLAVE_STATUS_SetLow();
        __delay_ms(250);
    }
}

void status_indicator_onInitializeFail(int intStepFail) {
    GENERAL_STATUS_SetHigh();
    int i;
    for (i = 0; i < intStepFail + 1; i++) {
        GENERAL_STATUS_SetHigh();
        __delay_ms(250);
        GENERAL_STATUS_SetLow();
        __delay_ms(250);
    }
    __delay_ms(3000);
    status_indicator_onInitializeFail(intStepFail);
}

void status_indicator_onSDCardWriteFinished() {
    int i;
    for (i = 0; i < 10 + 1; i++) {
        SLAVE_STATUS_SetHigh();
        __delay_ms(100);
        SLAVE_STATUS_SetLow();
        __delay_ms(100);
    }
}
