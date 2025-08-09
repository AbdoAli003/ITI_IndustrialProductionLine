#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

void TIMER1_voidInit() {
  switch (TIMER1_MODE) {
  case NORMAL_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_8_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_9_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_10_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case CTC_OCR1A_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case FPWNM_8_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case FPWNM_9_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case FPWNM_10_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_FREQ_ICR1_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_FREQ_OCR1A_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_ICR1_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case PWM_PHASE_OCR1A_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case CTC_ICR1_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case FPWM_ICR1_MODE:
    CLR_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  case FPWM_OCR1A_MODE:
    SET_BIT(TCCR1A, TCCR1A_u8_WGM10);
    SET_BIT(TCCR1A, TCCR1A_u8_WGM11);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM12);
    SET_BIT(TCCR1B, TCCR1B_u8_WGM13);
    break;
  default:
    break;
  }
}
void TIMER1_voidFPWN_8_Init() {
  /* Step 1: Set Fast PWM Mode 14 (TOP = ICR1) */
  TCCR1A = 0; // Clear register first
  TCCR1B = 0; // Clear register first

  // WGM bits: WGM13=1, WGM12=1, WGM11=1, WGM10=0 (Mode 14)
  TCCR1A |= (1 << 1);            // WGM11 = 1
  TCCR1B |= (1 << 4) | (1 << 3); // WGM13=1, WGM12=1

  /* Step 2: Configure BOTH OC1A and OC1B for Non-inverting PWM */
  // OC1A (PD5) - Clear on compare match, set at BOTTOM
  TCCR1A |= (1 << 7); // COM1A1 = 1
  // COM1A0 = 0 (already cleared)

  // OC1B (PD4) - Clear on compare match, set at BOTTOM
  TCCR1A |= (1 << 5); // COM1B1 = 1
  // COM1B0 = 0 (already cleared)

  /* Step 3: Set Prescaler = 8 */
  TCCR1B |= (1 << 1); // CS11 = 1, others = 0

  /* Step 4: Set TOP value for 50Hz (20ms period) */
  ICR1 = 19999; // 20ms period

  /* Step 5: Initialize both servos to starting position */
  OCR1A = 500; // Servo2 Starting position (0°)
  OCR1B = 500; // Servo1 Starting position (0°)
}
void TIMER1_voidSetCompareValueA(u16 Copy_u16Value) { OCR1A = Copy_u16Value; }
void TIMER1_voidSetCompareValueB(u16 Copy_u16Value) { OCR1B = Copy_u16Value; }
