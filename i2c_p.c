	/*Contains definition of  i2c.h file*/
	#include "types.h"
	#include "delay.h"
	#include "i2c_defines.h"
  
	void i2cStart(void)
	{
	/*Start condition*/
		sda=1;
		scl=1;
		sda=0;
	}
	void i2cStop(void)
	{
	/*Stop condition*/
		                  scl=0;
											sda=0;
											scl=1;
											sda=1;
	}

	void i2cWrite(u8 dat)
	{
			 /*write data or  address from master to slave*/
		 u8 i;
		for(i=0;i<8;i++)
		{
			scl=0;
			sda=(dat>>(7-i))&1;   /*MSB first uptil LSB */
			scl=1;
		}//for loop ended
	}


	u8 i2cRead(void)
	{
			 u8 i,buff=0;
			 for(i=0;i<8;i++)
			 {
						scl=0;
						scl=1;
					 if(sda)
								buff |= (0x80>>i);     /*i2cRead */
				}//for loop ended
	 return buff;
	}

	void i2cAck(void)
	{
			 scl=0;
			 sda=1;
			 scl=1;
			 while(sda);  /*waiting for the slave to Acknowledge*/
	}

	void i2cNoAck(void)
	{
	 scl=0;
	 sda=1;
	 scl=1;
	}

	void i2cMasterAck(void)
	{
		 scl=0;
		 sda=0;
		 scl=1;
		 scl=0;
		 sda=1;
	}

	void i2cRestart(void)
	{
			scl=0;
		 sda=1;
			scl=1;
		sda=0;
	}
	/*End with i2c bus events communication*/

	/*i2c read & write communication from or to device*/
	void i2cDevWrite(u8 slave_addr, u8 buff_addr, u8 dat)
	{
				i2cStart();
			 i2cWrite(slave_addr);
			 i2cAck();
			 i2cWrite(buff_addr);
			 i2cAck();
			 i2cWrite(dat);
			 i2cAck();
			i2cStop();
			delay_ms(20);        
	}
	u8 i2cDevRead(u8 slave_addr, u8 buff_addr)
		{
					u8 buff;
					 i2cStart();
					i2cWrite(slave_addr);
					i2cAck();
					i2cWrite(buff_addr);
				 i2cAck();
				 i2cRestart();
				 i2cWrite(slave_addr|0x01); /*0x01 is for read bit from slave device*/ 
				 i2cAck();
				buff=i2cRead();
				i2cNoAck();
				i2cStop();
				return buff;      
	}
void i2cDevPageWrite(u8 slave_addr,u8 buff_Startaddr,u8 *arr,u8 nbytes)
{
	u8 i;
	i2cStart();
	i2cWrite(slave_addr);
	i2cAck();
	i2cWrite(buff_Startaddr);
	i2cAck();
	for(i=0;i<nbytes;i++)
	{
		i2cWrite(arr[i]);
		i2cAck();
	}
	
	i2cStop();
	delay_ms(10);
}
void i2cDevPageRead(u8 slave_addr,u8 buff_Startaddr,u8 *arr,u8 nbytes)
{
     u8 i;
	   i2cStart();
	   i2cWrite(slave_addr);
	   i2cAck();
	   i2cWrite(buff_Startaddr);
	   i2cAck();
	   i2cRestart();
		 i2cWrite(slave_addr|0x01); /*0x01 is for read bit from slave device*/ 
     i2cAck();
	   for(i=0;i<nbytes-1;i++)
	   {
			 arr[i]=i2cRead();
			 i2cMasterAck();
		 }
		 arr[i]=i2cRead();
		 arr[++i]= '\0';
		 i2cNoAck();
		 i2cStop();
}
