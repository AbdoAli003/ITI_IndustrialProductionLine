#ifndef COLOR_SENSOR_INTERFACE_H
#define COLOR_SENSOR_INTERFACE_H

#define TCS3200_S0_PORT 	DIO_u8_PORTA
#define TCS3200_S0_PIN 		DIO_u8_PIN0

#define TCS3200_S1_PORT 	DIO_u8_PORTA
#define TCS3200_S1_PIN 		DIO_u8_PIN1

#define TCS3200_S2_PORT 	DIO_u8_PORTA
#define TCS3200_S2_PIN 		DIO_u8_PIN2

#define TCS3200_S3_PORT 	DIO_u8_PORTA
#define TCS3200_S3_PIN 		DIO_u8_PIN3

// Output pin (used for EXTI0 and Timer0 counter input)
#define TCS3200_OUT_PORT 	DIO_u8_PORTD
#define TCS3200_OUT_PIN 	DIO_u8_PIN2

#define RED 				0
#define GREEN 				1
#define BLUE 				2
#define CLEAR 				3
#define UNDEFINED			4


void 	TCS3200_voidInit(void);
void 	TCS3200_voidSelectColor(u8 Copy_u8Color);
u16 	TCS3200_u16ReadFrequencyHz(void);
void 	TCS3200_EXTI_ISR(void);
void 	TCS3200_voidDetectColor(void);
u8 		TCS3200_u8Getcurrentcolor(void);

#endif
