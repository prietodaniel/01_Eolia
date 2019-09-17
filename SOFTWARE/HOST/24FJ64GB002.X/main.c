/**
  Section: Included Files
 */
#include "main.h"

#define VERSION_MASTER "2.0"

const int slavesAddress[] = {SENSOR_1, SENSOR_2, SENSOR_3, SENSOR_4, SENSOR_5};
int slavesAddressIndex = 0;

int main(void) {
    SYSTEM_Initialize();
    __delay_ms(1000);
    init();
    while (1) {
        if (slavesAddressIndex == 4) {
            slavesAddressIndex = 0;
        }
        i2c_masterStart(slavesAddress[slavesAddressIndex]);
        char * frame = i2c_waitToRecibeDataFromSlave();
        Measurement measurement = sim808_readGPS();
        if (protocol_verifyChecksum(frame)) {
            status_indicator_onSlaveTxFinished(slavesAddressIndex);
            measurement = protocol_parseSlaveFrame(measurement, frame);
            sim808_httpGET(measurement);
            sd_card_write(measurement);
        }
        slavesAddressIndex++;
        __delay_ms(1000);
    }
    return 1;
}

void init() {
    if (!sim808_init()) {
        status_indicator_onInitializeFail(SIM_808_GSM);
    }
    if (!sim808_waitGPSReady()) {
        status_indicator_onInitializeFail(SIM_808_GPS_FIX);
    }
    status_indicator_onInitSuccessful();
}
/**
 End of File
 */