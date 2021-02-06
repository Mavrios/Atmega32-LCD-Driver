#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum {
DIO_NOK,
DIO_OK
}DIO_ErrorStatus;

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

//			PORTA
#define DIO_PORTA_PIN0	0
#define DIO_PORTA_PIN1	1
#define DIO_PORTA_PIN2	2
#define DIO_PORTA_PIN3	3
#define DIO_PORTA_PIN4	4
#define DIO_PORTA_PIN5	5
#define DIO_PORTA_PIN6	6
#define DIO_PORTA_PIN7	7

//			PORTB
#define DIO_PORTB_PIN0	8
#define DIO_PORTB_PIN1	9
#define DIO_PORTB_PIN2	10
#define DIO_PORTB_PIN3	11
#define DIO_PORTB_PIN4	12
#define DIO_PORTB_PIN5	13
#define DIO_PORTB_PIN6	14
#define DIO_PORTB_PIN7	15
//			PORTC

#define DIO_PORTC_PIN0	16
#define DIO_PORTC_PIN1	17
#define DIO_PORTC_PIN2	18
#define DIO_PORTC_PIN3	19
#define DIO_PORTC_PIN4	20
#define DIO_PORTC_PIN5	21
#define DIO_PORTC_PIN6	22
#define DIO_PORTC_PIN7	23

//			PORTD
#define DIO_PORTD_PIN0	24
#define DIO_PORTD_PIN1	25
#define DIO_PORTD_PIN2	26
#define DIO_PORTD_PIN3	27
#define DIO_PORTD_PIN4	28
#define DIO_PORTD_PIN5	29
#define DIO_PORTD_PIN6	30
#define DIO_PORTD_PIN7	31



#define DIO_HIGH	1
#define DIO_LOW		0

#define DIO_OUTPUT	1
#define DIO_INPUT	0

#define DIO_DIRECTION_OUTPUT	0xFF
#define DIO_DIRECTION_INPUT		0

#define DIO_DIRECTION_HIGH		0xFF
#define DIO_DIRECTION_LOW		0


/* prototype */

DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port, u8 Cpy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8DirectionValue );
DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PinValue );
u8 DIO_u8ReadPinValue(u8 Copy_u8PinNumber);
void DIO_voidActivePullUp(u8 Copy_u8PinNumber);

#endif
