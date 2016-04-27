/*
 * Timer_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "delay.h"
#include "Timer_Config.h"
#include "Timer_Private.h"
#include "Timer_Interface.h"

static u16 Local_u16TotalTime=0;
/***************************************/
extern void Timer_VoidInit(void)
{
	TCCR0|=Timer_u8Prescalir;
	// initialize counter
	TCNT0 = 0;
	TIMSK|=Timer_u8Interrupt;
}

/***************************************/
//OverFlow EXT0
ISR(__vector_11)
{
	ptr_OverFlow();
}
/***************************************/
/*
 * if u want to calculate overflow time u will firstly put your prescaler
 * then calculate max time that will use then devide maximum time over
 * time u want then multiply 1000
 * 50 ms--16 MHz --say 256 Prescaler
 	 maximum delay of  4.096 ms in 8 bit timer
50ms(Required) ÷ 4.096 ms = 12.207
 *
 * */
/*
 * overflow(1024)=65.636ms
 * oneTick(1024)=.256ms
 * */
extern void Timer_voidOverFlowInt0(void (*Local_ptr)(void))
{
	ptr_OverFlow=Local_ptr;
}
/***************************************/

extern u16 Timer_u16Count1mile(void)
{//here will calulate time off what is the time that take by calulate number of
	//Local_u16TotalTime and know how much time it take?
	u16 Local_u16ValueThatReturn=0;
	if(TCNT0 >= (u8)(Timer_u16TimerCounter)+1)//Timer_u16TimerCounter)//1 mile
	{//(u8)(Timer_u16TimerCounter)+1 3mlt u8 +1 3shan hwa ksr w ana msh hinf3 a2arn bksr
		//+1 3shan ygeb elrkm elkber 3la tol y3ny 14.25 lw u8 bs hia5d 14 l2 zwd b2a 3shan tb2a 15
		Local_u16TotalTime++;
		Local_u16ValueThatReturn=Local_u16TotalTime;
		TCNT0=0;
	}
	else;
	return Local_u16ValueThatReturn;
//when prescaler= 8
//	if (tot_overflow >= 1960)  // 500 mile
//			{
//				if (TCNT0 >= 200)
//				{
//					PORTA^=0xff;
//					Timer_u16ResetTotalTime();
//					Timer_u16ResetCounter();
//					tot_overflow=0;
//				}
//			}
}
/***************************************/

extern void Timer_u16ResetTotalTime(void)
{
	Local_u16TotalTime=0;
}
/***************************************/

extern void Timer_u16ResetCounter(void)
{
	TCNT0=0;
}
/***************************************/

extern u8 Timer_u16GetTCNT0(void)
{
	return TCNT0;
}

/***************************************/
extern void ExtInt_EnableGlobalInt(void)
{
	__asm__ __volatile__("sei");
}
/***************************************/
extern void ExtInt_DisableGlobalInt(void)
{
	__asm__ __volatile__("cli");
}

/***************************************/
extern u8 Timer_u16NumberOfOverFlowInMileSec(f32 Copy_f32PtrRequiredTimeMileSec)
{
	u8 Local_u8Status;
	static u8 Local_u8TCNT0Value=0;
	static u16 Local_u16CounterOverFlow=0;
	static f32 Local_f32NumberOfOverFlow=0;
	f32 Local_f32WithOutFloatNumber,Local_f32SubtractNumber;

	if(Local_u16CounterOverFlow==0)//first time only will enter
	{
		/*Comment: calculate number of overflow*/
		Local_f32NumberOfOverFlow=Copy_f32PtrRequiredTimeMileSec/Timer_f32TimeOverFlowTimer0;//500/65.536=7.629time
		/*Comment: calculate Number of time in mile without float number   */
		Local_f32WithOutFloatNumber=(u16)Local_f32NumberOfOverFlow * Timer_f32TimeOverFlowTimer0;//7*65.536=458.752ms
		/*Comment: calculate number Remain Ticks by subtract*/
		Local_f32SubtractNumber=Copy_f32PtrRequiredTimeMileSec-Local_f32NumberOfOverFlow;//500-458.752=41.248
		/*Comment: calculate Value Of TCNT0*/
		Local_u8TCNT0Value=(u8)(Local_f32SubtractNumber / Timer_f32OneTickTimer0);//41.248/.256
		//TCNT0=Local_u8TCNT0Value;
	}
	else;
	/*Comment: Increment Overflow counter*/
	Local_u16CounterOverFlow++;
	/*Comment: if Overflow counter reached exactly number*/
	if(Local_u16CounterOverFlow >= (u16)Local_f32NumberOfOverFlow+1)//7
	{
		if(Local_u8TCNT0Value==0)/*dh hi5sh fy shrt ely 2ablo w b3dha msh hi5sh hna
		hilainy 7tit 2imh ll TCNT0 3shan y3ml overflow w ygy hna tany w y2om 2ail ok ana wslt ll2imh overflow */
		{
			Local_u8Status=Timer_u8ReachRequiredOverFlowNumber;
			Local_u16CounterOverFlow=0;
			TCNT0=0;
		}
		else;
		TCNT0=(Timer_u8MaxTimerZeroTick-1)-(Local_u8TCNT0Value+1);
		Local_u8TCNT0Value=0;
	}
	else
	{
		Local_u8Status=Timer_u8NotYetReachToOverFlowNumber;
	}
	return Local_u8Status;
}

