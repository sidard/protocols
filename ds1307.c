#include "types.h"
#include "i2c_defines.h"
#include "i2c.h"

void setTime(u8 *t)
{
       u8 hrs,mins,secs;
      hrs = ((t[0]&0x0f)<<4) | (t[1]&0x0f);
      mins= ((t[3]&0x0f)<<4) | (t[4]&0x0f);
      secs= ((t[6]&0x0f)<<4) | (t[7]&0x0f);

     i2cDevWrite(0xd0,0x02,hrs);
     i2cDevWrite(0xd0,0x01,mins);
     i2cDevWrite(0xd0,0x00,secs);

}

u8 *getTime(void)
{
    static u8 t[9]="00:00:00";
    u8 hrs,mins,secs;
  
   hrs = i2cDevRead(0xd0,0x02);
   mins = i2cDevRead(0xd0,0x01);
   secs= i2cDevRead(0xd0,0x00);
  
	 t[0] = ((hrs/16)+48);
		 t[1] = ((hrs%16)+48);
	 t[3] = ((mins/16)+48);
	 t[4] = ((mins%16)+48);
	 t[6] =((secs/16)+48);
	 t[7] =((secs%16)+48);
	return t;
}
/*void setCalender(u8*);    "11/12/2019"
u8* getCalender(void);
void setDate(u8);
void setMonth(u8);
void setYear(u8);
u8 getDate(void);
u8 getMonth(void);
u8 getYear(void);
*/
void setDay(u8 day)
{
	 i2cDevWrite(0xd0,0x03,day);
}

u8 getDay(void)
{
	static u8 day=1;/*default value must be always set to 1(i.e. Sunday)*/
	day= i2cDevRead(0xd0,0x03);
	return day;
}
void  setDate(u8 Date)
{
 i2cDevWrite(0xd0,0x04,Date);
}	

void setMonth(u8 Month)
{
  i2cDevWrite(0xd0,0x05,Month);
}
	
void setYear(u8 Year)
{
  i2cDevWrite(0xd0,0x06,Year);
}
void setCalender(u8 *st)//    "11/12/19"
{
	 u8 Date=01,Month=01,Year=0000;
	 Date = ((st[0]&0x0f)<<4)|(st[1]&0x0f);
	 setDate(Date); 
	 Month = ((st[3]&0x0f)<<4)|(st[4]&0x0f);
	 setMonth(Month);
	 Year= ((st[6]&0x0f)<<4)|(st[7]&0x0f);
   setYear(Year);

}

u8 getDate(void)
{
	u8 Date=01;
	Date=i2cDevRead(0xd0,0x04);
  return Date;
}
u8 getMonth(void)
{
	u8 Month=01;
	Month=i2cDevRead(0xd0,0x05);
  return Month;
}u8 getYear(void)
{
	u8 Year=01;
	Year=i2cDevRead(0xd0,0x06);
  return Year;
}

u8* getCalender(void)
{
	u8 str[9]= "00/00/00";
 	
  str[0]= getDate()/10 +48 ;
	str[1]= getDate()%10 +48;
	str[3]= getMonth()/10 +48;
  str[4]=getMonth()%10 + 48;
	str[6]=getYear()/10 + 48;
	str[7]=getYear()%10 + 48;
	return str;
}
