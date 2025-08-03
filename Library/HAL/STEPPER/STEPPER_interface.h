#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#define CLOCKWISE				0
#define COUNTER_CLOCKWISE		1
void STEPPER_voidInit();
u8 STEPPER_u8MoveDegree(u8 Copy_u8Direction, u8 Copy_u8Degree);
u8 STEPPER_u8MoveSteps(u8 Copy_u8Direction, u8 Copy_u8Steps);


#endif
