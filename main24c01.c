#include "i2c.h"
#include <reg51.h>
#include "delay.h"

 sbit led = P1^0;
 main()
{
      u8 t;
     i2cDevWrite(0xA0,0x00,'A');
     t = i2cDevRead(0xA0,0x00);
   if(t=='A')
   {
    while(1)
    {
		 delay_ms(200);
       led=~led;
    }
	 }
   while(1);
}