/* =========================== */
/* Created By: Abdulrahman Ali */
/* =========================== */
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"

#include "IR_Sensor_config.h"
#include "IR_Sensor_interface.h"
#include "IR_Sensor_private.h"

u8 IR_Sensoru8GetValue() {
  u8 IR_Sensor_u8Value;
  DIO_u8GetPinValue(IR_Sensoru8Port, IR_Sensoru8PIN, &IR_Sensor_u8Value);
  return IR_Sensor_u8Value;
}
