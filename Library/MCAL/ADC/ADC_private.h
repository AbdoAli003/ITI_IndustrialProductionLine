#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADCL			*((volatile u8*)0x24)
#define ADCH			*((volatile u8*)0x25)
#define ADCSRA			*((volatile u8*)0x26)
#define ADMUX			*((volatile u8*)0x27)
#define ACSR			*((volatile u8*)0x28)

#define CHANNEL_MASK 	0b11100000
#endif
