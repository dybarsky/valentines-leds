#include <msp430g2553.h>
#include "shift.h"
#include "timer.h"
#include "button.h"
#include "pattern.h"

void configure() {
	// turn off watchdog
	WDTCTL = WDTPW + WDTHOLD;
	// set frequency 1MHz
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	// set all pins off
	P1OUT = 0;
	P2OUT = 0;
}

unsigned char *array;
unsigned char index;
unsigned char size;

int main(void) {
	// config peripherals
	configure();
	configure_timer();
	configure_shift();
	configure_button();
	// turn off leds
	shift_a(0);
	shift_b(0);
	// init state
	index = 0;
	array = next_pattern();
	size = pattern_size();
	start_timer();
	// low power mode + enable interruptions
	_BIS_SR(LPM0_bits + GIE);
}

void on_button_callback() {
	index = 0;
	array = next_pattern();
	size = pattern_size();
}

void on_timer_callback() {
	if (index >= size) {
		index = 0;
	}
	unsigned char *row = array + (index * 2);
	unsigned char left = row[0];
	unsigned char right = row[1];
	shift_b(left);
	shift_a(right);
	index ++;
}
