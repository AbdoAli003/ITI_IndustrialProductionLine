#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#define ADC0			0
#define ADC1 			1
#define ADC2 			2
#define ADC3 			3
#define ADC4 			4
#define ADC5 			5
#define ADC6 			6
#define ADC7 			7

#define TIMEOUT 		50000

void ADC_voidInit();
u16 ADC_u16ReadSync(u8 Copy_u8Channel, u16* Reading);
u8 ADC_u8ReadAsync(u8 Copy_u8Channel, u16* Pu16Reading, void(*PtrFunc)(void));


#endif
