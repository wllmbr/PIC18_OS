
#include "SN74HC164.h"

void init(SN74HC164 *object,
        unsigned char *clockPort,
        unsigned char clockMask,
        unsigned char *dataPort,
        unsigned char dataMask)
{
    object->clkPort = clockPort;
    object->clkMask = clockMask;
    object->dPort = dataPort;
    object->dMask = dataMask;
    
    //Setup
    object->data = 0xaa;
    //Drive clock high
    //Mask setting 
    object->clkPort[0] |= object->clkMask;
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
        unsigned char toSend;
        toSend= 0x00;
        if((0x80 >> cycle) & object->data){
            toSend = 0xff;
        }else{
            toSend = 0x00;
        }
        object->dPort[0] |= (object->dMask & toSend);
        asm("nop");
        //Set clock low
        object->clkPort[0] |= (object->clkMask & 0xff);
        asm("nop");
        //set clock high
        object->clkPort[0] &= ~(object->clkMask & 0xff);
    }
}

void clear(SN74HC164  *object){
    object->data = 0x00;
    //resend(object);

}