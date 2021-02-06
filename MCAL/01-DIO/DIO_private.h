#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* REGISTER DISCRIPTION */
#define DDRA  *((volatile u8 *)0x3A)
#define PORTA *((volatile u8 *)0x3B)
#define PINA  *((volatile u8 *)0x39)

#define DDRB  *((volatile u8 *)0x37)
#define PORTB *((volatile u8 *)0x38)
#define PINB  *((volatile u8 *)0x36)

#define DDRC  *((volatile u8 *)0x34)
#define PORTC *((volatile u8 *)0x35)
#define PINC  *((volatile u8 *)0x33)

#define DDRD  *((volatile u8 *)0x31)
#define PORTD *((volatile u8 *)0x32)
#define PIND  *((volatile u8 *)0x30)


/*            PORTA                        */
#define DIO_u8_PORTA_START                 0
#define DIO_u8_PORTA_END                   7
#define DIO_u8_PORTA_SIZE                  8

/*            PORTB                         */
#define DIO_u8_PORTB_START                 8
#define DIO_u8_PORTB_END                   15
#define DIO_u8_PORTB_SIZE                  8


/*            PORTC                         */
#define DIO_u8_PORTC_START                 16
#define DIO_u8_PORTC_END                   23
#define DIO_u8_PORTC_SIZE                  8



/*            PORTD                         */
#define DIO_u8_PORTD_START                 24
#define DIO_u8_PORTD_END                   31
#define DIO_u8_PORTD_SIZE                  8






#endif
