#include "STM32F401RBT6.h"
int display();
int count=0;
void sys_tick_init(void)
{
	STK->CTRL|=0x07;
}

void SysTick_Handler()
{
	count++;
}

void KM_Delay_ms(int n)
{
	STK->LOAD=16000*n-1;
	STK->VAL=0;
	while(!(STK->CTRL&(1<<16)));
}

void KM_udelay(int n)
{
	STK->LOAD=16*n-1;
	STK->VAL=0;
	while(!(STK->CTRL&(1<<16)));
}

void KM_Mdelay_IT(int n)
{
	count=0;
	STK->LOAD=16000-1;
	STK->VAL=0;
	while(count<n);
	
}


