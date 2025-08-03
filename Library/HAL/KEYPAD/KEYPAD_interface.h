#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#define KPD_u8_KEY_NOT_PRESSED		0xff
#define DC_MOTOR 					'1'
#define STEPPER						'2'

void KPD_voidInit();
u8 KPD_u8GetKeyState(u8* Copy_pu8ReturnedKey, u8 ALPHA);


#endif
