/*
 * CLCD_interface.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Kishk
 */

#ifndef HAL_04__CLCD_CLCD_INTERFACE_H_
#define HAL_04__CLCD_CLCD_INTERFACE_H_


#define CLCD_ROW_1		1
#define CLCD_ROW_2		2

#define CLCD_COL_1		1
#define CLCD_COL_2		2
#define CLCD_COL_3		3
#define CLCD_COL_4		4
#define CLCD_COL_5		5
#define CLCD_COL_6		6
#define CLCD_COL_7		7
#define CLCD_COL_8		8
#define CLCD_COL_9		9
#define CLCD_COL_10		10
#define CLCD_COL_11		11
#define CLCD_COL_12		12
#define CLCD_COL_13		13
#define CLCD_COL_14		14
#define CLCD_COL_15		15
#define CLCD_COL_16		16


#define CLCD_8BIT_PIN 		0
#define CLCD_4BIT_PIN 		1

#define CLCD_LEFT_RIGHT 	0
#define CLCD_RIGHT_LEFT 	1

#define CLCD_SHIFT_DISABLE	0
#define CLCD_SHIFT_LEFT 	1
#define CLCD_SHIFT_RIGHT 	2

#define CLCD_CURSOR_ON	1
#define CLCD_CURSOR_OFF	0






void CLCD_voidInit(void);


void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommend(u8 Copy_u8Commend);

void CLCD_voidSendString (u8 * Copy_u8ptrString );
void CLCD_voidSendNumber (u64 Copy_u64Number );

void CLCD_voidSetPosition(u8 Copy_u8Row ,u8 Copy_u8Coloum);

void CLCD_voidClearDisplay(void);

void CLCD_voidSendExtraChar(void);

void CLCD_voidMoveDirection(u8 Copy_u8Direction);
#endif /* HAL_04__CLCD_CLCD_INTERFACE_H_ */
