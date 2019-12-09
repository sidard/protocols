#include"types.h"
#ifndef __I2C_H__
#define __I2C_H__
		                /*prototypes for i2c bus events*/
void i2cStart(void);
void i2cRestart(void);
void i2cStop(void);
void i2cWrite(u8);
u8 i2cRead(void);
void i2cAck(void);
void i2cNoAck(void);
void i2cMasterAck();
                                                    /*end_prototypes for i2c bus events*/

		         /*prototypes for i2c communication algorithm*/
void i2cDevWrite(u8,u8,u8);
u8 i2cDevRead(u8,u8);
#endif             
              /*prototypes for i2c communication for page read and write algorithm*/
void i2cDevPageWrite(u8,u8,u8*,u8);
void i2cDevPageRead(u8,u8,u8*,u8);
/*end of i2c.h*/