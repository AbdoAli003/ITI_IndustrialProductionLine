#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include "LIB/delay.h"
#include "avr/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"

void DC_MOTOR_voidInit()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DIO_u8_PIN7, DIO_u8_LOW);
}
void DC_MOTOR_on()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DIO_u8_PIN7, DIO_u8_HIGH);
}
void DC_MOTOR_off()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DIO_u8_PIN7, DIO_u8_LOW);
}
