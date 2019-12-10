#include<reg51.h>
#include<string.h>
#include"lcd.h"
#include"delay.h"
#include"types.h"
#include"ds1307.h"
sbit led = P1^0;

main()
{
    u8 i, day,rTime[9],caldr[9];
	s8 days[][5]={"Sun","Mon","Tues","Wed","Thurs","Fri","Sat"};
    LCD_Init();
	/*set Time*/
    setTime("23:59:59");
  /*set Day*/  
	setDay(2);
	/*set Calendar*/
	setCalender("11/12/19");
	  while(1){		 
				strcpy(rTime,getTime());
			  LCD_cmd(0x80);
			  LCD_str(rTime); 
				
			  day=getDay();
			  for(i=0;i<7;i++)
        {
  			if(day==(i+1))
				{
					LCD_cmd(0x88);
					LCD_char('(');
					LCD_str(days[i]);LCD_char(')');
				}
			  }
		    
			
				strcpy(caldr,getCalender());
				LCD_cmd(0xc0);
			  LCD_str(caldr); 
				delay_ms(1000);
				
		  }		
}
