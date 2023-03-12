/*
 * PB_prog.c
 *
 *  Created on: ٠٢‏/٠٢‏/٢٠٢٣
 *      Author: muhsen
 */
#include"STD_TYPES.h"
#include "DIO_int.h"
#include "PB_priv.h"
#include"PB_config.h"
#include"PB_int.h"
#include<util/delay.h>


void H_PB_void_init(const PB_t *ptr)
{
	M_DIO_void_setPinDir(ptr->PB_port, ptr->PB_pin,IN);
}
void H_PB_void_read(const PB_t *ptr,u8 *pvalue)
{
	//u8 read;

	if(ptr -> PB_activeMood == ACTIVE_LOW)
	{
		*pvalue=NOT_PRESSED_ACTIVE_LOW ;
		M_DIO_void_getPinValue(ptr->PB_port, ptr->PB_pin, pvalue);
		if(*pvalue==PRESSED_ACTIVE_LOW)
		{
			*pvalue=PRESSED_ACTIVE_LOW;
			return;
		}
	}
	else if(ptr->PB_activeMood==ACTIVE_HIGH)
	{
		//u8 read;

		if(ptr->PB_activeMood==ACTIVE_HIGH)
		{
			*pvalue=NOT_PRESSED_ACTIVEHIGH ;
			M_DIO_void_getPinValue(ptr->PB_port, ptr->PB_pin, &pvalue);
			if(*pvalue==PRESSED_ACTIVE_HIGH){
				_delay_ms(200);

				M_DIO_void_getPinValue(ptr->PB_port, ptr->PB_pin, &pvalue);
				if (*pvalue==PRESSED_ACTIVE_HIGH)
				{
					while(*pvalue==PRESSED_ACTIVE_HIGH)
					{
						M_DIO_void_getPinValue(ptr->PB_port, ptr->PB_pin, &pvalue);
					}
					*pvalue=PRESSED_ACTIVE_HIGH;
					return;
				}

			}
		}
	}
}


