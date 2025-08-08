/* =========================== */
/* Created By: Abdulrahman Ali */
/* =========================== */
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include <util/delay.h>

#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"


#include "SERVO_config.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"

void SERVO_voidPush(u8 Copy_u8ServoNum) {
	if (Copy_u8ServoNum == 0) {
  for (u8 i = 0; i < 254; i++) {
    TIMER_voidSetDutyCycle(i);
    _delay_ms(5);
  }
  for (s16 i = 254; i >= 0; i--) {
    TIMER_voidSetDutyCycle(i);
    _delay_ms(5);
  }
	}
	else if (Copy_u8ServoNum == 1)
	{
		// --- Sweep from 0° to 180° ---

		        // Go to 0°
				for (u16 i = 500; i <= 2400; i++)
				{
			        OCR1A = i;
			        _delay_ms(0.2);
				}
				for (u16 i = 2400; i >= 500; i--)
				{
			        OCR1A = i;
			       _delay_ms(0.2);
				}


	}
	}
