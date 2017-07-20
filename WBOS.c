/* 
 * File:   WBOS.h
 * Author: wllmb
 *
 * Created on July 14, 2017, 9:11 PM
 */

#include <xc.h>
#include "SN74HC164.h"
#include "WBOS.h"

//Directional Macros

#define PIN_OUT 0
#define PIN_IN 1

void startPin (pinDef *newPin, char pinNum, int pinDir){
    
    //Build pinMask
    int shiftLevel = regNumber[pinNum];
    unsigned char rm = (unsigned)(0x1 << shiftLevel);
    newPin->regMask = rm;
    
    //Set the TRIS Direction
    if(pinDir){
        //If pinDir = 1 = PIN_IN
        //Set TRISx.bit = 1
        trisID[pinNum][0] |= newPin->regMask;
        newPin->regID = portID[pinNum];
    }else{
        //If pinDIr = 0 = PIN_OUT
        //Set TRISx.bit = 0
        trisID[pinNum][0] &= (unsigned)~(newPin->regMask);
        newPin->regID = latID[pinNum];
    }
   
    newPin->directionState = pinDir;
    newPin->pinState = 0;
    //Set pin low by default
    driveLow(newPin);
    return;
}

void driveHigh(pinDef * pin)
{
    unsigned char toMask =pin->regMask;
    pin->regID[0] |= toMask;
}

void driveLow(pinDef * pin){
    unsigned char toMask = (unsigned)~(pin->regMask);
    pin->regID[0] &= toMask;
}

void toggle(pinDef * pin){
    unsigned char toAssign = (unsigned)(pin->regID[0] ^ pin->regMask);
    pin->regID[0] = toAssign;
}

int readPin(pinDef *pin){
    if(pin->regID[0] | pin->regMask){
        return 1;
    }
    return 0;
}




