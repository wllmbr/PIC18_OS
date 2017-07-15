/* 
 * File:   74HC164.h
 * Author: wllmb
 *
 * Created on July 9, 2017, 5:08 PM
 */

#ifndef SN74HC164_H
#define	SN74HC164_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct SN74HC164{
    unsigned char *clkPort;
    unsigned char clkMask;
    unsigned char *dPort;
    unsigned char dMask;
    unsigned char data;
} SN74HC164;

void init(SN74HC164 *object,
        unsigned char *clockPort,
        unsigned char clockMask,
        unsigned char *dataPort,
        unsigned char dataMask);
void loadNew(SN74HC164  *object, unsigned char newData);
void resend(SN74HC164  *object);
void clear(SN74HC164  *object);

#ifdef	__cplusplus
}
#endif

#endif	/* 74HC164_H */

