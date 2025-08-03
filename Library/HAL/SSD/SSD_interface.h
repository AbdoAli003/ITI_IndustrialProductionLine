#ifndef HAL_SSD_INTERFACE_H_
#define HAL_SSD_INTERFACE_H_
#include "LIB/STD_TYPES.h"
#define SSD_u8_PIN0              0
#define SSD_u8_PIN1              1
#define SSD_u8_PIN2              2
#define SSD_u8_PIN3              3
#define SSD_u8_PIN4              4
#define SSD_u8_PIN5              5
#define SSD_u8_PIN6              6
#define SSD_u8_PIN7              7

#define SSD_u8_ENABLE_PIN 		SSD_u8_PIN7
#define SSD_u8_HIGH              1
#define SSD_u8_LOW               0

void SSD_voidInit();
void SSD_voidEnable();
void SSD_voidDisable();
void SSD_voidWrite(u8 Copy_u8Digit);

#endif /* HAL_SSD_INTERFACE_H_ */
