#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

void LED_voidInit(LED_Type LED_strcutConfig){
    DIO_enumSetPinDirection(LED_strcutConfig.PIN , DIO_OUTPUT);
}

void LED_voidLedOn(LED_Type LED_strcutConfig){
    if(LED_strcutConfig.Active_State == LED_ACTIVE_HIGH){
        DIO_enumSetPinValue(LED_strcutConfig.PIN, DIO_HIGH);
    }
    else if(LED_strcutConfig.Active_State == LED_ACTIVE_LOW){
        DIO_enumSetPinValue(LED_strcutConfig.PIN, DIO_LOW);

    }
}

void LED_voidLedOff(LED_Type LED_strcutConfig){
    if(LED_strcutConfig.Active_State == LED_ACTIVE_HIGH){
        DIO_enumSetPinValue(LED_strcutConfig.PIN, DIO_LOW);
    }
    else if(LED_strcutConfig.Active_State == LED_ACTIVE_LOW){
        DIO_enumSetPinValue(LED_strcutConfig.PIN, DIO_HIGH);

    }
}
