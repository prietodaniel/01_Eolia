/* 
 * File:   status_indicator.h
 * Author: quitu
 *
 * Created on February 28, 2019, 10:05 PM
 */

#ifndef STATUS_INDICATOR_H
#define	STATUS_INDICATOR_H

#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/pin_manager.h"
#include <libpic30.h>

void status_indicator_onSDCardWriteFinished();
void status_indicator_onInitSuccessful();
void status_indicator_onSlaveTxFinished(int);
void status_indicator_FonInitializeFail(int);

#endif	/* STATUS_INDICATOR_H */

