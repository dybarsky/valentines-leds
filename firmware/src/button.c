#include <msp430g2553.h>
#include "button.h"

#define BUTTON BIT3

void configure_button() {
	// P1REN |= BUTTON;                 // enabing pulling
	// P1OUT |= BUTTON;                 // pull up

	// Setup interruptions
	P1IES |= BUTTON;        
	// Reset interruptions flag
	P1IFG &= ~BUTTON;          
	// Enabled interruptions
	P1IE |= BUTTON;
}

#pragma vector = PORT1_VECTOR
__interrupt void on_button_pressed() {
	if (P1IFG & BUTTON) {
		// Reset interruption flag
		P1IFG &= ~BUTTON;
		// Invoke callback
		on_button_callback();
	}
}
