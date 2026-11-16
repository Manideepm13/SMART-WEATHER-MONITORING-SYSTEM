#include "WIFI.h"
#include "STM32F401RBT6.h"
#include "GPIO.h"
#include "SYSTICKTIMER.h"
//#include "LCD.c"
#include "LCD.h"
#include <stdio.h>
#include "ADC.h"
#include "I2C.h"
#include<string.h>
int display();

void WIFI_Init()
{
	
	//UART INITIALIZATION
	RCC->AHB1ENR |=(1<<2);//CLOCK FOR GPIO C 
	RCC->APB2ENR |=(1<<5);//CLOCK FOR UART6
	
	sys_tick_init();
	//UART CONFIGURATION	
	GPIOC->MODER &=~(3<<12);//ALTERNATE MODE FOR THE PIN 6
	GPIOC->MODER |=(2<<12);//ALTERNATE MODE FOR THE PIN 6
	
	GPIOC->MODER &=~(3<<14);//ALTERNATE MODE FOR THE PIN 7
	GPIOC->MODER |=(2<<14);
	
	 UART6->BRR |=0X8A;//BAUD RATE
	
	NVIC->ISER[2]|=1<<7; //INTERRUPT FOR 
	
	GPIOC->AFR[0] &= ~(0xF << 24);
  GPIOC->AFR[0] |=  (0x8 << 24);//PC6 AS UART6 TX
	
	GPIOC->AFR[0] &= ~(0xF << 28);
  GPIOC->AFR[0]|=  (0x8 << 28);//PC7 AS UART6 RX
	
	UART6->CR1|=0X1<<5;//RXNIE ENABLE
	
	UART6->CR1|=(0X1<<13);//USART enable
	UART6->CR1|=((0X1<<2)|(1<<3));//USART TX AND RX ENABLE
	KM_LCD_Pin_Init(LCD_PORT,LCD_D4,LCD_D5,LCD_D6,LCD_D7,LCD_RS,LCD_RW,LCD_EN);//port b pins configured as output
	KM_LCD_Init();//lcd initilaization
	KM_LCD_Write_Str("SMART WEATHER");
	KM_LCD_Write_Cmd(0xC0);
	KM_LCD_Write_Str("MONITORING");
	
}


volatile int i=0,K=0,j=0,X=0,g;
extern char strr;
//extern char data;
char  str[1000],res[1000],fet[10],temp[50];

//UART6 HANDLER

void USART6_IRQHandler()
{
		if((UART6->SR & (1<<5)))
		{
				res[j]=UART6->DR;
				j++;
				res[j]='\0';
		}		
}



//OUTSTRING FUNCTION
void USART_OUT_String( char *str)
{
		for(i=0;str[i];i++)
	{
		{
		while(!(UART6->SR & (1<<7)));
	
		UART6->DR=str[i];
		}
	}
	 
}


//MY STRSTR FUNCTION
int my_strstr(char STR[],char SUB[])
{
	for(i=0;STR[i];i++)
	{
		K=0;
		if(STR[i]==SUB[K])
		{
			while(STR[i+K]==SUB[K] && SUB[K] && STR[i])
			{
				
				K++;
			}
			if(SUB[K]=='\0')
			{
				return 1;
			}
		}
	}
	return 0;
}

static unsigned char init=1;

//OPERATION FUNCTION
void RUN()
{
		while(init)
			{
				
				if(init==1)
				{
					j=0;

					memset(res,0,1000);
					USART_OUT_String("AT\r\n");
					KM_Mdelay_IT(100);
					
					if(my_strstr(res,"OK")==1)
					{
						init=2;
						KM_LCD_Write_Cmd(0x01);
						KM_LCD_Write_Str("AT DONE");
					}
				}
					
					
			
				if(init==2)
				{
		       	j=0;

					  memset(res,0,1000);
		        USART_OUT_String("AT+RST\r\n");
		        KM_Mdelay_IT(100);
		        if(my_strstr(res,"OK")==1)
			    	{
			    		init=3;
			    		KM_LCD_Write_Cmd(0x01);
		        	KM_LCD_Write_Str("RESET DONE");
			    	}
					}
         
			
			
			if(init==3)
			{
			     j=0;

						memset(res,0,1000);
			     USART_OUT_String("AT+CWMODE=3\r\n");
			     KM_Mdelay_IT(500);
			     if(my_strstr(res,"OK")==1)
			     {
			     	init=4;
			     KM_LCD_Write_Cmd(0x01);
			     KM_LCD_Write_Str("WIFI MODE SET");
			     }
		  }
			
			
			if(init==4)
			{
		    		j=0;

						memset(res,0,1000);
		       	USART_OUT_String("AT+CWJAP=\"KMLearnX-2.4G\",\"9963111084\"\r\n");
		    	  KM_Mdelay_IT(10000);
		    	  if(my_strstr(res,"WIFI CONNECTED")==1)
		    	  {
		    		 init=5;
		    		 KM_LCD_Write_Cmd(0x01);
		    		 KM_LCD_Write_Str("WIFI-CONNECTED");
			      }
		  }
			
			
			
			if(init==5)
			{
					j=0;

				USART_OUT_String("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
			KM_Mdelay_IT(4000);
			if(my_strstr(res,"OK")==1 || (my_strstr(res,"ALREADY CONNECTED"))==1)
			{
			
				KM_LCD_Write_Cmd(0x01);
				KM_LCD_Write_Str("SERVER CONNECTED");	
				init=6;
			}
		}
			

			if(init==6)
			{
		   		j=0;

		   	  USART_OUT_String("AT+CIPSEND=37\r\n");
		   	  KM_Mdelay_IT(1000);
		   	 if(my_strstr(res,">")==1)
		   	 {
		   		init=0;
		   		KM_LCD_Write_Cmd(0x01);
		   		KM_LCD_Write_Str("READY TO SEND");
		   		KM_LCD_Write_Cmd(0x01);
			    }
				 
			}
		}
		
}
			
static unsigned char test=1;			
void send()
{
			//display();
			if(test==1)	
			{				
			    	j=0;

						memset(res,0,500);
			    	X=ADCC();
			    	sprintf(temp,"GET /page.php?temp=%d&hum=40&dev=21\r\n",X);
			    	USART_OUT_String(temp);
			    	display();
			      KM_Mdelay_IT(900);
			    	display();
			      if(my_strstr(res,"OK")==1)
			      {	
			      sprintf(fet,"TEMP=%d",X);
			      KM_LCD_Write_Str(fet);
			      test=2;
			      }
						
	   	}
			
			display();
			
				if(test==2)
				{
		      	j=0;
		      	memset(res,0,500);
		      	USART_OUT_String("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		      	display();
		      	KM_Mdelay_IT(500);
		      	if((my_strstr(res,"CONNECT"))==1 || my_strstr(res,"ALREADY CONNECTED")==1)
						{
								test=3;
						}
				}
		      	
			display();

			if(test==3)
			{
		    		j=0;
		    		memset(res,0,500);
		      	USART_OUT_String("AT+CIPSEND=37\r\n");
		    		display();
		    	  KM_Mdelay_IT(500);
		    	  if( my_strstr(res,">")==1)
		    	  {
		    		 test=1;
		    	  }
						else
				 {
					 test=2;
				 }
		}
			display();
	}


