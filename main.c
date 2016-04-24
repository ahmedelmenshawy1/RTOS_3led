/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "Types.h"
#include "DIO_interface.h"
#include "Timer_Interface.h"
#include "RTOS_Interface.h"
#include "delay.h"

#define		RTOS_u8LedOn		1
#define		RTOS_u8LedOff		0

/*Comment:Set Led Number */
#define		RTOS_u8GreenLed		0
#define		RTOS_u8RedLed		1
#define		RTOS_u8YellowLed	2

extern void RTOS_GreenOnTask(void);
extern void RTOS_GreenOffTask(void);

extern void RTOS_RedOnTask(void);
extern void RTOS_RedOffTask(void);

extern void RTOS_YellowOnTask(void);
extern void RTOS_YellowOffTask(void);

/*Comment:Set Periodicity to Green Task */
#define RTOS_u8PeriodictyGreenOnTaskChoose		4
#define RTOS_u8FisrtDelayGreenOnTaskChoose		0
#define RTOS_u8FisrtDelayGreenOffTaskChoose		4
#define RTOS_u8PeriodictyGreenOffTaskChoose		2

/*Comment:Set Periodicity to Red Task */
#define RTOS_u8PeriodictyRedOnTaskChoose		6
#define RTOS_u8FisrtDelayRedOnTaskChoose		0
#define RTOS_u8PeriodictyRedOffTaskChoose 		6
#define RTOS_u8FisrtDelayRedOffTaskChoose		3

/*Comment:Set Periodicity to Yellow Task */
#define RTOS_u8PeriodictyYellowOnTaskChoose		8
#define RTOS_u8FisrtDelayYellowOnTaskChoose 	0
#define RTOS_u8PeriodictyYellowOffTaskChoose	8
#define RTOS_u8FisrtDelayYellowOffTaskChoose 	4

int main (void)
{
	DIO_VoidInit();

	/*Comment:Set Create to Green Task */
	RTOS_voidCreateTask(RTOS_GreenOnTask,RTOS_u8PeriodictyGreenOnTaskChoose,RTOS_u8FisrtDelayGreenOnTaskChoose+1);
	RTOS_voidCreateTask(RTOS_GreenOffTask, RTOS_u8FisrtDelayGreenOffTaskChoose,RTOS_u8PeriodictyGreenOffTaskChoose + 1);

	/*Comment:Set Create to Red Task */
	RTOS_voidCreateTask(RTOS_RedOnTask, RTOS_u8PeriodictyRedOnTaskChoose,RTOS_u8FisrtDelayRedOnTaskChoose + 1);
	RTOS_voidCreateTask(RTOS_RedOffTask,RTOS_u8PeriodictyRedOffTaskChoose ,RTOS_u8FisrtDelayRedOffTaskChoose+1);

	/*Comment:Set Periodicity to Yellow Task */
	RTOS_voidCreateTask(RTOS_YellowOnTask,RTOS_u8PeriodictyYellowOnTaskChoose,RTOS_u8FisrtDelayYellowOnTaskChoose+1);
	RTOS_voidCreateTask(RTOS_YellowOffTask,RTOS_u8PeriodictyYellowOffTaskChoose ,RTOS_u8FisrtDelayYellowOffTaskChoose+1);

	RTOS_VoidInit();

	while(1)
	{

	}
	return 0;
}

/********************************/
extern void RTOS_GreenOnTask(void)
{
	DIO_u8WritePinVal(RTOS_u8GreenLed,RTOS_u8LedOn);
}
/********************************/
extern void RTOS_GreenOffTask(void)
{
	DIO_u8WritePinVal(RTOS_u8GreenLed,RTOS_u8LedOff);
}
/********************************/
extern void RTOS_RedOnTask(void)
{
	DIO_u8WritePinVal(RTOS_u8RedLed,RTOS_u8LedOn);
}
/********************************/
extern void RTOS_RedOffTask(void)
{
	DIO_u8WritePinVal(RTOS_u8RedLed,RTOS_u8LedOff);
}
/********************************/
extern void RTOS_YellowOnTask(void)
{
	DIO_u8WritePinVal(RTOS_u8YellowLed,RTOS_u8LedOn);
}
/********************************/
extern void RTOS_YellowOffTask(void)
{
	DIO_u8WritePinVal(RTOS_u8YellowLed,RTOS_u8LedOff);
}
/********************************/
