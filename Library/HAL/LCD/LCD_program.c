#include "LIB/STD_TYPES.h"

#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_voidSendInstruction(u8 Copy_u8instruction) {
  DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RSPIN, DIO_u8_LOW);
  DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_LOW);
  DIO_u8SetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_EPIN, DIO_u8_HIGH);
  DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8instruction);
  delay_ms(2);
  DIO_u8SetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_EPIN, DIO_u8_LOW);
}
void LCD_voidInit() {
  DIO_u8SetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_OUTPUT);
  DIO_u8SetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_OUTPUT);
  DIO_u8SetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_OUTPUT);

  DIO_u8SetPortDirection(LCD_u8_DATA_PORT, DIO_u8_OUTPUT);
  delay_ms(60);
  LCD_voidSendInstruction(0b00111100);
  delay_ms(2);
  LCD_voidSendInstruction(0b00001100);
  delay_ms(2);
  LCD_voidSendInstruction(0b00000001);
  delay_ms(2);
  LCD_voidSendInstruction(0b00000110);
  delay_ms(2);
}
void LCD_voidWriteChar(u8 Copy_u8char) {
  DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RSPIN, DIO_u8_HIGH);
  DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_LOW);
  DIO_u8SetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_EPIN, DIO_u8_HIGH);
  DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8char);
  delay_ms(2);
  DIO_u8SetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_EPIN, DIO_u8_LOW);
}
void LCD_SetPos(u8 x, u8 y) { LCD_voidSendInstruction(0x80 + 0x40 * y + x); }
void LCD_voidWriteString(u8 *str) {
  u8 count = 0;
  while (*str != '\0') {
    LCD_voidWriteChar(*str);
    str++;
    count++;
    if (count == 16) {
      LCD_SetPos(0, 1);
      count = 0;
    }
  }
}
