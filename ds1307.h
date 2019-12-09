#ifndef __DS1307_H__
#define __DS1307_H__

#include "types.h"
void setTime(u8 *);
u8 *getTime(void);

void setHours(u8);
void setMins(u8);
void setSecs(u8);

u8 getHours(void);
u8 getMins(void);
u8 getSecs(void);

void setCalender(u8*);
u8* getCalender(void);
void setDay(u8);
void setDate(u8);
void setMonth(u8);
void setYear(u8);

u8 getDay(void);
u8 getDate(void);
u8 getMonth(void);
u8 getYear(void);

#endif
