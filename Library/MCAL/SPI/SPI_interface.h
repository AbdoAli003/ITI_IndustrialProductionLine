#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#define MASTER	0
#define SLAVE	1

#define MODE 	MASTER
void SPI_voidInit();
u8 SPI_u8TransRecieve(u8 Copy_u8Data);
void SPI_voidMasterInit();
void SPI_voidSlaveInit();

#endif
