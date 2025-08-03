/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
//ADD Includes HERE (LIB & MCAL)
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/EXTI/EXTI_private.h"
#include "MCAL/EXTI/EXTI_Config.h"

/**pointers to function**/
static void (*pf[3]) (void) = {NULL,NULL,NULL};
/*********************************************************************************/
/* Function: EXTI_voidEXTIEnable	                        				    **/
/* I/P Parameters: Copy_u8EXTINo, u8 Copy_u8EXTISense		          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables a specific EXTI Peripheral				       	**/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*  Copy_u8EXTISense Options:                                                   **/
/*  EXTI_u8_LOW_LEVEL , EXTI_u8_ANY_LOGICAL_CHANGE,                             **/
/*  EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE									**/
/*                                                                              **/
/*********************************************************************************/

void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense)
{
	switch (Copy_u8EXTINo)
	{
	case EXTI_u8_EXTI0:
		switch (Copy_u8EXTISense)
		{
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		default:
			break;
		}
		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT0);
		break;
		case EXTI_u8_EXTI1:
			switch (Copy_u8EXTISense)
			{
			case EXTI_u8_LOW_LEVEL:
				CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
				CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
				break;
			case EXTI_u8_ANY_LOGICAL_CHANGE:
				SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
				CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
				break;
			case EXTI_u8_FALLING_EDGE:
				CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
				SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
				break;
			case EXTI_u8_RISING_EDGE:
				SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
				SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
				break;
			default:
				break;
			}
			SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT1);
			break;
			case EXTI_u8_EXTI2:
				switch (Copy_u8EXTISense)
				{

				case EXTI_u8_FALLING_EDGE:
					CLR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
					break;
				case EXTI_u8_RISING_EDGE:
					SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
					break;
				default:
					break;
				}
				SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT2);
				break;
				default:
					break;
	}
}

/*********************************************************************************/
/* Function: EXTI_voidEXTIDisable	                        				    **/
/* I/P Parameters: Copy_u8EXTINo 							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables a specific EXTI Peripheral				       	**/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo)
{
	switch (Copy_u8EXTINo)
	{
	case EXTI_u8_EXTI0:
		CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT0);
		break;
	case EXTI_u8_EXTI1:
		CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT1);
		break;
	case EXTI_u8_EXTI2:
		CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT2);
		break;
	default:
		break;
	}
}

/*********************************************************************************/
/* Function: EXTI_voidSetCallBack	                        				    **/
/* I/P Parameters: void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex    		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the global pointer to function with passed function  **/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex)
{

    pf[Copy_u8EXTIIndex] = Copy_PtrToFunc;
}

/***********************************EXTI0 ISR***********************************/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)   
{
	if (pf[0])
	pf[0]();
}

/***********************************EXTI1 ISR***********************************/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)   
{
	if (pf[1])
	pf[1]();
}

/***********************************EXTI2 ISR***********************************/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)   
{
	if (pf[2])
	pf[2]();
}
