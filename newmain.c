/*
 * File:   newmain.c
 * Author: wllmb
 *
 * Created on July 8, 2017, 11:15 AM
 */
#include <xc.h>
#include "SN74HC164.h"
#include "WBOS.h"
// BEGIN CONFIG
#pragma config WDTE = 0 //Disable Watchdog
//END CONFIG

void main(void) {
  struct pinDef ledPin;
  startPin(&ledPin,21,PIN_OUT);
  unsigned int c;
  unsigned int overFlow = 65535;
  while(1)
  {
    toggle(&ledPin);
    for(c = 0; c < overFlow; c++){asm("nop");}
  }
  return;
}

