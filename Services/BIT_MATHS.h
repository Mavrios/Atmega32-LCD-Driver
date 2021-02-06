#ifndef BIT_MATHS_H
#define BIT_MATHS_H

#define SET_BIT(BYTE,Bit_NO) (BYTE) |= (1<<(Bit_NO))
#define CLR_BIT(BYTE,Bit_NO) (BYTE) &= ~(1<<(Bit_NO))
#define TOGGEL_BIT(BYTE,Bit_NO) (BYTE) ^= 1<<(Bit_NO)
#define GET_BIT(BYTE,Bit_NO) ((BYTE>>Bit_NO)&(0x01))
	
		
#endif
