#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_private.h"

#include "LIB/delay.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"



u8 KPD_Au8Keys[4][4] = {
		{'7','4','1','#'},
		{'8','5','2','0'},
		{'9','6','3','='},
		{'/','*','-','+'}
};							// 4x4 keypad

/*u8 KPD_Au8Keys[4][4] = {
		{'1','4','7','*'},
		{'2','5','8','0'},
		{'3','6','9','#'},
		{'3','6','9','#'}
};	*/						// 4*3 keypad

u8 KPD_Au8AlphaKeys[4][4] = {
		{'A','E','I','M'},
		{'B','F','J','N'},
		{'C','G','K','O'},
		{'D','H','L','P'}
};


u8 KPD_Au8RowsPin[4] = {KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
u8 KPD_Au8ColsPin[4] = {KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

void KPD_voidInit()
{
	for (u8 i = 0; i <= 3; i++)
		DIO_u8SetPinDirection(KPD_u8_PORT, i ,DIO_u8_OUTPUT);
	for (u8 i = 4; i <= 7; i++)
		DIO_u8SetPinDirection(KPD_u8_PORT, i ,DIO_u8_INPUT);
	DIO_u8SetPortValue(KPD_u8_PORT, 0xFF);
}

u8 KPD_u8GetKeyState(u8* Copy_pu8ReturnedKey, u8 ALPHA)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RowsCounter;
	u8 Local_u8ColsCounter;
	u8 Local_u8PinValue;
	u8 Local_u8Flag = 0;
	if (Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/* Activation for row pins */
		for (Local_u8RowsCounter = 0; Local_u8RowsCounter < 4; Local_u8RowsCounter++)
		{
			DIO_u8SetPinValue(KPD_u8_PORT, KPD_Au8RowsPin[Local_u8RowsCounter] ,DIO_u8_LOW);
			for (Local_u8ColsCounter = 0; Local_u8ColsCounter < 4; Local_u8ColsCounter++)
			{
				DIO_u8GetPinValue(KPD_u8_PORT, KPD_Au8ColsPin[Local_u8ColsCounter], &Local_u8PinValue);
				if (Local_u8PinValue == DIO_u8_LOW)
				{
					//delay_ms(20);
					DIO_u8GetPinValue(KPD_u8_PORT, KPD_Au8ColsPin[Local_u8ColsCounter], &Local_u8PinValue);
					while (Local_u8PinValue == DIO_u8_LOW)
					{
						DIO_u8GetPinValue(KPD_u8_PORT, KPD_Au8ColsPin[Local_u8ColsCounter], &Local_u8PinValue);
					}
					*Copy_pu8ReturnedKey = (ALPHA) ? KPD_Au8AlphaKeys[Local_u8RowsCounter][Local_u8ColsCounter] : KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
					Local_u8Flag = 1;
					break;

				}
			}
			DIO_u8SetPinValue(KPD_u8_PORT, KPD_Au8RowsPin[Local_u8RowsCounter] ,DIO_u8_HIGH);
			if (Local_u8Flag == 1) break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
