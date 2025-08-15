#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"
#include <stdio.h>
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "Display_interface.h"
#include "Memory_interface.h"

void Display_voidDisplay_Objects_Sorted() {
  u8 red, green, blue;
  Memory_voidGet_objects_sorted(&red, &green, &blue);
  UART_voidSendString((u8 *)"R:");
  Display_voidDisplay_Number(red);
  UART_voidSendString((u8 *)" G:");
  Display_voidDisplay_Number(green);
  UART_voidSendString((u8 *)" B:");
  Display_voidDisplay_Number(blue);
}
void Display_voidDisplay_Number(u8 Num) {
  u8 strNum[4];
  itoa(Num, strNum, 10);
  UART_voidSendString(strNum);
}
