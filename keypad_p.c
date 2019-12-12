#include<reg51.h>
#include"types.h"


#define keypd P2^0
sbit c0=keypd^0;
sbit c1=keypd^1;
sbit c2=keypd^2;
sbit c3=keypd^3;
sbit r0=keypd^4;
sbit r1=keypd^5;
sbit r2=keypd^6;
sbit r3=keypd^7;

u8 row_val,col_val;
code u8 b[][4]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};


void Row_Init(void)
{
	r0 = r1 = r2 = r3 = 0;//make all rows as output & bydefault columns are input
}

bit ColStatus(void)
{
	return(c0&&c1&&c2&&c3);
}
s8 KeyScan(void)
{
	
	r0=0;r1=r2=r3=1;
	if(!ColStatus())
	{
		row_val=0;
		goto colcheck;
	}
		r1=0;r0=r2=r3=1;
	if(!ColStatus())
	{
		row_val=1;
		goto colcheck;
	}
		r2=0;r1=r0=r3=1;
	if(!ColStatus())
	{
		row_val=2;
		goto colcheck;
	}
		r3=0;r1=r2=r0=1;
	if(!ColStatus())
	{
		row_val=3;
		goto colcheck;
	}
	
	colcheck:
	if(c0==0)
		col_val=0;
	else if(c1==0)
		col_val=1;
	else if(c2==0)
		col_val=2;
	else
		col_val=3;
	while(!ColStatus());
	return(b[row_val][col_val]);
}