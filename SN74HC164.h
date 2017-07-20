/* 
 * File:   74HC164.h
 * Author: wllmb
 *
 * Created on July 9, 2017, 5:08 PM
 */

#ifndef SN74HC164_H
#define	SN74HC164_H

#include "WBOS.h"

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct SN74HC164{
    pinDef *clockPin;
    pinDef *dataPin;
    pinDef *clearPin;
    unsigned char data;
} SN74HC164;

void init(SN74HC164 *object,pinDef *cp,pinDef *dp, pinDef *cl);
void loadNew(SN74HC164  *object, unsigned char newData);
void resend(SN74HC164  *object);
void clear(SN74HC164  *object);

#ifdef	__cplusplus
}
#endif

#endif	/* 74HC164_H */

