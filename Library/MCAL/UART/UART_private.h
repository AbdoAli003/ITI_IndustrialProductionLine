#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UCSRA		*((volatile u8*)0x2B)
#define UCSRB		*((volatile u8*)0x2A)
#define UCSRC		*((volatile u8*)0x40)
#define UDR			*((volatile u8*)0x2C)
#define UBRRL		*((volatile u8*)0x29)

#endif
