#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"

#define lcd P0

sbit rs= P3^0;
sbit rw= P3^1;
sbit en= P3^2;
void LCD_Init(void)
{
	delay_ms(16);
	LCD_cmd(0x30);
	
	delay_ms(6);
	LCD_cmd(0x30);
	
	delay_ms(1);
	LCD_cmd(0x30);
	delay_ms(1);
	
	LCD_cmd(0x38);
	LCD_cmd(0x10);
	LCD_cmd(0x01);
	LCD_cmd(0x04);
	LCD_cmd(0x0f);
}
void LCD_disp(s8 val)
{
	rw=0;
	lcd=val;
	en=1;
	en=0;
	delay_ms(1);
}

void LCD_cmd(s8 cmd)
{
	rs=0;
	LCD_disp(cmd);
}

void LCD_char(s8 ch)
{
	rs=1;
	LCD_disp(ch);
}

void LCD_str(s8 *p)
{
	while(*p!=0)	
			LCD_char(*p++);
}

s8 code a[]={0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00};

void store_font_CGRAM(void)
{
	s8 i;
	LCD_cmd(0x40);
	for(i=0;i<8;i++)
		LCD_char(a[i]);
}
	