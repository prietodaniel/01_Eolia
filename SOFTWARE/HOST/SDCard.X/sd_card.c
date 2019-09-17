/*
 * File:   sd_card.c
 * Author: quitu
 *
 * Created on February 28, 2019, 9:20 PM
 */


#include "sd_card.h"

FATFS FatFs; /* FatFs work area needed for each volume */
FIL Fil; /* File object needed for each open file */
UINT bw;

char aux[160] = {};

void sd_card_write(Measurement measurement) {
    protocol_clearArray(aux, 160);
    char separator[] = {0x2c, '\0'};
    strcat(aux, measurement.sensor);
    strcat(aux, separator);
    strcat(aux, measurement.valor);
    strcat(aux, separator);
    strcat(aux, measurement.latitud);
    strcat(aux, separator);
    strcat(aux, measurement.longitud);
    strcat(aux, separator);
    strcat(aux, measurement.fecha);
    strcat(aux, "\n");
    if (f_mount(&FatFs, "", 1) == FR_OK) { /* Mount SD */

        if (f_open(&Fil, "Eolia.csv", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) { /* Open or create a file */

            if ((Fil.fsize != 0) && (f_lseek(&Fil, Fil.fsize) != FR_OK)) goto endSD; /* Jump to the end of the file */

            f_write(&Fil, aux, strlen(aux), &bw); /* Write data to the file */

endSD:
            f_close(&Fil); /* Close the file */
            status_indicator_onSDCardWriteFinished();
        }

    }
}
