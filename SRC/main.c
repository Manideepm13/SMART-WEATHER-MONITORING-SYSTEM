#include "I2C.h"
#include "SYSTICKTIMER.h"
#include "LCD.h"
#include "GPIO.h"
#include "WIFI.h"
#include "ADC.h"
#include<stdio.h>
unsigned char data[30];
char strr[40];
unsigned char InData[10]={0x00,0x57,0x68,0x04,0x10,0x09,0x26};

int display()
{
	KM_I2C_Mem_Read(0x68,0x00,1,data,7);
	KM_LCD_Write_Cmd(0x80);
	sprintf(strr,"%02x:%02x:%02x %s",data[2]&0x1f,data[1],data[0],data[2]&1<<5?"PM":"AM");
	KM_LCD_Write_Str(strr);
	KM_LCD_Write_Cmd(0xC0);
	sprintf(strr,"%02x/%02x/%02x ",data[4]&0x3f,data[5]&0x1f,data[6]);
	KM_LCD_Write_Str(strr);
	return 1;
	
}


int main()
{
	sys_tick_init();
	KM_I2C1_Init();
	KM_I2C1_Config();
	
	WIFI_Init();
	ADC_Init();
	 
	
	
	KM_LCD_Pin_Init(LCD_PORT,LCD_D4,LCD_D5,LCD_D6,LCD_D7,LCD_RS,LCD_RW,LCD_EN);//port b pins configured as output
	KM_LCD_Init();//lcd initilaization
	
	RUN();
	
	//KM_I2C_Mem_Write(0x68,00,1,InData,7);
	
	while(1)
	{
	display();
	send();
	
  }
}

