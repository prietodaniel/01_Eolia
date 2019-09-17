/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
#include <xc.h>
#elif defined(__C30__)
#if defined(__PIC24E__)
#include <p24Exxxx.h>
#elif defined (__PIC24F__)||defined (__PIC24FK__)
#include <p24Fxxxx.h>
#elif defined(__PIC24H__)
#include <p24Hxxxx.h>
#endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

//#include "system.h"        /* System funct/params, like osc/peripheral config */
//#include "user.h"          /* User funct/params, such as InitApp              */
#include "ff.h"
#include "mcc_generated_files/mcc.h"
#include "string.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

FATFS FatFs; /* FatFs work area needed for each volume */
FIL Fil; /* File object needed for each open file */

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

int16_t main(void) {

    SYSTEM_Initialize();

    UINT bw;
    char medicion1[] = "medicion nueva\r\n";
    char medicion2[] = "2222.222 ppm\r\n";
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (f_mount(&FatFs, "", 1) == FR_OK) { /* Mount SD */

            if (f_open(&Fil, "eolia.csv", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) { /* Open or create a file */

                if ((Fil.fsize != 0) && (f_lseek(&Fil, Fil.fsize) != FR_OK)) goto endSD; /* Jump to the end of the file */

                f_write(&Fil, medicion1, strlen(medicion1), &bw); /* Write data to the file */
                f_write(&Fil, medicion2, strlen(medicion2), &bw); /* Write data to the file */
endSD:
                f_close(&Fil); /* Close the file */
                TRISBbits.TRISB0 = 0;
                LATBbits.LATB0 = ~LATBbits.LATB0; //Enciendo el LED.
            }

        }
    }


    while (1) {

    }
}
