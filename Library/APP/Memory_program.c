#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "HAL/EEPROM/EEPROM_Interface.h"
#include "Memory_interface.h"

static u8 redObject, greenObject, blueObject, Seconds, Minutes, Errors;

u8 Memory_u8IsMemory_Initialized() {
  if (EEPROM_u8ReadDataByte(0) != Memory_u8_Signature) {
    EEPROM_voidSendDataByte(0, Memory_u8_Signature);
    return 0;
  } else {
    return 1;
  }
}
void Memory_voidInitMemory() {
  EEPROM_voidEEPROMInit();
  if (!Memory_u8IsMemory_Initialized()) {
    redObject = 0;
    greenObject = 0;
    blueObject = 0;
    Seconds = 0;
    Minutes = 0;
    Errors = 0;
    for (u8 i = 1; i < 7; ++i) {
      EEPROM_voidSendDataByte(i, 0);
    }
  } else {
    redObject = EEPROM_u8ReadDataByte(Memory_u8_Red_Place);
    greenObject = EEPROM_u8ReadDataByte(Memory_u8_Green_Place);
    blueObject = EEPROM_u8ReadDataByte(Memory_u8_Blue_Place);
    Seconds = EEPROM_u8ReadDataByte(Memory_u8_Seconds_place);
    Minutes = EEPROM_u8ReadDataByte(Memory_u8_Minutes_place);
    Errors = EEPROM_u8ReadDataByte(Memory_u8_Errors_place);
  }
}
void Memory_voidReset() {
  redObject = 0;
  greenObject = 0;
  blueObject = 0;
  Seconds = 0;
  Minutes = 0;
  Errors = 0;
  for (u8 i = 1; i < 7; ++i) {
    EEPROM_voidSendDataByte(i, 0);
  }
}
void Memory_voidStore_object_sorted(u8 objectColor) {
  switch (objectColor) {
  case Memory_u8_Blue_object:
    ++blueObject;
    EEPROM_voidSendDataByte(Memory_u8_Blue_Place, blueObject);
    break;
  case Memory_u8_Green_object:
    ++greenObject;
    EEPROM_voidSendDataByte(Memory_u8_Green_Place, greenObject);
    break;
  case Memory_u8_Red_object:
    ++redObject;
    EEPROM_voidSendDataByte(Memory_u8_Red_Place, redObject);
    break;
  }
}
void Memory_voidGet_objects_sorted(u8 *copy_redObject, u8 *copy_greenObject,
                                   u8 *copy_blueObject) {
  *copy_redObject = redObject;
  *copy_greenObject = greenObject;
  *copy_blueObject = blueObject;
}
