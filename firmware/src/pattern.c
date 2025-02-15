#include "pattern.h"

#define AMOUNT 6
#define SIZE_RUNNING 16
#define SIZE_FILLING 18
#define SIZE_BEATING 12
#define SIZE_BLINKING 4
#define SIZE_CHEASING 12
#define SIZE_ALTERNATING 4

unsigned char running[SIZE_RUNNING][2] = {
	{ 0b00000000, 0b10000000 },
	{ 0b00000001, 0b00000000 },
	{ 0b00000010, 0b00000000 },
	{ 0b00000100, 0b00000000 },
	{ 0b00001000, 0b00000000 },
	{ 0b00010000, 0b00000000 },
	{ 0b00100000, 0b00000000 },
	{ 0b01000000, 0b00000000 },
	{ 0b10000000, 0b00000000 },
	{ 0b00000000, 0b00000001 },
	{ 0b00000000, 0b00000010 },
	{ 0b00000000, 0b00000100 },
	{ 0b00000000, 0b00001000 },
	{ 0b00000000, 0b00010000 },
	{ 0b00000000, 0b00100000 },
	{ 0b00000000, 0b01000000 },
};

unsigned char filling[SIZE_FILLING][2] = {
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b10000000 },
	{ 0b00000001, 0b11000000 },
	{ 0b00000011, 0b11100000 },
	{ 0b00000111, 0b11110000 },
	{ 0b00001111, 0b11111000 },
	{ 0b00011111, 0b11111100 },
	{ 0b00111111, 0b11111110 },
	{ 0b01111111, 0b11111111 },
	{ 0b11111111, 0b11111111 },
	{ 0b01111111, 0b11111111 },
	{ 0b00111111, 0b11111110 },
	{ 0b00011111, 0b11111100 },
	{ 0b00001111, 0b11111000 },
	{ 0b00000111, 0b11110000 },
	{ 0b00000011, 0b11100000 },
	{ 0b00000001, 0b11000000 },
	{ 0b00000000, 0b10000000 },
};

unsigned char blinking[SIZE_BLINKING][2] = {
	{ 0b11111111, 0b10000000 },
	{ 0b11111111, 0b10000000 },
	{ 0b10000000, 0b11111111 },	
	{ 0b10000000, 0b11111111 },	
};

unsigned char alternating[SIZE_ALTERNATING][2] = {
	{ 0b01010101, 0b01010101 },
	{ 0b01010101, 0b01010101 },
	{ 0b10101010, 0b10101010 },
	{ 0b10101010, 0b10101010 },
};

unsigned char beating[SIZE_BEATING][2] = {
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b00000000 },
	{ 0b11111111, 0b11111111 },
	{ 0b11111111, 0b11111111 },
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b00000000 },
	{ 0b11111111, 0b11111111 },
	{ 0b11111111, 0b11111111 },
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b00000000 },
	{ 0b00000000, 0b00000000 },
};

unsigned char cheasing[SIZE_CHEASING][2] = {
	{ 0b00000000, 0b00000000 },
	{ 0b10000000, 0b00000000 },
	{ 0b11000000, 0b00000001 },
	{ 0b11100000, 0b00000011 },
	{ 0b01110000, 0b00000111 },
	{ 0b00111000, 0b00001110 },
	{ 0b00011100, 0b00011100 },
	{ 0b00001110, 0b00111000 },
	{ 0b00000111, 0b01110000 },
	{ 0b00000011, 0b11100000 },
	{ 0b00000001, 0b11000000 },
	{ 0b00000000, 0b10000000 },
};

struct pattern data[AMOUNT] = {
	{ SIZE_RUNNING, *running },
	{ SIZE_FILLING, *filling },
	{ SIZE_BEATING, *beating },
	{ SIZE_CHEASING, *cheasing },
	{ SIZE_BLINKING, *blinking },
	{ SIZE_ALTERNATING, *alternating }
};

static unsigned char current = 0;

struct pattern next_pattern() {
	if (current >= AMOUNT) {
		current = 0;
	}
	return data[current++];
}
