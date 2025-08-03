#ifndef HAL_SSD_PRIVATE_H_
#define HAL_SSD_PRIVATE_H_

#define SSD_COMMON_ANODE 		1
#define SSD_COMMON_CATHODE 		0
#define SSD_TYPE 				SSD_COMMON_CATHODE
#define SSD_u8_PORT 			0
#define SSD_u8_MASK 			0x7F

static u8 SSD_Digits[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,1,0},
    {1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

#endif
