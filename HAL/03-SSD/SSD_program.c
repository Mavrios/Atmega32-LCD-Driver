/*
 * SSD_program.c
 *
 *  Created on: Jan 31, 2021
 *      Author: Kishk
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

#include "util/delay.h"

#include "../03-SSD/SSD_interface.h"
#include "../03-SSD/SSD_private.h"
void SSD_voidInit(SSD_Type SSD_structConfig) {
	DIO_enumSetPortDirection(SSD_structConfig.Port, DIO_DIRECTION_OUTPUT);

}

void SSD_voidAllNumbers(SSD_Type SSD_structConfig, u16 Copy_u16Delay) {
	u8 LOC_u8Iterator = 0;
	if (SSD_structConfig.CommonType == SSD_COMMEN_CATHOD) {
		for (LOC_u8Iterator = 0; LOC_u8Iterator < 10; LOC_u8Iterator++) {
			DIO_enumSetPortValue(SSD_structConfig.Port,
					SSD_CATHOD[LOC_u8Iterator]);
			_delay_ms(Copy_u16Delay);
		}
	} else if (SSD_structConfig.CommonType == SSD_COMMEN_ANODE) {
		for (LOC_u8Iterator = 0; LOC_u8Iterator < 10; LOC_u8Iterator++) {
			DIO_enumSetPortValue(SSD_structConfig.Port,
					SSD_ANODE[LOC_u8Iterator]);
			_delay_ms(Copy_u16Delay);
		}
	}
}

void SSD_voidSelectNumber(SSD_Type SSD_structConfig, u8 Copy_u8Number) {
	if (SSD_structConfig.CommonType == SSD_COMMEN_CATHOD) {
			DIO_enumSetPortValue(SSD_structConfig.Port, SSD_CATHOD[Copy_u8Number]);
	}

	if (SSD_structConfig.CommonType == SSD_COMMEN_ANODE) {
			DIO_enumSetPortValue(SSD_structConfig.Port, SSD_ANODE[Copy_u8Number]);

	}
}
