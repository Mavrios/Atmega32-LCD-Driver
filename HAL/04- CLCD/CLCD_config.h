/*
 * CLCD_config.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Kishk
 */

#ifndef HAL_04__CLCD_CLCD_CONFIG_H_
#define HAL_04__CLCD_CLCD_CONFIG_H_

/*
 * Options:-

 DIO_PORTA
 DIO_PORTB
 DIO_PORTC
 DIO_PORTD
 */

#define CLCD_DATA_PORT		DIO_PORTA

/*
 * Options:-
 //			PORTA
 DIO_PORTA_PIN0	0
 DIO_PORTA_PIN1
 DIO_PORTA_PIN2
 DIO_PORTA_PIN3
 DIO_PORTA_PIN4
 DIO_PORTA_PIN5
 DIO_PORTA_PIN6
 DIO_PORTA_PIN7

 //			PORTB
 DIO_PORTB_PIN0
 DIO_PORTB_PIN1
 DIO_PORTB_PIN2
 DIO_PORTB_PIN3
 DIO_PORTB_PIN4
 DIO_PORTB_PIN5
 DIO_PORTB_PIN6
 DIO_PORTB_PIN7
 //			PORTC

 DIO_PORTC_PIN0
 DIO_PORTC_PIN1
 DIO_PORTC_PIN2
 DIO_PORTC_PIN3
 DIO_PORTC_PIN4
 DIO_PORTC_PIN5
 DIO_PORTC_PIN6
 DIO_PORTC_PIN7

 //			PORTD
 DIO_PORTD_PIN0
 DIO_PORTD_PIN1
 DIO_PORTD_PIN2
 DIO_PORTD_PIN3
 DIO_PORTD_PIN4
 DIO_PORTD_PIN5
 DIO_PORTD_PIN6
 DIO_PORTD_PIN7

 */

#define CLCD_RS				DIO_PORTD_PIN0
#define CLCD_RW				DIO_PORTD_PIN1
#define CLCD_EN				DIO_PORTD_PIN2

static u8 CLCD_u8SpicialCharacter[] =
		{ 0x07, 0x04, 0x0E, 0x00, 0x04, 0x04, 0x04, 0x04, 			//First  Character
		  0x00, 0x00, 0x0F, 0x01, 0x1F,	0x00, 0x00, 0x00,			//Second Character
		  0x00, 0x00, 0x00, 0x0E, 0x1B, 0x0E, 0x00, 0x00,			//Third  Character
		  0x00, 0x00, 0x04, 0x04, 0x1F, 0x00, 0x00, 0x00			//Fourth Character
		};


#endif /* HAL_04__CLCD_CLCD_CONFIG_H_ */