/*
Patterns for LEDs
*/

struct pattern {
	unsigned char size;
	unsigned char * array;
};

struct pattern next_pattern();
