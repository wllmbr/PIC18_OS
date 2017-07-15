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

#define PIN_OUT 1
#define PIN_IN 0

unsigned char regNumber[41] = {
0,3,0,1,2,3,4,5,0,1,
2,0,0,7,6,0,1,2,3,0,
1,2,3,4,5,6,7,4,5,6,
7,0,0,0,1,2,3,4,5,6,7
};

unsigned char *trisID[41] = {
0,&TRISE,&TRISA,&TRISA,&TRISA,&TRISA,&TRISA,&TRISA,&TRISE,&TRISE,
&TRISE,0,0,&TRISA,&TRISA,&TRISC,&TRISC,&TRISC,&TRISC,&TRISD,
&TRISD,&TRISD,&TRISD,&TRISC,&TRISC,&TRISC,&TRISC,&TRISD,&TRISD,&TRISD,
&TRISD,0,0,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB
};

unsigned char *portID[41] = {
0,&PORTE,&PORTA,&PORTA,&PORTA,&PORTA,&PORTA,&PORTA,&PORTE,&PORTE,
&PORTE,0,0,&PORTA,&PORTA,&PORTC,&PORTC,&PORTC,&PORTC,&PORTD,
&PORTD,&PORTD,&PORTD,&PORTC,&PORTC,&PORTC,&PORTC,&PORTD,&PORTD,&PORTD,
&PORTD,0,0,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB
};

unsigned char *latID[41] = {
0,&LATE,&LATA,&LATA,&LATA,&LATA,&LATA,&LATA,&LATE,&LATE,
&LATE,0,0,&LATA,&LATA,&LATC,&LATC,&LATC,&LATC,&LATD,
&LATD,&LATD,&LATD,&LATC,&LATC,&LATC,&LATC,&LATD,&LATD,&LATD,
&LATD,0,0,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB
};

void startPin (pinDef *newPin, char pinNum, int pinDir){
    //Build pinMask
    int shiftLevel = regNumber[pinNum];
    unsigned char rm = 0x1 << shiftLevel;
    newPin->regMask = rm;
    
    //Set the TRIS Direction
    if(pinDir){
        //If pinDir = 1 = PIN_OUT
        //Set TRISx.bit = 1
        trisID[pinNum][0] |= newPin->regMask;
    }else{
        //If pinDIr = 0 = PIN_IN
        //Set TRISx.bit = 0
        trisID[pinNum][0] &= ~(newPin->regMask);
    }
    
    //Setup the pin struct
    if(pinDir){
        //If PIN_OUT -> latx
        newPin->regID = latID[pinNum];
    }else{
        newPin->regID = portID[pinNum];
    }
    
    newPin->directionState = pinDir;
    newPin->pinState = 0;
    //Set pin low by default
    driveLow(newPin);
    return;
}

void driveHigh(pinDef * pin)
{
    pin->regID[0] |= pin->regMask;
}

void driveLow(pinDef * pin){
    unsigned char toMask = ~(pin->regMask);
    pin->regID[0] &= toMask;
}

void toggle(pinDef * pin){
    unsigned char toAssign = pin->regID[0] ^ pin->regMask;
    pin->regID[0] = toAssign;
}

int readPin(pinDef *pin){
    if(pin->regID[0] | pin->regMask){
        return 1;
    }
    return 0;
}




