#include<reg51.h>
#include"i2c.h"
#include"lcd.h"
#include"delay.h"
#include"keypad.h"
void intToAscii(u16);

main()
{
	u8 ch,str[8]="sidarrd",strRead[8]={0};
  LCD_Init();
	LCD_cmd(0x80);
	LCD_str("siddeshwar");
	while(1){
	
	/*LCD_cmd(0xc0);
	intToAscii(12345);
	*/
	
	Row_Init();
	while(ColStatus());
	ch=KeyScan();
	LCD_cmd(0xc0);
	LCD_char(ch+48);
	
	delay_ms(2000);
	i2cDevPageWrite(0xa0,0x00,str,8);
	i2cDevPageRead(0xa0,0x00,strRead,7);
  LCD_cmd(0x80);
	LCD_str("eeprom....");
	LCD_cmd(0xc0);
	LCD_str(strRead);
	}
}

void intToAscii(u16 i_data)
{
	u16 temp,arr[11],i=0;
	while(i_data)
	{
		temp = i_data;
		arr[i++] = temp%10 + 48;
		//cnt++;
		i_data/=10;
	}
	i--;
	do{
			LCD_char(arr[i]);
	}while(i--);
}