#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"

#include "LIB/delay.h"

#include "SSD_interface.h"
#include "SSD_private.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_private.h"

void SSD_voidInit()
{
	DIO_u8SetPortDirection(DIO_u8_DDRA_REG, DIO_u8_OUTPUT);
}
void SSD_voidEnable()
{
	if (SSD_TYPE == SSD_COMMON_ANODE)
	{
		DIO_u8SetPinValue(SSD_u8_PORT, SSD_u8_ENABLE_PIN ,SSD_u8_HIGH);
	}
	else
		DIO_u8SetPinValue(SSD_u8_PORT, SSD_u8_ENABLE_PIN ,SSD_u8_LOW);
}
void SSD_voidDisable()
{
	if (SSD_TYPE == SSD_COMMON_ANODE)
	{
		DIO_u8SetPinValue(SSD_u8_PORT, SSD_u8_ENABLE_PIN ,SSD_u8_LOW);
	}
	else
		DIO_u8SetPinValue(SSD_u8_PORT, SSD_u8_ENABLE_PIN ,SSD_u8_HIGH);
}
void SSD_voidWrite(u8 Copy_u8Digit)
{
		u8 patternBits = 0;
		for (u8 i = 0; i <= 6; i++)
		{
			patternBits |= ((SSD_Digits[Copy_u8Digit][i]) << i);
		}
		u8 Copy_pu8ReturnedPinValue;
		if (SSD_TYPE == SSD_COMMON_ANODE){
			u8 Copy_pu8ReturnedPortValue;
			DIO_u8GetPortValue(SSD_u8_PORT,&Copy_pu8ReturnedPortValue);
			// flip bits and keep LSB 1
			patternBits = (~patternBits & SSD_u8_MASK);
			patternBits |= (Copy_pu8ReturnedPortValue & 0x80);
		}
		DIO_u8SetPortValue(SSD_u8_PORT, patternBits);

}
