#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#define CLEAR_SCREEN	0x01
#define CURSOR_BLINK	0x0F
#define CURSOR_OFF		0x0C
#define CLEARSCREEN     0x01
void LCD_voidSendInstruction(u8 Copy_u8instruction);
void LCD_voidInit();
void LCD_voidWriteChar(u8 Copy_u8char);
void LCD_SetPos(u8 x, u8 y);
void LCD_voidWriteString(u8* str);
void LCD_voidClear_Displayed();

#endif
