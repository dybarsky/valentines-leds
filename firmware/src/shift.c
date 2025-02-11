#include <msp430g2553.h>
#include "shift.h"

#define DATA	BIT4
#define CLOCK	BIT3
#define LATCH_A	BIT2
#define LATCH_B	BIT5

void configure_shift() {
	P1SEL &= ~(CLOCK + DATA + LATCH_A + LATCH_B);
	P1DIR |= (CLOCK + DATA + LATCH_A + LATCH_B);
	P1OUT = 0;
}

void transmit(unsigned char data) {
	char count;
	for (count = 0; count < 8; count ++) {
		char bytes = data & (1 << count);
		if (bytes) {
			P1OUT |= DATA;
		} else {
			P1OUT &= ~DATA;
		}
		// clock tick
		P1OUT |= CLOCK;
		P1OUT &= ~CLOCK;
	}
}

void shift_a(unsigned char data) {
	// latch is down to start receiving
	P1OUT &= ~LATCH_A;
	// transmit data to bus
	transmit(data);
	// latch is up to apply shifted data
	P1OUT |= LATCH_A;
}

void shift_b(unsigned char data) {
	// latch is down to start receiving
	P1OUT &= ~LATCH_B;
	// transmit data to bus
	transmit(data);
	// latch is up to apply shifted data
	P1OUT |= LATCH_B;
}
