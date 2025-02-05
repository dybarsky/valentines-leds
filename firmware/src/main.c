#include <msp430g2553.h>
#include "shift.h"
#include "timer.h"
#include "button.h"

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

int main(void) {
	// config peripherals
	configure();
	configure_timer();
	configure_shift();
	configure_button();

	// test
	//unsigned int data = 0b00000101;
	//shift_a(data);
	//shift_b(data);

	// reset state
	shift_a(0);
	shift_b(0);

	start_timer();
	
	// low power mode + enable interruptions
	_BIS_SR(LPM0_bits + GIE);
}

void on_button_callback() {
	
}

void on_timer_callback() {
	program_1();
}

int count = 0;
void program_1() {
	if (count > 8) {
		count = 0;
	}
	unsigned int byte = 128;
	unsigned int data = byte >> count;
	//unsigned int data = ~(~byte >> count);
	shift_a(data);
	shift_b(data);
	count ++;
}
