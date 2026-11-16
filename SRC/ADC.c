#include "ADC.h"
#include "STM32F401RBT6.h"
#include "GPIO.h"
int M=0,m=0;
void ADC_Init()
{
	//ADC INITIALIZATION	
	RCC->APB2ENR|=(1<<8);  //ENABLE CLOCK FOR ADC
	
	
	//ADC CONFIGURATION
	GPIOC->MODER&=~(3); //CONFIGURE PC0 AS ANALOG
	GPIOC->MODER|=(3<<0); 
	ADC->SMPR1|=7;
	
	ADC->SQR3|=0XA; //PCO ---> ADC_CH10
	
	//ADC_CR2 |=0X1<<1; //SET CONTINUOUS MODE
	ADC->CR2 |=0X1; //ON the ADC
	

}


int ADCC()
{
		ADC->CR2 |=0X1<<30; //SOFTWARE START -->START CONVERSION
		while(!(ADC->SR&(1<<1)));
		m=ADC->DR;
	  M=(m*0.0008f)*100;
		return M;
}
	