#define LCD_PORT GPIOBB
#define LCD_D4 0
#define LCD_D5 1
#define LCD_D6 2
#define LCD_D7 3
#define LCD_RS 4
#define LCD_RW 5
#define LCD_EN 8

void KM_LCD_Pin_Init(int port,int lcd_d4,int lcd_d5,int lcd_d6,int lcd_d7,int lcd_rs,int lcd_rw,int lcd_en);
void KM_LCD_Init(void);
void KM_LCD_Write_Data(unsigned char data);
void KM_LCD_Write_Cmd(unsigned char data);
static void write_low_nibble(unsigned char data);
static void write_high_nibble(unsigned char data);
void KM_LCD_Write_Str(char str[]);



	