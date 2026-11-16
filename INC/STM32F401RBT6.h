#include<stdint.h>


#define GPIOA ((GPIO_TypeDef *)0x40020000)
#define GPIOB ((GPIO_TypeDef *)0x40020400)
#define GPIOC ((GPIO_TypeDef *)0x40020800)
#define GPIOH ((GPIO_TypeDef *)0x40021C00)

#define RCC    ((RCC_TypeDef *)0x40023800)
#define STK    ((SysTick_Type *)0xE000E010)
#define ADC    ((ADC_TypeDef *)0x40012000)
#define NVIC    ((NVIC_Type *)0xE000E100)

#define UART1   ((USART_TypeDef*)0X40011000)
#define UART2    ((USART_TypeDef *)0X40004400)
#define UART6   ((USART_TypeDef *)0x40011400)


//////////////////////////GPIO///////////////////////////////////

typedef struct
{
  volatile uint32_t MODER;    
  volatile uint32_t OTYPER;   
  volatile uint32_t OSPEEDR;  
  volatile uint32_t PUPDR;    
  volatile uint32_t IDR;

	
  volatile uint32_t ODR;      
  volatile uint32_t BSRR;     
  volatile uint32_t LCKR;     
  volatile uint32_t AFR[2];   
} GPIO_TypeDef;

/////////////////////////////RCC/////////////////////////////////
typedef struct
{
  volatile uint32_t CR;       
  volatile uint32_t PLLCFGR;  
  volatile uint32_t CFGR;     
  volatile uint32_t CIR;      
  volatile uint32_t AHB1RSTR; 
  volatile uint32_t AHB2RSTR; 
  volatile uint32_t AHB3RSTR; 
  uint32_t      RESERVED0;    
  volatile uint32_t APB1RSTR; 
  volatile uint32_t APB2RSTR; 
  uint32_t      RESERVED1[2]; 
 volatile uint32_t AHB1ENR;   
 volatile uint32_t AHB2ENR;   
 volatile uint32_t AHB3ENR;   
  uint32_t      RESERVED2;    
  volatile uint32_t APB1ENR;  
  volatile uint32_t APB2ENR;  
  uint32_t      RESERVED3[2]; 
  volatile uint32_t AHB1LPENR;
  volatile uint32_t AHB2LPENR;
  volatile uint32_t AHB3LPENR;
  uint32_t      RESERVED4;    
  volatile uint32_t APB1LPENR;
  volatile uint32_t APB2LPENR;
  uint32_t      RESERVED5[2]; 
  volatile uint32_t BDCR;     
  volatile uint32_t CSR;      
  uint32_t      RESERVED6[2]; 
 volatile uint32_t SSCGR;     
 volatile uint32_t PLLI2SCFGR;
  uint32_t      RESERVED7[1]; 
  volatile int32_t DCKCFGR;   
} RCC_TypeDef;

//////////////////////SYSTIC///////////////////////////
typedef struct
{
  volatile uint32_t CTRL;                  
  volatile uint32_t LOAD;                  
  volatile uint32_t VAL;                   
  volatile uint32_t CALIB;                 
} SysTick_Type;

///////////////////////ADC////////////////////////////

typedef struct
{
  volatile uint32_t SR;     
  volatile uint32_t CR1;    
  volatile uint32_t CR2;    
  volatile uint32_t SMPR1;  
  volatile uint32_t SMPR2;  
  volatile uint32_t JOFR1;  
  volatile uint32_t JOFR2;  
  volatile uint32_t JOFR3;  
  volatile uint32_t JOFR4;  
  volatile uint32_t HTR;    
  volatile uint32_t LTR;    
  volatile uint32_t SQR1;   
  volatile uint32_t SQR2;   
  volatile uint32_t SQR3;   
  volatile uint32_t JSQR;   
  volatile uint32_t JDR1;   
  volatile uint32_t JDR2;   
  volatile uint32_t JDR3;   
  volatile uint32_t JDR4;   
  volatile uint32_t DR;     
} ADC_TypeDef;

/////////////////////////UART////////////////////////

typedef struct
{
 volatile uint32_t SR;        
 volatile uint32_t DR;        
 volatile uint32_t BRR;       
 volatile uint32_t CR1;       
 volatile uint32_t CR2;       
 volatile uint32_t CR3;       
 volatile uint32_t GTPR;      
} USART_TypeDef;


//////////////////////////NVIC///////////////////////

typedef struct
{
 volatile uint32_t ISER[8U];              
 volatile uint32_t RESERVED0[24U];
 volatile uint32_t ICER[8U];              
 volatile uint32_t RSERVED1[24U];
 volatile uint32_t ISPR[8U];              
 volatile uint32_t RESERVED2[24U];
 volatile uint32_t ICPR[8U];              
 volatile uint32_t RESERVED3[24U];
 volatile uint32_t IABR[8U];              
 volatile uint32_t RESERVED4[56U];
 volatile uint8_t  IP[240U];              
 volatile uint32_t RESERVED5[644U];
 volatile uint32_t STIR;                  
}  NVIC_Type;
