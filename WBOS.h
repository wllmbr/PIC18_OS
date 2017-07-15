/* 
 * File:   WBOS.h
 * Author: wllmb
 *
 * Created on July 14, 2017, 9:11 PM
 */

#include <xc.h>
#include "SN74HC164.h"

#ifndef WBOS_H
#define	WBOS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef struct pinDef{
    unsigned char *regID;
    unsigned char regMask;
    int pinState;
    int directionState;
} pinDef;

//Directional Macros
#define PIN_OUT 1
#define PIN_IN 0

// Mapping Pins to R Registers
//unsigned char regNumber[41] = {
//0,3,0,1,2,3,4,5,0,1,
//2,0,0,7,6,0,1,2,3,0,
//1,2,3,4,5,6,7,4,5,6,
//7,0,0,0,1,2,3,4,5,6,7
//};
//
//unsigned char *trisID[41] = {
//0,&TRISE,&TRISA,&TRISA,&TRISA,&TRISA,&TRISA,&TRISA,&TRISE,&TRISE,
//&TRISE,0,0,&TRISA,&TRISA,&TRISC,&TRISC,&TRISC,&TRISC,&TRISD,
//&TRISD,&TRISD,&TRISD,&TRISC,&TRISC,&TRISC,&TRISC,&TRISD,&TRISD,&TRISD,
//&TRISD,0,0,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB,&TRISB
//};
//
//unsigned char *portID[41] = {
//0,&PORTE,&PORTA,&PORTA,&PORTA,&PORTA,&PORTA,&PORTA,&PORTE,&PORTE,
//&PORTE,0,0,&PORTA,&PORTA,&PORTC,&PORTC,&PORTC,&PORTC,&PORTD,
//&PORTD,&PORTD,&PORTD,&PORTC,&PORTC,&PORTC,&PORTC,&PORTD,&PORTD,&PORTD,
//&PORTD,0,0,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB
//};
//
//unsigned char *latID[41] = {
//0,&LATE,&LATA,&LATA,&LATA,&LATA,&LATA,&LATA,&LATE,&LATE,
//&LATE,0,0,&LATA,&LATA,&LATC,&LATC,&LATC,&LATC,&LATD,
//&LATD,&LATD,&LATD,&LATC,&LATC,&LATC,&LATC,&LATD,&LATD,&LATD,
//&LATD,0,0,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB,&LATB
//};

void startPin(pinDef *newPin, char pinNum, int pinDir);
void driveHigh(pinDef * pin);
void driveLow(pinDef * pin);
void toggle(pinDef *pin);
int readPin(pinDef * pin);

    
#ifdef	__cplusplus
}
#endif

#endif	/* WBOS_H */

