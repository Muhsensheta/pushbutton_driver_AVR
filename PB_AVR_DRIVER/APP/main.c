/*
 * main.c
 *
 *  Created on: ٠٤‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#include<util/delay.h>
#include "STD_TYPES.h"

#include "DIO_int.h"
#include"LED_int.h"
#include"PB_int.h"


int main()
{
	u8 x;
	PB_t PB1 = {1,PORTD_ID,PIN7,ACTIVE_LOW};
//init push button
H_PB_void_init(&PB1);
H_Led_void_ledInit(RED_LED);
H_Led_void_setOFF(RED_LED);
while(1)
{
	H_PB_void_read(&PB1,&x);
    if(x==PRESSED_ACTIVE_LOW)
    {
    	H_Led_void_setON(RED_LED);
    }
    else if(x==NOT_PRESSED_ACTIVE_LOW)
    {
    	H_Led_void_setOFF(RED_LED);
    }
}

return 0;
}

