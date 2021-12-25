/*
 * keypad.c
 *
 *  Created on: Dec 11, 2021
 *      Author: noura
 */
#include "GPIO.h"
#include "_7segment.h"
#include "keypad.h"
#include<time.h>

char port_row = 'A' ;
int first_row = 10;
int last_row = 7;

char port_col = 'A' ;
int first_col = 13;
int last_col = 15 ;

int col;
int row;
char pressed_key ;
int keypad_state ;

char keypad [4][3] = {  {1,2,3},
						{4,5,6},
						{7,8,9},
						{'*',0,'#'} } ;

void keypad_init (void)
{
	for ( row = first_row ; row >= last_row  ; row --)
	{
		GPIO_Init(port_row , row , INPUT , PULL_UP);
	}

	for ( col = first_col ; col <= last_col ; col ++)
	{
		GPIO_Init(port_col , col , OUTPUT , PUSH_PULL);
		GPIO_WritePin(port_col , col , HIGH);
	}
}


void keypad_manage (void)
{
	if (keypad_state == 0)
	{
	//outter output
	// inner input
	for ( col = first_col ; col <= last_col ; col ++ )
		{
		GPIO_WritePin(port_col , col , LOW);
		for ( row = first_row ; row >= last_row  ; row -- )
			{
				if ( GPIO_ReadPin( port_row , row) == 0 )
				{
					//delay(0.5);
					for (int i=0 ; i<500000 ; i++){}
					if ( GPIO_ReadPin( port_row , row) == 0 )
					{
						keypad_state = 1;
						pressed_key = keypad_GetKey ();
						KeypadCallouts_KeyPressNotificaton();
					}
				}
				GPIO_WritePin(port_col , col , HIGH);
			}
		}
	}

}


char keypad_GetKey (void)
{
	keypad_state = 0;
	return pressed_key;
}
