#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"

void UART_voidInit()
{
	// 8 bit data mode
	UCSRC = (1 << UCSRC_u8_URSEL) | (1 << UCSRC_u8_UCSZ0) | (1 << UCSRC_u8_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_u8_UCSZ2);
	// 9600
	UBRRL = 51;
	// enable trans/recv
	SET_BIT(UCSRB,UCSRB_u8_TXEN);
	SET_BIT(UCSRB,UCSRB_u8_RXEN);
	// async
}
void UART_voidSendData(u8 Copy_u8Data)
{
	while (!GET_BIT(UCSRA,UCSRA_u8_UDRE));
		UDR = Copy_u8Data;
}
u8 UART_u8Recieve()
{
	while (!GET_BIT(UCSRA,UCSRA_u8_RXC));
		return UDR;
}
void UART_voidSendString(u8 Copy_u8PrintedData[])
{
	u8* ptr = Copy_u8PrintedData;
	while (*ptr != '\0')
	{
		UART_voidSendData(*ptr);
		ptr++;
	}
}
