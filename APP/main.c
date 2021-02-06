/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/04- CLCD/CLCD_interface.h"

int main(void) {
	CLCD_voidInit();
	CLCD_voidSendExtraChar();
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
	for(s8 s8Iterator = 3 ; s8Iterator >= 0  ; --s8Iterator){
		CLCD_voidSendData(s8Iterator);
	}

}
