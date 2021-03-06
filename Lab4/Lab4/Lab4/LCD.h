/*
 * LCD.h
 *
 * Created: 3/2/2020 9:00:10 PM
 *  Author: noor_
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "PulseGenerator.h"
#include "TinyTimber.h"

typedef struct {
	Object super;
	PulseGenerator *g1;
	PulseGenerator *g2;
	PulseGenerator *currentPulse;
} LCD;

void writeChar(char ch, int pos);
void printAt(long num, int pos);
void init(void);
void updateLCD(LCD *self, int arg);
void change(LCD *self, int pulse);

#define initLCD(pg1, pg2, curr) {initObject(), pg1, pg2, curr}

#endif /* LCD_H_ */