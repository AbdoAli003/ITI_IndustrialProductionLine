#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
// Tick Time = 1 / (8MHZ / 64) = 8 us
// OV Time = 8 us * 256 = 2048 us = 2.048 ms
// 0 degree = 1 ms -> 1 ms / 8 us = 125
// 90 degree = 1.5 ms -> 1.5 ms / 8 us = 187
// 90 degree = 2 ms -> 2 ms / 8 us = 250

static void (*GlobalPtrFuncNormal)(void) = NULL;
u32 TIMER_u32GlobalCounter = 0;
u8 TIMER_u8OneSec = 0;
void TIMER_voidInit(void) {
  if (TIMER_MODE == NORMAL_MODE) {
    CLR_BIT(TCCR0, TCCR0_u8_WGM01);
    CLR_BIT(TCCR0, TCCR0_u8_WGM00);
  } else if (TIMER_MODE == CTC_MODE) {
    SET_BIT(TCCR0, TCCR0_u8_WGM01);
    CLR_BIT(TCCR0, TCCR0_u8_WGM00);
  }

  SET_BIT(TCCR0, TCCR0_u8_CS00);
  SET_BIT(TCCR0, TCCR0_u8_CS01);
  CLR_BIT(TCCR0, TCCR0_u8_CS02);
}
void TIMER_voidFPWM_Init(void) {
  SET_BIT(TCCR0, TCCR0_u8_WGM01);
  SET_BIT(TCCR0, TCCR0_u8_WGM00);

  SET_BIT(TCCR0, TCCR0_u8_CS00);
  SET_BIT(TCCR0, TCCR0_u8_CS01);
  CLR_BIT(TCCR0, TCCR0_u8_CS02);

  CLR_BIT(TCCR0, TCCR0_u8_COM00);
  SET_BIT(TCCR0, TCCR0_u8_COM01);
  OCR0 = 50;
}

void TIMER_voidDelay(u32 ms) {
  u32 ticks = (u32)((f32)ms / 2.048 + 0.5);
  u32 LocalCounter = TIMER_u32GlobalCounter;
  while (TIMER_u32GlobalCounter - LocalCounter < ticks)
    ;
}
u8 TIMER_voidGetTCNT0(void) { return TCNT0; }
void TIMER_voidResetTCNT0(void) { TCNT0 = 0x00; }
u8 TIMER_u8SetCallBackNormal(void (*PtrFunc)(void)) {
  u8 Local_ErrorState = STD_TYPES_OK;
  if (PtrFunc) {
    GlobalPtrFuncNormal = PtrFunc;
  } else
    Local_ErrorState = STD_TYPES_NOK;
  return Local_ErrorState;
}
void TIMER_voidEnableInterrupt() {
  SET_BIT(TIMSK, TIMSK_u8_TOIE0);
  SET_BIT(TIMSK, TIMSK_u8_OCIE0);
}
void TIMER_voidSetDutyCycle(u8 num) { OCR0 = num; }
void __vector_11(void) __attribute__((signal)); // Normal Mode
void __vector_11(void) {
  /*if (GlobalPtrFuncNormal)
  GlobalPtrFuncNormal();
  static u32 LocalCounter = 0;
  LocalCounter++;
  TIMER_u32GlobalCounter++;
  if (LocalCounter >= 488)
  {
          TIMER_u8OneSec = 1;
          LocalCounter = 0;
  }*/
}
void __vector_10(void) __attribute__((signal)); // CTC Mode
void __vector_10(void) {
  if (GlobalPtrFuncNormal)
    GlobalPtrFuncNormal();
  /*static u32 ms = 0;
  ms++;
  if (ms >= 1000)
  {
          ms = 0;
          TIMER_u8OneSec = 1;
  }*/
}
