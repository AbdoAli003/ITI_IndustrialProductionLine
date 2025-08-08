#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#define	NORMAL_MODE								0
#define	PWM_PHASE_8_MODE						1
#define	PWM_PHASE_9_MODE						2
#define	PWM_PHASE_10_MODE						3
#define	CTC_OCR1A_MODE							4
#define	FPWNM_8_MODE							5
#define	FPWNM_9_MODE							6
#define	FPWNM_10_MODE							7
#define	PWM_PHASE_FREQ_ICR1_MODE				8
#define	PWM_PHASE_FREQ_OCR1A_MODE				9
#define	PWM_PHASE_ICR1_MODE						10
#define	PWM_PHASE_OCR1A_MODE					11
#define	CTC_ICR1_MODE							12
#define	FPWM_ICR1_MODE							14
#define	FPWM_OCR1A_MODE							15

#define TIMER1_MODE								FPWM_ICR1_MODE

void TIMER1_voidInit();
void TIMER1_voidFPWN_8_Init();
void TIMER1_voidSetCompareValue(u16 Copy_u16Value);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
