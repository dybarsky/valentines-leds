#include <msp430g2553.h>
#include "shift.h"

#define DATA 	BIT3
#define CLOCK	BIT6
#define LATCH_A	BIT4
#define LATCH_B	BIT5

void configure_shift() {
	P2SEL &= ~(CLOCK + DATA + LATCH_A + LATCH_B);
	P2DIR |= (CLOCK + DATA + LATCH_A + LATCH_B);
	P2OUT = 0;
}

void transmit(unsigned int data) {
	int count;
	for (count = 0; count < 8; count ++) {
		int bytes = data & (1 << count);
		if (bytes) {
			P2OUT |= DATA;
		} else {
			P2OUT &= ~DATA;
		}
		// Clock tick
		P2OUT |= CLOCK;
		P2OUT &= ~CLOCK;
	}
}

void shift_a(unsigned int data) {
	// Latch is down to start receiving
	P2OUT &= ~LATCH_A;
	// Transmit data to bus
	transmit(data);
	// Latch is up to apply shifted data
	P2OUT |= LATCH_A;
}

void shift_b(unsigned int data) {
	// Latch is down to start receiving
	P2OUT &= ~LATCH_B;
	// Transmit data to bus
	transmit(data);
	// Latch is up to apply shifted data
	P2OUT |= LATCH_B;
}
