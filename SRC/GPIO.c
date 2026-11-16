#include "STM32F401RBT6.h"
#include "GPIO.h"
void KM_GPIO_Init(int port)
{
	switch(port)
	{
		case GPIOAA:RCC->AHB1ENR|=(1<<GPIOAA);
			break;
		case GPIOBB:RCC->AHB1ENR|=(1<<GPIOBB);
			break;
		case GPIOCC:RCC->AHB1ENR|=(1<<GPIOCC);
			break;
	}
}



void KM_GPIO_Pin_Mode(int port,int pin,int mode)
{
	switch(port)
	{
		
		//PORT A
		case GPIOAA:switch(mode)
		{
			case OUT:
				(GPIOA)->MODER &=~(0x03<<(pin*2));
				GPIOA->MODER |=(0x01<<pin*2);
				break;
			
			case IN:
				GPIOA->MODER&=~(0x03<<pin*2);
				break;
			
			case ALT:
				GPIOA->MODER&=~(0x03<<pin*2);
				GPIOA->MODER|=(0x02<<pin*2);
				break;
			
			case ANL:
				GPIOA->MODER&=~(0x03<<pin*2);
				GPIOA->MODER|=(0x03<<pin*2);
				break;
			
			case PULL_UP:
				GPIOA->PUPDR&=~(0x03<<pin*2);
				GPIOA->PUPDR|=(0x01<<pin*2);
				break;
			
			case PULL_DOWN:
				GPIOA->PUPDR&=~(0x03<<pin*2);
				GPIOA->PUPDR|=(0x02<<pin*2);
				break;
		}
		break;
		
		//PORT B
		case GPIOBB:switch(mode)
		{
			case OUT:
				GPIOB->MODER&=~(0x03<<pin*2);
				GPIOB->MODER|=(0x01<<pin*2);
				break;
			
			case IN:
				GPIOB->MODER&=~(0x03<<pin*2);
				break;
			
			case ALT:
				GPIOB->MODER&=~(0x03<<pin*2);
				GPIOB->MODER|=(0x02<<pin*2);
				break;
			
			case ANL:
				GPIOB->MODER&=~(0x03<<pin*2);
				GPIOB->MODER|=(0x03<<pin*2);
				break;
			
			case PULL_UP:
				GPIOB->PUPDR&=~(0x03<<pin*2);
				GPIOB->PUPDR|=(0x01<<pin*2);
				break;
			
			case PULL_DOWN:
				GPIOB->PUPDR&=~(0x03<<pin*2);
				GPIOB->PUPDR|=(0x02<<pin*2);
				break;
		}
		break;
		
		//PORT C
		case GPIOCC:switch(mode)
		{
			case OUT:
				GPIOC->MODER&=~(0x03<<pin*2);
				GPIOC->MODER|=(0x01<<pin*2);
				break;
			
			case IN:
				GPIOC->MODER&=~(0x03<<pin*2);
				break;
			
			case ALT:
				GPIOC->MODER&=~(0x03<<pin*2);
				GPIOC->MODER|=(0x02<<pin*2);
				break;
			
			case ANL:
				GPIOC->MODER&=~(0x03<<pin*2);
				GPIOC->MODER|=(0x03<<pin*2);
				break;
			
			case PULL_UP:
				GPIOC->PUPDR&=~(0x03<<pin*2);
				GPIOC->PUPDR|=(0x01<<pin*2);
				break;
			
			case PULL_DOWN:
				GPIOC->PUPDR&=~(0x03<<pin*2);
				GPIOC->PUPDR|=(0x02<<pin*2);
				break;
		}
	}
}
	

void KM_GPIO_Write_Pin(int port,int pin,int data)
{
	switch(port)
	{
		//PORT A
		case GPIOAA:switch(data)
		{
			case SET:
				GPIOA->ODR|=(1<<pin);
				break;
			
			case RESET:
				GPIOA->ODR&=~(1<<pin);
				break;
		}
		break;
			
		//PORT B
		case GPIOBB:switch(data)
		{
			case SET:
				GPIOB->ODR|=(1<<pin);
				break;
			
			case RESET:
				GPIOB->ODR&=~(1<<pin);
				break;
		}
		break;
		
		//PORT B
		case GPIOCC:switch(data)
		{
			case SET:
				GPIOC->ODR|=(0x1<<pin);
				break;
			
			case RESET:
				GPIOC->ODR&=~(0x1<<pin);
				break;
		}
	}
}


void KM_GPIO_Toggle(int port,int pin)
{
	switch(port)
	{
		case GPIOAA:
			GPIOA->ODR ^=(0x1<<pin);
			break;
		
		case GPIOBB:
			GPIOB->ODR ^=(0x1<<pin);
			break;
		
		case GPIOCC:
			GPIOC->ODR ^=(0x1<<pin);
			break;
	}
}
		

int KM_GPIO_Read_Pin(int port,int pin)
{
	switch(port)
	{
		case GPIOAA:
			return GPIOA->IDR &(0x1<<pin);

		
		case GPIOBB:
			return GPIOB->IDR &(0x1<<pin);
		
		
		case GPIOCC:
			return GPIOC->IDR &(0x1<<pin);
	}
	return 0;
}

	
	

			
