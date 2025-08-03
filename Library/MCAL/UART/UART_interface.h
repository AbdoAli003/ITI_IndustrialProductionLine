#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_voidInit();
void UART_voidSendData(u8 Copy_u8Data);
u8 UART_u8Recieve();
void UART_voidSendString(u8 Copy_u8PrintedData[]);
#endif
