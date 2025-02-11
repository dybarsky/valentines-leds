#include <msp430g2553.h>
#include "button.h"

#define BUTTON BIT3

void configure_button() {
	// Setup button pin
	P2DIR &= ~BUTTON;
	// Pull down
	P2REN |= BUTTON;
	P2OUT &= ~BUTTON;
	// Setup interruptions
	P2IES |= BUTTON;        
	P2IFG &= ~BUTTON;          
	P2IE |= BUTTON;
}

#pragma vector = PORT2_VECTOR
__interrupt void on_button_pressed() {
	if (P2IFG & BUTTON) {
		// Reset interruption flag
		P2IFG &= ~BUTTON;
		// Invoke callback
		on_button_callback();
	}
}
