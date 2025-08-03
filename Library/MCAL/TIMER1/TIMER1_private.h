#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCNT1		*((volatile u16*)0x4C)
#define TCCR1A		*((volatile u8*)0x4F)
#define TCCR1B		*((volatile u8*)0x4E)
#define OCR1A		*((volatile u16*)0x4A)
#define ICR1		*((volatile u16*)0x46)
#define OCR1B		*((volatile u16*)0x48)









#endif
