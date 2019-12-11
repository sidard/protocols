#include"lcd.h"
#include"delay.h"
main()
{
	LCD_Init();
	LCD_cmd(0x80);
	LCD_char('A');
	LCD_cmd(0x88);
	LCD_str("INDIA");
	store_font_CGRAM();//calling the cgram which is storing user defined graphic symbols
	LCD_cmd(0x86);
	LCD_char(0);
	while(1);
}
