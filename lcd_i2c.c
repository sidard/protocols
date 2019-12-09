/*lcd interfacing with i2c file*/
#include "i2c.h"
#include <reg51.h>
#include "String.h"
#include "delay.h"
#include "lcd.h"
#include "types.h"
sbit led = P1^0;
main()
{
     u8 i,t[4],cnt=0;
	   u8 d[4]="sid";
	   LCD_Init();
	   LCD_cmd(0x80);
	   
	   for(i=0;i<3;i++)
         i2cDevWrite(0xA0,0x00+i,d[i]);
	   for(i=0;i<3;i++)
        t[i] = i2cDevRead(0xA0,0x00+i);
	  t[i]='\0';
    if((Str_cmp(d,t))==0){
		LCD_str(t);
		while(1);
	 }
	 while(1);
}





