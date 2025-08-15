#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include <stdlib.h>
#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "Inputs_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "Display_interface.h"

void Inputs_ShutDown_System() {
  UART_voidSendString((u8 *)"\r\nSystem is Shutting Down...\r\n");
  exit(0);
}
