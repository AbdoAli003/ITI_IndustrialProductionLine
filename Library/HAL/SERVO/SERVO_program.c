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

u8 SERVO_u8Servo1_color;
u8 SERVO_u8Servo2_color;

void SERVO_voidSetColor(u8 Copy_u8ServoNum, u8 Copy_u8Color) {
  if (Copy_u8ServoNum == 1) {
    SERVO_u8Servo1_color = Copy_u8Color;
  } else if (Copy_u8ServoNum == 2) {
    SERVO_u8Servo2_color = Copy_u8Color;
  }
}
u8 SERVO_u8GetServoColor(u8 Copy_u8ServoNum) {
  if (Copy_u8ServoNum == 1) {
    return SERVO_u8Servo1_color;
  } else if (Copy_u8ServoNum == 2) {
    return SERVO_u8Servo2_color;
  }
  return 4;
}

void SERVO_voidPush(u8 Copy_u8ServoNum) {
  if (Copy_u8ServoNum == 2) {
    for (u16 i = 500; i <= 2400; i += 10) {
      OCR1B = i;
      _delay_ms(2);
    }
    for (u16 i = 2400; i >= 500; i -= 10) {
      OCR1B = i;
      _delay_ms(2);
    }
  } else if (Copy_u8ServoNum == 1) {
    // --- Sweep from 0° to 180° ---

    // Go to 0°
    for (u16 i = 500; i <= 2400; i++) {
      OCR1A = i;
      _delay_ms(0.00002);
    }
    for (u16 i = 2400; i >= 500; i--) {
      OCR1A = i;
      _delay_ms(0.00002);
    }
  }
}
