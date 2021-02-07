/*
 * CLCD_program.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Kishk
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"
#include "../../MCAL/01-DIO/DIO_interface.h"

#include <util/delay.h>

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

void CLCD_voidInit(void) {

	DIO_enumSetPortDirection(CLCD_DATA_PORT, DIO_DIRECTION_OUTPUT);
	DIO_enumSetPinDirection(CLCD_RS, DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_RW, DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_EN, DIO_OUTPUT);

#if CLCD_PIN_INITIALIZATION == CLCD_8BIT_PIN
//	Function Set
	_delay_ms(50);
	CLCD_voidSendCommend(CLCD_8PIN_FUNCTION_SET);
//	Display ON/OFF Control
	_delay_ms(1);
//	TURN OFF CURSOR
#if CLCD_DISPLAY_CURSOR == CLCD_CURSOR_OFF
	CLCD_voidSendCommend(0b00001100);
//TRUN ON CURSOR
#elif CLCD_DISPLAY_CURSOR == CLCD_CURSOR_ON
	CLCD_voidSendCommend(0b00001110);
#endif


//	Display Clear
	_delay_ms(1);
	CLCD_voidSendCommend(0b00000001);
	_delay_ms(2);
//	Entry Mode Set

	//	CURSUR AUTO INCREMENT (MOVE FROM LEFT TO RIGHT)
#if (CLCD_MOVE_DIRECTION ==  CLCD_LEFT_RIGHT && CLCD_AUTO_SHIFT == CLCD_SHIFT_DISABLE)
	CLCD_voidSendCommend(0b00000110);
	_delay_ms(1);
#endif

	//	CURSUR AUTO DECREMENT (MOVE FROM RIGHT TO LEFT)
#if (CLCD_MOVE_DIRECTION ==  CLCD_RIGHT_LEFT && CLCD_AUTO_SHIFT == CLCD_SHIFT_DISABLE)
	CLCD_voidSendCommend(0b00000100);
	_delay_ms(1);
#endif

#if (CLCD_AUTO_SHIFT == CLCD_SHIFT_LEFT)
	CLCD_voidSendCommend(0b00000111);
	_delay_ms(1);
#endif

#if (CLCD_AUTO_SHIFT == CLCD_SHIFT_RIGHT)
	CLCD_voidSendCommend(0b00000101);
	_delay_ms(1);
#endif

#endif

#if CLCD_PIN_INITIALIZATION == CLCD_4BIT_PIN
//	Function Set
	_delay_ms(50);
	CLCD_voidSendCommend(0b00100000);
	CLCD_voidSendCommend(0b00100000);
	CLCD_voidSendCommend(0b11000000);

//	Display ON/OFF Control
	_delay_ms(1);
	CLCD_voidSendCommend(0b00000000);

#if CLCD_DISPLAY_CURSOR == CLCD_CURSOR_OFF
	CLCD_voidSendCommend(0b11000000);
#elif CLCD_DISPLAY_CURSOR == CLCD_CURSOR_ON
	CLCD_voidSendCommend(0b11100000);
#endif
	//	Display Clear
	_delay_ms(1);
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b00010000);
	_delay_ms(2);
//	Entry Mode Set

	//	CURSUR AUTO INCREMENT (MOVE FROM LEFT TO RIGHT)
#if (CLCD_MOVE_DIRECTION ==  CLCD_LEFT_RIGHT && CLCD_AUTO_SHIFT == CLCD_SHIFT_DISABLE)
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b01100000);
#endif

#if (CLCD_AUTO_SHIFT == CLCD_SHIFT_LEFT)
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b01110000);
#endif

#if (CLCD_AUTO_SHIFT == CLCD_SHIFT_RIGHT)
	CLCD_voidSendCommend(0b00000000);
	CLCD_voidSendCommend(0b01010000);
#endif

	_delay_ms(1);


#endif

}

void CLCD_voidSendData(u8 Copy_u8Data) {
	DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	DIO_enumSetPinValue(CLCD_RS, DIO_HIGH);
	DIO_enumSetPinValue(CLCD_RW, DIO_LOW);
//	Applying falling edge to EN Pin
	DIO_enumSetPinValue(CLCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_EN, DIO_LOW);
	_delay_ms(1);

}

void CLCD_voidSendCommend(u8 Copy_u8Commend) {
	DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Commend);
	DIO_enumSetPinValue(CLCD_RS, DIO_LOW);
	DIO_enumSetPinValue(CLCD_RW, DIO_LOW);
//	Applying falling edge to EN Pin
	DIO_enumSetPinValue(CLCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_EN, DIO_LOW);
	_delay_ms(1);

}

void CLCD_voidSendString(u8 * Copy_u8ptrString) {

	u8 LOC_u8Iterator = 0;

	while (Copy_u8ptrString[LOC_u8Iterator] != '\0') {
		CLCD_voidSendData(Copy_u8ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}

void CLCD_voidSendNumber(u64 Copy_u64Number) {
	u64 LOC_u16Reversed = 1;
	if (Copy_u64Number == 0) {
		CLCD_voidSendData('0');
	} else {
		while (Copy_u64Number != 0) {
			LOC_u16Reversed = (LOC_u16Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}
		while (LOC_u16Reversed != 1) {
			CLCD_voidSendData(LOC_u16Reversed % 10 + '0');
			LOC_u16Reversed /= 10;
		}
	}
}

void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Coloum) {
	if (Copy_u8Row == CLCD_ROW_1) {
		CLCD_voidSendCommend((CLCD_ROW_1_ADDRESS) + Copy_u8Coloum - 1);
	} else if (Copy_u8Row == CLCD_ROW_2) {
		CLCD_voidSendCommend((CLCD_ROW_2_ADDRESS) + Copy_u8Coloum - 1);

	}

}

void CLCD_voidSendExtraChar(void) {
	CLCD_voidSendCommend(0x40);
	u8 LOC_u8Iterator = 0;
	for (LOC_u8Iterator = 0;
			LOC_u8Iterator
					< (sizeof(CLCD_u8SpicialCharacter)
							/ sizeof(CLCD_u8SpicialCharacter[LOC_u8Iterator]));
			LOC_u8Iterator++) {
		CLCD_voidSendData(CLCD_u8SpicialCharacter[LOC_u8Iterator]);
	}
}

void CLCD_voidClearDisplay(void) {
	CLCD_voidSendCommend(0b00000001);
	_delay_ms(2);
}


void CLCD_voidMoveDirection(u8 Copy_u8Direction){
	if(Copy_u8Direction == CLCD_LEFT_RIGHT){
		CLCD_voidSendCommend(0b00000110);
	}
	else if((Copy_u8Direction == CLCD_RIGHT_LEFT)){
		CLCD_voidSendCommend(0b00000100);
	}
	_delay_ms(1);
}
