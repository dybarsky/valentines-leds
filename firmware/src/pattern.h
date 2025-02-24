/*
Patterns for LEDs
*/

#ifndef HEADER_PATTERN
#define HEADER_PATTERN

typedef struct {
	unsigned char size;
	unsigned char * array;
} pattern;

pattern next_pattern();

#endif // HEADER_PATTERN