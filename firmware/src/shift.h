/*
SN74HC595N shift register control
Turns on and off leds.
*/

#ifndef HEADER_SHIFT
#define HEADER_SHIFT

void configure_shift();
void shift_a(unsigned char data);
void shift_b(unsigned char data);

#endif // HEADER_SHIFT