/*
 * PulseGenerator.c
 *
 * Created: 3/2/2020 9:47:00 PM
 *  Author: noor_
 */ 

#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include "PulseGenerator.h"
#include "Port.h"

void increasePulse(PulseGenerator *self, int arg) {
	if (self->frequency < 99 && self->saved == 0) {
		if (self->frequency == 0) {
			self->frequency += 1;
			AFTER((MSEC(4000)/self->frequency), self, goToPort, 0);
			} else {
			self->frequency += 1;
		}
	}
}

void decreasePulse(PulseGenerator *self, int arg) {
	if (self->frequency > 0 && self->saved == 0) {
		self->frequency--;
	}
}

void saveState(PulseGenerator *self, int arg) {
	if (self->saved == 0) {
		self->oldFrequency = self->frequency;
		self->frequency = 0;
		self->saved = 1;
		} else if (self->saved == 1) {
		self->frequency = self->oldFrequency;
		self->oldFrequency = 0;
		self->saved = 0;
		AFTER((MSEC(4000)/self->frequency), self, goToPort, 0);
	}
}

void goToPort(PulseGenerator *self, int arg) {
	if (self->frequency > 0) {
		SYNC(self->port, porting, self->portBit);
		AFTER((MSEC(4000)/self->frequency), self, goToPort, 0);
	}
}
