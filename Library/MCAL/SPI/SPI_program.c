#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"


u8 SPI_u8TransRecieve(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while (!GET_BIT(SPSR,SPSR_u8_SPIF));
	return SPDR;
}
void SPI_voidMasterInit()
{
	// Master mode
	SET_BIT(SPCR,SPCR_u8_MSTR);
	// Prescaler
	CLR_BIT(SPCR,SPCR_u8_SPR0);
	SET_BIT(SPCR,SPCR_u8_SPR1);
	CLR_BIT(SPSR,SPSR_u8_SPI2X);
	// Enable
	SET_BIT(SPCR,SPCR_u8_SPE);

	CLR_BIT(SPCR,SPCR_u8_DORD);

	CLR_BIT(SPCR,SPCR_u8_CPHA);
	CLR_BIT(SPCR,SPCR_u8_CPOL);
}
void SPI_voidSlaveInit()
{
	// Slave mode
	CLR_BIT(SPCR,SPCR_u8_MSTR);
	// Enable
	SET_BIT(SPCR,SPCR_u8_SPE);

	CLR_BIT(SPCR,SPCR_u8_DORD);

	CLR_BIT(SPCR,SPCR_u8_CPHA);
	CLR_BIT(SPCR,SPCR_u8_CPOL);
}
