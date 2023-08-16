// This file transform IR signal as 1 and 0.
#include "IR_10.h"
#include "main.h"

#define HIGH_MAX	2400
#define HIGH_MIN	2100
#define LOW_MAX		1300
#define LOW_MIN		1000

uint32_t Difference = 0;
uint8_t bin = 0;
uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;

void count_pulse_width(void)
{
	if (IC_Val2 > IC_Val1)
		Difference = IC_Val2 - IC_Val1;
	else if (IC_Val2 < IC_Val1)
		Difference = (0xffff - IC_Val1) + IC_Val2;
	
}

void Difference2Binary(void)
{
	if (Difference > LOW_MIN && Difference < LOW_MAX)
		bin = 0;
	else if (Difference > HIGH_MIN && Difference < HIGH_MAX)
		bin = 1;
}






