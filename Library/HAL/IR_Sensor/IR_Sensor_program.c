/* =========================== */
/* Created By: Abdulrahman Ali */
/* =========================== */
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"

#include "IR_Sensor_config.h"
#include "IR_Sensor_interface.h"
#include "IR_Sensor_private.h"

u8 IR_Sensoru8GetValue(u8 Copy_u8IR) {
  u8 IR_Sensor_u8Value;
  if (Copy_u8IR == 0)
  DIO_u8GetPinValue(IR_Sensoru8Port, IR1_Sensoru8PIN, &IR_Sensor_u8Value);
  else if (Copy_u8IR == 1)
	  DIO_u8GetPinValue(IR_Sensoru8Port, IR2_Sensoru8PIN, &IR_Sensor_u8Value);
  return IR_Sensor_u8Value;
}

