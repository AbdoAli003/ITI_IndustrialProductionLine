/* =========================== */
/* Created By: Kerolos Ayman*/
/* =========================== */
#include "LIB/STD_TYPES.h"
#include "Color_Sensor_Interface.h"
#include "HAL/Color_Sensor/Color_Sensor_Interface.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/EXTI/EXTI_Private.h"
#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "HAL/IR_Sensor/IR_Sensor_interface.h"
#include <util/delay.h>

static volatile u8 current_color = UNDEFINED;
static volatile u8 rising_edge_count = 0;
static volatile u16 timer_start = 0;
static volatile u16 timer_end = 0;
static volatile u8 measurement_done = 0;

// ISR for EXTI0 — triggered on rising edge of TCS OUT pin
void TCS3200_EXTI_ISR(void) {
  if (rising_edge_count == 0) {
    timer_start = TIMER_voidGetTCNT0();
    rising_edge_count++;
  } else if (rising_edge_count == 1) {
    timer_end = TIMER_voidGetTCNT0();
    rising_edge_count++;
    measurement_done = 1;
  }
}

void TCS3200_voidInit(void) {
  // Frequency scaling: 20% (S0 = HIGH, S1 = HIGH)
  DIO_u8SetPinValue(TCS3200_S0_PORT, TCS3200_S0_PIN, DIO_u8_HIGH);
  DIO_u8SetPinValue(TCS3200_S1_PORT, TCS3200_S1_PIN, DIO_u8_LOW);
  // Led pin
  DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_HIGH);

  // Setting OUT pin is input (PD2 = INT0) as input pull-up
  DIO_u8SetPinValue(TCS3200_OUT_PORT, TCS3200_OUT_PIN, DIO_u8_HIGH);

  // Initialize Timer0 in NORMAL mode with prescaler = 64
  TIMER_voidResetTCNT0();
}

void TCS3200_voidSelectColor(u8 Copy_u8Color) {
  switch (Copy_u8Color) {
  case RED:
    DIO_u8SetPinValue(TCS3200_S2_PORT, TCS3200_S2_PIN, DIO_u8_LOW);
    DIO_u8SetPinValue(TCS3200_S3_PORT, TCS3200_S3_PIN, DIO_u8_LOW);
    break;

  case GREEN:
    DIO_u8SetPinValue(TCS3200_S2_PORT, TCS3200_S2_PIN, DIO_u8_HIGH);
    DIO_u8SetPinValue(TCS3200_S3_PORT, TCS3200_S3_PIN, DIO_u8_HIGH);
    break;

  case BLUE:
    DIO_u8SetPinValue(TCS3200_S2_PORT, TCS3200_S2_PIN, DIO_u8_LOW);
    DIO_u8SetPinValue(TCS3200_S3_PORT, TCS3200_S3_PIN, DIO_u8_HIGH);
    break;

  case CLEAR:
    DIO_u8SetPinValue(TCS3200_S2_PORT, TCS3200_S2_PIN, DIO_u8_HIGH);
    DIO_u8SetPinValue(TCS3200_S3_PORT, TCS3200_S3_PIN, DIO_u8_LOW);
    break;
  }
}

u16 TCS3200_u16ReadFrequencyHz(void) {
  measurement_done = 0;
  rising_edge_count = 0;

  TIMER_voidResetTCNT0();

  // Wait for two rising edges
  while (!measurement_done)
    ;

  // Handle Timer overflow
  u16 period_counts = (timer_end >= timer_start)
                          ? (timer_end - timer_start)
                          : (256 - timer_start + timer_end);

  if (period_counts == 0)
    return 0;

  // Frequency = 8,000,000 / (64 × period_counts) = 125000 / period_counts
  return (125000UL / period_counts);
}
void TCS3200_voidDetectColor(void) {
  u16 avgFreq, redFreq, greenFreq, blueFreq;

  // Measure RED
  TCS3200_voidSelectColor(RED);
  _delay_ms(100);
  redFreq = TCS3200_u16ReadFrequencyHz();

  // Measure GREEN
  TCS3200_voidSelectColor(GREEN);
  _delay_ms(100);
  greenFreq = TCS3200_u16ReadFrequencyHz();

  // Measure BLUE
  TCS3200_voidSelectColor(BLUE);
  _delay_ms(100);
  blueFreq = TCS3200_u16ReadFrequencyHz();
  avgFreq = (redFreq + greenFreq + blueFreq) / 3;

  /* If average is too high no object
  if (avgFreq <= 7500) // Adjust threshold based on test (500–800)
  {
    return "UNKNOWN";
  }

  Determine dominant color — higher frequency means higher intensity*/
  while (IR_Sensoru8GetValue(3))
    ; // Wait until there is an object near color sensor
  if (redFreq >= greenFreq && redFreq >= blueFreq)
    current_color = 0;
  else if (greenFreq >= redFreq && greenFreq >= blueFreq)
    current_color = 1;
  else if (blueFreq >= redFreq && blueFreq >= greenFreq)
    current_color = 2;
  else
    current_color = 4;
}
u8 TCS3200_u8Getcurrentcolor(void) { return current_color; }
