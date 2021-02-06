#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_private.h"

DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {

	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch (Copy_u8Port) {
	case DIO_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_PORTD:
		DDRD = Copy_u8Direction;
		break;
	default:
		LOC_enumState = DIO_NOK;
		break;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {

	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch (Copy_u8Port) {
	case DIO_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_PORTD:
		PORTD = Copy_u8Value;
		break;
	default:
		LOC_enumState = DIO_NOK;
		break;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PinNumber, u8 Copy_u8DirectionValue) {

	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* 		DDRA		*/
	if ((Copy_u8PinNumber >= DIO_u8_PORTA_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTA_END)) {
		if (Copy_u8DirectionValue == DIO_OUTPUT) {
			SET_BIT(DDRA, Copy_u8PinNumber);
		} else {
			CLR_BIT(DDRA, Copy_u8PinNumber);
		}

	}
	/* 		DDRB		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTB_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTB_END)) {
		if (Copy_u8DirectionValue == DIO_OUTPUT) {
			SET_BIT(DDRB, (Copy_u8PinNumber - DIO_u8_PORTA_SIZE));
		} else {
			CLR_BIT(DDRB, (Copy_u8PinNumber - DIO_u8_PORTA_SIZE));
		}
	}
	/* 		DDRC		*/

	else if ((Copy_u8PinNumber >= DIO_u8_PORTC_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTC_END)) {
		if (Copy_u8DirectionValue == DIO_OUTPUT) {
			SET_BIT(DDRC,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE)));
		} else {
			CLR_BIT(DDRC,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE)));
		}

		/* 		DDRD		*/
	} else if ((Copy_u8PinNumber >= DIO_u8_PORTD_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTD_END)) {
		if (Copy_u8DirectionValue == DIO_OUTPUT) {
			SET_BIT(DDRD,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE)));
		} else {
			CLR_BIT(DDRD,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE)));
		}

	}
	else{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PinValue) {
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* 		PORTA		*/
	if ((Copy_u8PinNumber >= DIO_u8_PORTA_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTA_END)) {
		if (Copy_u8PinValue == DIO_HIGH) {
			SET_BIT(PORTA, Copy_u8PinNumber);
		} else {
			CLR_BIT(PORTA, Copy_u8PinNumber);
		}
	}

	/* 		PORTB		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTB_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTB_END)) {
		if (Copy_u8PinValue == DIO_HIGH) {
			SET_BIT(PORTB, (Copy_u8PinNumber - DIO_u8_PORTA_SIZE));
		} else {
			CLR_BIT(PORTB, (Copy_u8PinNumber - DIO_u8_PORTA_SIZE));
		}
	}

	/* 		PORTC		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTC_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTC_END)) {
		if (Copy_u8PinValue == DIO_HIGH) {
			SET_BIT(PORTC,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE)));
		} else {
			CLR_BIT(PORTC,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE)));
		}
	}

	/* 		PORTD		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTD_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTD_END)) {
		if (Copy_u8PinValue == DIO_HIGH) {
			SET_BIT(PORTD,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE)));
		} else {
			CLR_BIT(PORTD,
					(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE)));
		}

	}
	else{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

u8 DIO_u8ReadPinValue(u8 Copy_u8PinNumber) {
	/* 		PORTA		*/
	u8 LOC_u8Result = 0;
	if ((Copy_u8PinNumber >= DIO_u8_PORTA_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTA_END)) {
		LOC_u8Result = GET_BIT(PINA, Copy_u8PinNumber);
	}

	/* 		PORTB		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTB_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTB_END)) {
		LOC_u8Result = GET_BIT(PINB, (Copy_u8PinNumber - (DIO_u8_PORTA_SIZE)));
	}

	/* 		PORTC		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTC_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTC_END)) {
		LOC_u8Result = GET_BIT(PINC,
				(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE)));
	}

	/* 		PORTD		*/
	else if ((Copy_u8PinNumber >= DIO_u8_PORTD_START)
			&& (Copy_u8PinNumber <= DIO_u8_PORTD_END)) {
		LOC_u8Result =
				GET_BIT(PIND,
						(Copy_u8PinNumber - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE)));

	}
	return LOC_u8Result;
}

void DIO_voidActivePullUp(u8 Copy_u8PinNumber) {
	DIO_enumSetPinValue(Copy_u8PinNumber, DIO_HIGH);
}
