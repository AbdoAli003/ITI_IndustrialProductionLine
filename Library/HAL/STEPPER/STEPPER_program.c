#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"

void STEPPER_voidInit()
{
	DIO_u8SetPortValue(STEPPER_u8_PORT, 0x0F);
}

u8 STEPPER_u8MoveDegree(u8 Copy_u8Direction, u8 Copy_u8Degree)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Steps = ((((Copy_u8Degree * 2048UL)) / 360) / 4);
	if (Copy_u8Direction == CLOCKWISE)
	{
		for (u32 i = 0; i < Steps; i++)
		{
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_HIGH);
		}
	}
	else if (Copy_u8Direction == COUNTER_CLOCKWISE)
	{
		for (u32 i = 0; i < Steps; i++)
		{
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_LOW);
			delay_ms(10);
			DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_HIGH);
		}
	}
	else Local_u8ErrorState = STD_TYPES_NOK;
	return 0;
}
u8 STEPPER_u8MoveSteps(u8 Copy_u8Direction, u8 Copy_u8Steps)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
		u32 Steps = Copy_u8Steps;
		if (Copy_u8Direction == CLOCKWISE)
		{
			for (u32 i = 0; i < Steps; i++)
			{
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_HIGH);
			}
		}
		else if (Copy_u8Direction == COUNTER_CLOCKWISE)
		{
			for (u32 i = 0; i < Steps; i++)
			{
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_ORANGE_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_YELLOW_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_PINK_PIN,DIO_u8_HIGH);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_LOW);
				delay_ms(10);
				DIO_u8SetPinValue(STEPPER_u8_PORT, STEPPER_u8_BLUE_PIN,DIO_u8_HIGH);
			}
		}
		else Local_u8ErrorState = STD_TYPES_NOK;
		return 0;
}
