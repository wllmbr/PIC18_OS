
#include "SN74HC164.h"
#define _XTAL_FREQ 16000000

void init(SN74HC164 *object,pinDef *cp,pinDef *dp, pinDef *cl)
{
    object->dataPin = dp;
    object->clockPin = cp;
    object->clearPin = cl;
    
    //Setup
    object->data = 0xaa;
    //Drive clock high
    driveHigh(object->clockPin);
    driveHigh(object->clearPin);
    //Clear chip device
    clear(object);
    
}
          
void loadNew(SN74HC164 * object, unsigned char newData)
{
    object->data = newData;
    resend(object);
}
void resend(SN74HC164  *object)
{
    int cycle;
    for(cycle=0; cycle < 8; cycle++){
        //Set data line
        if((0x80 >> cycle) & object->data){
            //Set High
            driveHigh(object->dataPin);
        }else{
            //Set Low
            driveLow(object->dataPin);
        }
        //__delay_ms(333);
        //Set clock low
        driveLow(object->clockPin);
        //__delay_ms(333);
        //set clock high
        driveHigh(object->clockPin);
        //__delay_ms(333);
    }
}

void clear(SN74HC164  *object){
    object->data = 0x00;
    //resend(object);
    //__delay_ms(400);
    driveLow(object->clearPin);
    //__delay_ms(100);
    driveHigh(object->clearPin);
    

}