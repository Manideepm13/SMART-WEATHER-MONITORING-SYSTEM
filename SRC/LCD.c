#include "STM32F401RBT6.h"
#include "lcd.h"
#include "GPIO.h"

//1
void KM_LCD_Pin_Init(int port,int lcd_d4,int lcd_d5,int lcd_d6,int lcd_d7,int lcd_rs,int lcd_rw,int lcd_en)
{
	KM_GPIO_Init(port);
	KM_GPIO_Pin_Mode(port,lcd_d4,OUT);
	KM_GPIO_Pin_Mode(port,lcd_d5,OUT);
	KM_GPIO_Pin_Mode(port,lcd_d6,OUT);
	KM_GPIO_Pin_Mode(port,lcd_d7,OUT);
	KM_GPIO_Pin_Mode(port,lcd_rs,OUT);
	KM_GPIO_Pin_Mode(port,lcd_rw,OUT);
	KM_GPIO_Pin_Mode(port,lcd_en,OUT);
}


//2
void KM_LCD_Init(void)
{
	
	KM_Mdelay_IT(5);
	KM_LCD_Write_Cmd(0x33);
	KM_Mdelay_IT(1);
	KM_LCD_Write_Cmd(0x32);
	KM_LCD_Write_Cmd(0x0C);
	KM_LCD_Write_Cmd(0x01);
}

//3
void KM_LCD_Write_Data(unsigned char data)
{
	KM_GPIO_Write_Pin(LCD_PORT,LCD_RS,SET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_RW,RESET);
	write_high_nibble(data);
	write_low_nibble(data);
}

//4
void KM_LCD_Write_Cmd(unsigned char data)
{
	KM_GPIO_Write_Pin(LCD_PORT,LCD_RS,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_RW,RESET);
	write_high_nibble(data);
	write_low_nibble(data);
}

//5
static void write_high_nibble(unsigned char data)
{
	data&=0xF0;
	data>>=4;
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D4,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D5,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D6,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D7,RESET);
	
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D4,(data&(0x01)));
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D5,(data&(0x02))>>1);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D6,(data&(0x04))>>2);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D7,(data&(0x08))>>3);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_EN,SET);
	KM_Mdelay_IT(5);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_EN,RESET);
	
}

//6
static void write_low_nibble(unsigned char data)
{
	data&=0x0F;
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D4,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D5,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D6,RESET);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D7,RESET);
	
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D4,(data&(0x01)));
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D5,(data&(0x02))>>1);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D6,(data&(0x04))>>2);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_D7,(data&(0x08))>>3);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_EN,SET);
	KM_Mdelay_IT(5);
	KM_GPIO_Write_Pin(LCD_PORT,LCD_EN,RESET);
	
}
//7
void KM_LCD_Write_Str(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		 KM_LCD_Write_Data(str[i]);
	}
}
		




	









	




	