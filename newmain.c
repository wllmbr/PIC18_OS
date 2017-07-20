/*
 * File:   newmain.c
 * Author: wllmb
 *
 * Created on July 8, 2017, 11:15 AM
 */
#define _XTAL_FREQ 16000000

#include <xc.h>
#include "SN74HC164.h"
#include "WBOS.h"
// BEGIN CONFIG
#pragma config WDTE = 0 //Disable Watchdog
//END CONFIG

void main(void) {    
    struct pinDef ledPin, clockPin, dataPin, clearPin;
    startPin(&clockPin,20,PIN_OUT);
    startPin(&dataPin,19,PIN_OUT);
    startPin(&clearPin,22,PIN_OUT);
    struct SN74HC164 chipPin;
    init(&chipPin,&clockPin,&dataPin,&clearPin);
    startPin(&ledPin,21,PIN_OUT);
    unsigned char ovlsb = 0;
    unsigned char ovmsb = 0;
    SETUP_TIMER0
    while(1)
    {
        START_TIMER0
        clear(&chipPin);
        loadNew(&chipPin,ovmsb);
        ovmsb++;
        toggle(&ledPin);
        toggle(&ledPin);
        STOP_TIMER0
        asm("nop");
    }

}

