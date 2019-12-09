#include "types.h"
#include "i2c_defines.h"
#include "i2c.h"

void setTime(u8 *time)
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
    static u8 t[0]="00:00:00";
    u8 hrs,mins,secs;
  
   hrs = i2cDevRead(0xd0,0x02);
   mins = i2cDevRead(0xd0,0x01);
   secs= i2cDevRead(0xd0,0x00);

   t[0] = ((hrs/16)+48);
   t[1] = ()
}