/*
frequency = 1 MHz
divider = 8
1 second = 125 000 tacts
0.1 seconds = 12 500 tacts
*/

#include <msp430g2553.h>
#include "timer.h"

#define COUNT 12500

void configure_timer() {
	// set timer counter
	TA1CCR0 = COUNT;
}

void start_timer() {
	// sum-main clock + freq divider 4 + up mode + init
	TA1CTL = TASSEL_2 + ID_3 + MC_1 + TACLR;
	// enable timer interruptions
	TA1CCTL0 = CCIE;
}

void stop_timer() {
	// disable timer interruptions 
	TA1CCTL0 = ~CCIE;
	// stop timer
	TA1CTL &= ~MC_3;
	// set stop mode
	TA1CTL |= MC_0;
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void on_timer1_ccr0(void) {
	// reset interruption flag
	TA1CCTL0 &= ~CCIFG;
	// invoke callback
	on_timer_callback();
}
