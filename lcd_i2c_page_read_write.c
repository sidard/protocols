/*lcd interfacing with i2c file*/
#include "i2c.h"
#include <reg51.h>
#include "String.h"
#include "delay.h"
//#include "lcd.h"
#include "types.h"
sbit led = P1^0;
main()
{
     u8 s1[4];
	   u8 s[4]="sid";
     /*By Page Write method**/

i2cDevPageWrite(0xA0,0x00,s,4);

	   /*for(i=0;i<3;i++)
         i2cDevWrite(0xA0,0x00+i,s[i]);
	   for(i=0;i<3;i++)
        s1[i] = i2cDevRead(0xA0,0x00+i);
	  s1[i]='\0';
	*/
     /*By Page Read method**/
i2cDevPageRead(0xA0,0x00,s1,3);

	if(Str_cmp(s,s1)==0)
    { 
			 while(1){
	      led=~led;
			  delay_ms(1000);
			 }
    }
		while(1);
}





