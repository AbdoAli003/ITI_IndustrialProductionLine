#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0		*((volatile u8*)0x53)
#define TCNT0		*((volatile u8*)0X52)
#define TIFR		*((volatile u8*)0X58)
#define TIMSK		*((volatile u8*)0X59)
#define OCR0		*((volatile u8*)0X5C)


#endif
