#ifndef APP_MEMORY_INTERFACE_H_
#define APP_MEMORY_INTERFACE_H_

#define Memory_u8_Red_object        0
#define Memory_u8_Green_object      1
#define Memory_u8_Blue_object       2

#define Memory_u8_State_place       0    // memory place to state if it is initialized or the first time to use it
#define Memory_u8_Signature         22   // used to store in place 0 if memory is initialized

// where we store the number of objects sorted
#define Memory_u8_Red_Place         1
#define Memory_u8_Green_Place       2
#define Memory_u8_Blue_Place        3

// to store the time the production line was running
#define Memory_u8_Seconds_place     4
#define Memory_u8_Minutes_place     5

// to store number of errors happened during running for performance analysis
#define Memory_u8_Errors_place      6

u8   Memory_u8IsMemory_Initialized();
void Memory_voidReset();
void Memory_voidInitMemory();
void Memory_voidStore_object_sorted(u8 objectColor);
void Memory_voidGet_objects_sorted(u8* copy_redObject ,u8* copy_greenObject ,u8* copy_blueObject);

#endif /* APP_MEMORY_INTERFACE_H_ */
