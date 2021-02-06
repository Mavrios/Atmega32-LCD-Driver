/*
 * SSD_interface.h
 *
 *  Created on: Jan 31, 2021
 *      Author: Kishk
 */

#ifndef HAL_03_SSD_SSD_INTERFACE_H_
#define HAL_03_SSD_SSD_INTERFACE_H_


#define SSD_COMMEN_CATHOD	0
#define SSD_COMMEN_ANODE	1

#define SSD_ZERO			0
#define SSD_ONE				1
#define SSD_TWO				2
#define SSD_THREE			3
#define SSD_FOUR			4
#define SSD_FIVE			5
#define SSD_SIX				6
#define SSD_SEVEN			7
#define SSD_EIGHT			8
#define SSD_NINE			9

typedef struct {
	u8 Port;
	u8 CommonType;
}SSD_Type;


void SSD_voidInit(SSD_Type SSD_structConfig);
void SSD_voidAllNumbers(SSD_Type SSD_structConfig , u16 Copy_u16Delay);
void SSD_voidSelectNumber(SSD_Type SSD_structConfig , u8 Copy_u8Number);

#endif /* HAL_03_SSD_SSD_INTERFACE_H_ */
