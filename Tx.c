#include<reg51.h>
#include"lcd.h"
#include"delay.h"
void UART_Init(void);
void UART_Tx(char);
main()
{
	char ch='A';
	UART_Init();
	LCD_Init();
	LCD_cmd(0x80);
	LCD_str("Trasmission");
	while(1)
	{
		UART_Tx(ch);	
	}
	
}
void UART_Init(void)
{
	SCON = 0X50;
	TMOD = 0X20;
	TH1 = -3;//9600 BAUDRATE
	TR1 =1;
}
void UART_Tx(char ch)
{
	SBUF = ch;
	while(TI==0);
	TI=0;
}
