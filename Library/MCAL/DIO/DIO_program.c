/* Lib layer */
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
/* MCAL */
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_voidInit(void) {
	  /* Direction for IR Sensor pin */
	  DIO_u8SetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_INPUT);
	  /* Direction for COLOR_SENSOR Sensor pin */
	  DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_OUTPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_OUTPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_OUTPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_OUTPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_OUTPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_INPUT);
	  /* Direction for URAT pin */
	  DIO_u8SetPinDirection(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_INPUT);
	  DIO_u8SetPinDirection(DIO_u8_PORTD, DIO_u8_PIN1, DIO_u8_OUTPUT);
}

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
                         u8 Copy_u8PinDirection) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) &&
      ((Copy_u8PinDirection == DIO_u8_OUTPUT) ||
       (Copy_u8PinDirection == DIO_u8_INPUT))) {
    switch (Copy_u8PortId) {
    case DIO_u8_PORTA:
      switch (Copy_u8PinDirection) {
      case DIO_u8_OUTPUT:
        SET_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
        break;
      case DIO_u8_INPUT:
        CLR_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
        break;
      }
      break;
    case DIO_u8_PORTB:
      switch (Copy_u8PinDirection) {
      case DIO_u8_OUTPUT:
        SET_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
        break;
      case DIO_u8_INPUT:
        CLR_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
        break;
      }
      break;
    case DIO_u8_PORTC:
      switch (Copy_u8PinDirection) {
      case DIO_u8_OUTPUT:
        SET_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
        break;
      case DIO_u8_INPUT:
        CLR_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
        break;
      }
      break;
    case DIO_u8_PORTD:
      switch (Copy_u8PinDirection) {
      case DIO_u8_OUTPUT:
        SET_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
        break;
      case DIO_u8_INPUT:
        CLR_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
        break;
      }
      break;
    }
  } else {
    Local_u8ErrorState = STD_TYPES_NOK;
  }

  return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  if (Copy_u8PinId <= DIO_u8_PIN7) {
    switch (Copy_u8PortId) {
    case DIO_u8_PORTA:
      switch (Copy_u8PinValue) {
      case DIO_u8_HIGH:
        SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
        break;
      case DIO_u8_LOW:
        CLR_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
        break;
      default:
        Local_u8ErrorState = STD_TYPES_NOK;
      }
      break;
    case DIO_u8_PORTB:
      switch (Copy_u8PinValue) {
      case DIO_u8_HIGH:
        SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
        break;
      case DIO_u8_LOW:
        CLR_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
        break;
      default:
        Local_u8ErrorState = STD_TYPES_NOK;
      }
      break;
    case DIO_u8_PORTC:
      switch (Copy_u8PinValue) {
      case DIO_u8_HIGH:
        SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
        break;
      case DIO_u8_LOW:
        CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
        break;
      default:
        Local_u8ErrorState = STD_TYPES_NOK;
      }
      break;
    case DIO_u8_PORTD:
      switch (Copy_u8PinValue) {
      case DIO_u8_HIGH:
        SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
        break;
      case DIO_u8_LOW:
        CLR_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
        break;
      default:
        Local_u8ErrorState = STD_TYPES_NOK;
      }
      break;
    default:
      Local_u8ErrorState = STD_TYPES_NOK;
    }

  } else {
    Local_u8ErrorState = STD_TYPES_NOK;
  }
  return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
                     u8 *Copy_pu8ReturnedPinValue) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  u8 Local_u8PinValue;
  switch (Copy_u8PortId) {

  case DIO_u8_PORTA:
    *Copy_pu8ReturnedPinValue = GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId);
    break;

  case DIO_u8_PORTB:
    *Copy_pu8ReturnedPinValue = GET_BIT(DIO_u8_PINB_REG, Copy_u8PinId);
    break;

  case DIO_u8_PORTC:
    *Copy_pu8ReturnedPinValue = GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId);
    break;

  case DIO_u8_PORTD:
    *Copy_pu8ReturnedPinValue = GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId);
    break;

  default:
    Local_u8ErrorState = STD_TYPES_NOK;
  }

  return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  if ((Copy_u8PortDirection == DIO_u8_OUTPUT) ||
      (Copy_u8PortDirection == DIO_u8_INPUT)) {
    switch (Copy_u8PortId) {
    case DIO_u8_PORTA:
      switch (Copy_u8PortDirection) {
      case DIO_u8_OUTPUT:
        DIO_u8_DDRA_REG = 0xff;
        break;
      case DIO_u8_INPUT:
        DIO_u8_DDRA_REG = 0x00;
        break;
      }
      break;
    case DIO_u8_PORTB:
      switch (Copy_u8PortDirection) {
      case DIO_u8_OUTPUT:
        DIO_u8_DDRB_REG = 0xff;
        break;
      case DIO_u8_INPUT:
        DIO_u8_DDRB_REG = 0x00;
        break;
      }
      break;
    case DIO_u8_PORTC:
      switch (Copy_u8PortDirection) {
      case DIO_u8_OUTPUT:
        DIO_u8_DDRC_REG = 0xff;
        break;
      case DIO_u8_INPUT:
        DIO_u8_DDRC_REG = 0x00;
        break;
      }
      break;
    case DIO_u8_PORTD:
      switch (Copy_u8PortDirection) {
      case DIO_u8_OUTPUT:
        DIO_u8_DDRD_REG = 0xff;
        break;
      case DIO_u8_INPUT:
        DIO_u8_DDRD_REG = 0x00;
        break;
      }
      break;
    default:
      Local_u8ErrorState = STD_TYPES_NOK;
    }
  } else {
    Local_u8ErrorState = STD_TYPES_NOK;
  }
  return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  switch (Copy_u8PortId) {
  case DIO_u8_PORTA:
    DIO_u8_PORTA_REG = Copy_u8PortValue;
    break;
  case DIO_u8_PORTB:
    DIO_u8_PORTB_REG = Copy_u8PortValue;
    break;
  case DIO_u8_PORTC:
    DIO_u8_PORTC_REG = Copy_u8PortValue;
    break;
  case DIO_u8_PORTD:
    DIO_u8_PORTD_REG = Copy_u8PortValue;
    break;
  default:
    Local_u8ErrorState = STD_TYPES_NOK;
  }
  return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  if (Copy_pu8ReturnedPortValue != NULL) {
    switch (Copy_u8PortId) {
    case DIO_u8_PORTA:
      *Copy_pu8ReturnedPortValue = DIO_u8_PINA_REG;
      break;
    case DIO_u8_PORTB:
      *Copy_pu8ReturnedPortValue = DIO_u8_PINB_REG;
      break;
    case DIO_u8_PORTC:
      *Copy_pu8ReturnedPortValue = DIO_u8_PINC_REG;
      break;
    case DIO_u8_PORTD:
      *Copy_pu8ReturnedPortValue = DIO_u8_PIND_REG;
      break;
    default:
      Local_u8ErrorState = STD_TYPES_NOK;
    }
  } else {
    Local_u8ErrorState = STD_TYPES_NOK;
  }
  return Local_u8ErrorState;
}
