
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

void SW_voidInit(SW_Type SW_Config){

    DIO_enumSetPinDirection(SW_Config.Pin,DIO_INPUT);

    if( SW_Config.Pull_State == SW_PULL_UP ){
        DIO_voidActivePullUp(SW_Config.Pin);
    } 
}

u8 SW_u8GetPressed(SW_Type SW_Config){
    u8 LOC_u8Result = DIO_u8ReadPinValue(SW_Config.Pin);
    return !LOC_u8Result;
}
