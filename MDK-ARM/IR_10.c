// This file transform IR signal as 1 and 0.
#include "IR_10.h"
#include "main.h"

#define HIGH_MAX	2400
#define HIGH_MIN	2100
#define LOW_MAX		1300
#define LOW_MIN		1000


uint32_t count_pulse_width(uint32_t VAL1, uint32_t VAL2)
{
	uint32_t Difference;
	if (VAL2 > VAL1)
		Difference = VAL2 - VAL1;
	else if (VAL2 < VAL1)
		Difference = (0xffff - VAL1) + VAL2;
	
	return Difference;
}

uint8_t Difference2Binary(uint32_t Difference)
{
	if (Difference > LOW_MIN && Difference < LOW_MAX)
		return 0;
	else if (Difference > HIGH_MIN && Difference < HIGH_MAX)
		return 1;
}






