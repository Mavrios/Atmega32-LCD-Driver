#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct {
    u8 PIN;
    u8 Active_State;
}LED_Type;


#define LED_ACTIVE_HIGH 1
#define LED_ACTIVE_LOW  0

void LED_voidInit(LED_Type LED_strcutConfig);
void LED_voidLedOn(LED_Type LED_strcutConfig);
void LED_voidLedOff(LED_Type LED_strcutConfig);


#endif
