#include "LIB/STD_TYPES.h"

#include "APP/System_interface.h"
#include "APP/Memory_interface.h"

int main()
{
	/* remove comment to clear memory, comment System_voidSystemStart() then run program*/
	/* comment them again and remove comment from System_voidSystemStart() */
	//System_voidInit();
	//Memory_voidReset();

	System_voidSystemStart();
	return 0;
}

