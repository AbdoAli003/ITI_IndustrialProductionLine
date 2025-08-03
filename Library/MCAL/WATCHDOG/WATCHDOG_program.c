#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "WATCHDOG_config.h"
#include "WATCHDOG_interface.h"
#include "WATCHDOG_private.h"

void WATCHDOG_voidInit()
{
	SET_BIT(WDTCR,WDTCR_u8_WPD0);
	CLR_BIT(WDTCR,WDTCR_u8_WPD1);
	SET_BIT(WDTCR,WDTCR_u8_WPD2);
}

void WATCHDOG_voidDisable()
{
	WDTCR = WDTCR | 0x18;
	CLR_BIT(WDTCR, WDTCR_u8_WDE);
}
void WATCHDOG_voidEnable()
{
	SET_BIT(WDTCR, WDTCR_u8_WDE);
}
void WATCHDOG_voidFeed()
{
	asm("wdr");
}
