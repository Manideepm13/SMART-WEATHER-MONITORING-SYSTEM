//**************RAAYAN MINI PERIPHERALS***************

#define RED_LED 13
#define GREEN_LED 14
#define BUZZER 12
#define SW_ENT 10
#define SW_UP 8
#define SW_DW 9

//*********************GPIO PORTS*********************

#define GPIOAA 0
#define GPIOBB 1
#define GPIOCC 2

//************************MODES***********************

#define IN 0
#define OUT 1
#define ALT 2
#define ANL 3

//*************************DATA************************

#define SET 1
#define RESET 0

#define PULL_UP 4
#define PULL_DOWN 5

//**************GPIO FUNCTION DELCARATIONS*************

void KM_GPIO_Init(int port);
void KM_GPIO_Pin_Mode(int port,int pin,int mode);
void KM_GPIO_Write_Pin(int port,int pin,int data);
void KM_GPIO_Toggle(int port,int pin);
int KM_GPIO_Read_Pin(int port,int pin);

