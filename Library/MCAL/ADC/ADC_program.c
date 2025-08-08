#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

static u8 ADC_u8BusyFlag = 0;
static void (*GlobalPtrFunc)(void) = NULL;
static u16 *Global_Reading = NULL;
void ADC_voidInit() {
  CLR_BIT(ADCSRA, ADCSRA_u8_ADPS0);
  CLR_BIT(ADCSRA, ADCSRA_u8_ADPS1);
  SET_BIT(ADCSRA, ADCSRA_u8_ADPS2);
  // SET_BIT(ADCSRA, ADCSRA_u8_ADATE);

  CLR_BIT(ADMUX, ADMUX_u8_MUX0);
  CLR_BIT(ADMUX, ADMUX_u8_MUX1);
  CLR_BIT(ADMUX, ADMUX_u8_MUX2);
  CLR_BIT(ADMUX, ADMUX_u8_MUX3);
  CLR_BIT(ADMUX, ADMUX_u8_MUX4);

  CLR_BIT(ADMUX, ADMUX_u8_ADLAR);

  SET_BIT(ADMUX, ADMUX_u8_REFS0);
  CLR_BIT(ADMUX, ADMUX_u8_REFS1);

  SET_BIT(ADCSRA, ADCSRA_u8_ADEN);
}

u16 ADC_u16ReadSync(u8 Copy_u8Channel, u16 *Reading) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  u16 Local_u16Counter = 0;
  if (Reading) {
    ADMUX &= CHANNEL_MASK;
    ADMUX |= Copy_u8Channel;
    SET_BIT(ADCSRA, ADCSRA_u8_ADSC);
    while (!GET_BIT(ADCSRA, ADCSRA_u8_ADIF) && Local_u16Counter < TIMEOUT) {
      Local_u16Counter++;
    }
    if (Local_u16Counter == TIMEOUT) {
      Local_u8ErrorState = STD_TYPES_NOK;
    } else {
      SET_BIT(ADCSRA, ADCSRA_u8_ADIF);
      u8 Copy_u8_ADCL_VALUE = ADCL;
      u8 Copy_u8_ADCH_VALUE = ADCH;
      *Reading = ((u16)Copy_u8_ADCH_VALUE << 8) | Copy_u8_ADCL_VALUE;
    }
  } else
    Local_u8ErrorState = STD_TYPES_NOK;

  return Local_u8ErrorState;
}

u8 ADC_u8ReadAsync(u8 Copy_u8Channel, u16 *Pu16Reading, void (*PtrFunc)(void)) {
  u8 Local_u8ErrorState = STD_TYPES_OK;
  if (!ADC_u8BusyFlag) {
    if (Pu16Reading && PtrFunc) {
      ADC_u8BusyFlag = 1;
      Global_Reading = Pu16Reading;
      GlobalPtrFunc = PtrFunc;
      ADMUX &= 0b11100000;
      ADMUX |= Copy_u8Channel;
      // Enable Conversion
      SET_BIT(ADCSRA, ADCSRA_u8_ADSC);
      // Enable Interrupt
      SET_BIT(ADCSRA, ADCSRA_u8_ADIE);

    } else
      Local_u8ErrorState = STD_TYPES_NOK;
  } else
    Local_u8ErrorState = STD_TYPES_NOK;
  return Local_u8ErrorState;
}
/*void __vector_16(void)   __attribute__((signal));
void __vector_16(void)
{
        u8 Copy_u8_ADCL_VALUE = ADCL;
        u8 Copy_u8_ADCH_VALUE = ADCH;
        // Return Reading
        *Global_Reading = ((u16)Copy_u8_ADCH_VALUE << 8) | Copy_u8_ADCL_VALUE;
        // Invoke func
        GlobalPtrFunc();
        // disable int
        CLR_BIT(ADCSRA, ADCSRA_u8_ADIE);
        // back to idle
        ADC_u8BusyFlag = 0 ;
}*/
