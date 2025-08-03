/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#include "LIB/STD_TYPES.h"
#define F_CPU	8000000UL
#include <util/delay.h>

#include "MCAL/TWI/TWI_interface.h"

#include "HAL/EEPROM/EEPROM_Interface.h"
#include "HAL/EEPROM/EEPROM_Config.h"
#include "HAL/EEPROM/EEPROM_Private.h"

/*********************************************************************************/
/* Function: EEPROM_voidSendDataByte	                       				    **/
/* I/P Parameters: u16 Copy_u16LocationAddress, u8 Copy_u8DataByte   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sends byte of data to eeprom								**/
/*********************************************************************************/
/* Copy_u16LocationAddress:the address of the location you want to write on		**/
/* Copy_u8DataByte:Assign the Data you want to send								**/
/*********************************************************************************/
/*void EEPROM_voidWriteDataByte(u8 Copy_u8Data,
		u16 Copy_u16Location,
		u8 Copy_u8Device)
{
	u8 Local_u8Address;
	Local_u8Address=(0b01010000)|
			(Copy_u8Device<<2)|
			(Copy_u16Location>>8);
	TWI_voidSendStartCondition();
	TWI_voidSendSlaveAddressWithWrite(Local_u8Address);
	TWI_voidSendDataByte((u8)Copy_u16Location);
	TWI_voidSendDataByte(Copy_u8Data);
	TWI_voidSendStopCondition();
	_delay_ms(10);
}*/
void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);
	
	/*Send start condition*/
	TWI_ErrorStatusSendStartConditionWithACK();
	/*Send the address packet*/
	TWI_ErrorStatusSendSlaveAddressWithWriteACK(Local_u8AddressPacket);
	/*Send the rest 8bits of the location address*/
	TWI_ErrorStatusMasterWriteDataByteWithACK((u8)Copy_u16LocationAddress);
	/*Send the data byte to the memory location*/
	TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u8DataByte);
	/*Send stop condition*/
	TWI_voidSendStopCondition();
	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}

/*********************************************************************************/
/* Function: EEPROM_u8ReadDataByte		                       				    **/
/* I/P Parameters: u16 Copy_u16LocationAddress						  		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function reads a byte of data from eeprom							**/
/*********************************************************************************/
/* Copy_u16LocationAddress:the address of the location you want to read from	**/
/*********************************************************************************/
u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 Local_u8AddressPacket, Local_u8Data;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

	/*Send start condition*/

	/*Send the address packet with write request*/

	/*Send the rest 8bits of the location address*/

	/*Send repeated start to change write request into read request*/

	/*Send the address packet with read request*/
	
	/*Get the data from memory*/

	/*send the stop condition*/

	return Local_u8Data;
}
