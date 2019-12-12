#include<reg51.h>
#include"i2c.h"
#include"lcd.h"
#include"delay.h"
#include"keypad.h"
#include"inter.h"
#include"types.h"
u8 pswd[5]={0};
void ISR_INT0(void) interrupt 0
{
	u8 ch=0,i=0;
	LCD_cmd(0x80);
	LCD_str("Enter pswd.....");
	LCD_cmd(0xc0);
	while(i!=5)
	{
     Row_Init();
	   while(ColStatus());
	   ch=KeyScan();

     if((ch>=0)&&(ch<10))
     {
			 pswd[i]=ch;
			 LCD_char(pswd[i]+48);
			 LCD_cmd(0xc0+i);
			 LCD_char('*'); 
			 i++;
		 }			 
	}
	pswd[5]='\0';
}
main()
{
	UART_Init();
  LCD_Init();
	
	EA=1;
	ES=1;  // interpt for UART
	EX0=1;  // interpt for int0
	IT0=1;
	EX1=1;  //interpt for int1
	LCD_cmd(0x80);
	
	while(1)
  { 
		LCD_cmd(0x80);
		LCD_str("ADD ITEMS......");
		LCD_cmd(0xc0);
		LCD_str("      ");
//		while(1);
	}
	}

