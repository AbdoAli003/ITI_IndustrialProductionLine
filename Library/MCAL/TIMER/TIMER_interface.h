#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#define NORMAL_MODE					0
#define PWN_PHASE_CORRECT_MODE		1
#define CTC_MODE					2
#define	FAST_PWM_MODE				3

#define TIMER_MODE					NORMAL_MODE

void TIMER_voidInit(void);
void TIMER_voidDelay(u32 ms);
u8 TIMER_u8SetCallBackNormal(void(*PtrFunc)(void));
void TIMER_voidEnableInterrupt(void);
void TIMER_voidFPWM_Init(void);
void TIMER_voidSetDutyCycle(u8 num);
u8 TIMER_voidGetTCNT0(void);
void TIMER_voidResetTCNT0(void);




#endif
