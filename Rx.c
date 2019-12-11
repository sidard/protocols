#include<reg51.h>
#include"lcd.h"
#include"delay.h"

void UART_Init(void);
char UART_Rx(void);
void UART_Tx(char);
main()
{
	char ch=0;
	UART_Init();
	LCD_Init();
	LCD_cmd(0x80);
	while(1)
	{
		ch=UART_Rx();
		LCD_char(ch);
		UART_Tx(ch);
	}
	
}
void UART_Tx(char ch)
{
	SBUF = ch;
	while(TI==0);
	TI=0;
}
void UART_Init(void)
{
	SCON = 0X50;
	TMOD = 0X20;
	TH1 = -3;//9600 BAUDRATE
	TR1 =1;
}
char UART_Rx(void)
{
	
	while(RI==0);
	RI=0;
	return(SBUF);
}
