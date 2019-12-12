#include<reg51.h>
#include<string.h>
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
u8 i=0,c[10]={0}, ps[5]={0};
sbit led_flag=P1^0;// for serial


void UART_Init(void)
{
	SCON = 0X50;//UART_mode_1
	TMOD = 0X20;//TMOD_mode_3
	TH1= -3;//9600 Baudrate
	TR1=1;
}

void ISR_INT1(void) interrupt 1
{
	/*disp on hyper terminal*/
	
}
void  ISR_SER(void) interrupt 4
{
	led_flag=0;// for serial
	RI=0;
	c[i]=SBUF;
  if((c[i]!='$')&&(i<9))
	   i++;
	else
	{
		c[i]='\0';
		i=0;
		led_flag=1;
	}
}
