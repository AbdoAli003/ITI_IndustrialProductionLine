#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include <util/delay.h>

#include "MCAL/TIMER/TIMER_interface.h"

#include "SERVO_config.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"

void SERVO_voidPush()
{
	for (u8 i = 0; i < 254; i++){
	TIMER_voidSetDutyCycle(i);
	_delay_ms(5);
	}
	for (s16 i = 254; i >= 0; i--){
	TIMER_voidSetDutyCycle(i);
	_delay_ms(5);
	}
}

