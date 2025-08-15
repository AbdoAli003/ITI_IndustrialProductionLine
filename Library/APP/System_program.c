#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include <stdio.h>
#include <util/delay.h>

// MCAL
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GPI/GPI_Interface.h"
#include "MCAL/UART/UART_interface.h"

// HAL
#include "HAL/LCD/LCD_interface.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/IR_Sensor/IR_Sensor_interface.h"
#include "HAL/COLOR_SENSOR/Color_Sensor_Interface.h"
#include "HAL/EEPROM/EEPROM_Interface.h"

// APP
#include "Display_interface.h"
#include "Inputs_interface.h"
#include "Memory_interface.h"
#include "System_interface.h"

void System_voidInit() {
  DIO_voidInit();
  UART_voidInit();
  KPD_voidInit();
  TIMER_voidInit();
  TIMER1_voidInit();
  TIMER1_voidFPWN_8_Init();
  EXTI_voidEXTIEnable(0, EXTI_u8_RISING_EDGE); // enable INT0
  EXTI_voidSetCallBack(TCS3200_EXTI_ISR, 0);
  EXTI_voidEXTIEnable(1, EXTI_u8_FALLING_EDGE); // enable INT1
  EXTI_voidSetCallBack(Inputs_ShutDown_System, 1); // Shutdown system interrupt
  GPI_voidInit();
  GPI_voidEnable();
  TCS3200_voidInit(); // color sensor init
  Memory_voidInitMemory(); // external EEPROM init
}

void System_voidSystemStart() {
  System_voidInit();
  // set sorting sriteria
  System_voidSetSorting();
  UART_voidSendString((u8 *)"\r\n");
  Display_voidDisplay_Objects_Sorted();
  while (1) {
    System_voidSystemSorting();
  }
}
void System_voidSystemSorting() {
  while (1) {
    TCS3200_voidDetectColor();
    _delay_ms(100);

    if (TCS3200_u8Getcurrentcolor() == GREEN) {
      System_voidMemoryUpdate(GREEN);

    } else if (TCS3200_u8Getcurrentcolor() == SERVO_u8GetServoColor(1)) {
      while (IR_Sensoru8GetValue(1))
        ;
      _delay_ms(800);
      SERVO_voidPush(1);
      System_voidMemoryUpdate(SERVO_u8GetServoColor(1));

    } else if (TCS3200_u8Getcurrentcolor() == SERVO_u8GetServoColor(2)) {
      while (IR_Sensoru8GetValue(2))
        ;

      _delay_ms(800);
      SERVO_voidPush(2);
      System_voidMemoryUpdate(SERVO_u8GetServoColor(2));
    }
  }
}
void System_voidSetSorting() {
  UART_voidSendString((u8 *)"\r\nSet Sorting\r\n");
  UART_voidSendString((u8 *)"Red bin:(1,2) : ");
  // get input
  u8 MyKey1;
  do {
    KPD_u8GetKeyState(&MyKey1);
    if (MyKey1 == '1' || MyKey1 == '2')
      UART_voidSendData(MyKey1);
  } while (MyKey1 != '1' && MyKey1 != '2');
  SERVO_voidSetColor(MyKey1 - '0', RED);
  UART_voidSendString((u8 *)"\r\nBlue bin:(1,2) : ");
  // get input
  u8 MyKey2;
  do {
    KPD_u8GetKeyState(&MyKey2);
    if (MyKey2 == '1' || MyKey2 == '2') {
      UART_voidSendData(MyKey2);
      if (MyKey2 == MyKey1) {
        MyKey2 = KPD_u8_KEY_NOT_PRESSED;
      }
    }
  } while (MyKey2 != '1' && MyKey2 != '2');
  SERVO_voidSetColor(MyKey2 - '0', BLUE);
}
void System_voidMemoryUpdate(u8 color) {
  Memory_voidStore_object_sorted(color);
  UART_voidSendString((u8 *)"\r\n");
  Display_voidDisplay_Objects_Sorted();
}
