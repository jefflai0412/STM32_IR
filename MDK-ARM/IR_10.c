// This file transform IR signal as 1 and 0.
#include "IR_10.h"
#include "main.h"
#include <math.h>
#include <string.h>


#define HIGH_MAX	2400
#define HIGH_MIN	2100
#define LOW_MAX		1300
#define LOW_MIN		1000

uint8_t count = 0;

uint32_t Difference = 0;
uint8_t lead_code_received = 0;
uint8_t bin = 0;
uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;

uint8_t deci = 0;
char hex_str[1];

char result[100];

char * signal_receive(uint8_t data_bits)
{
	return result;
}

void count_pulse_width(void)
{
	if (IC_Val2 > IC_Val1)
		Difference = IC_Val2 - IC_Val1;
	else if (IC_Val2 < IC_Val1)
		Difference = (0xffff - IC_Val1) + IC_Val2;
	
	IC_Val1 = IC_Val2;
}

void Difference2hex(void)
{
	if (Difference > LOW_MIN && Difference < LOW_MAX)
		bin = 0;
	else if (Difference > HIGH_MIN && Difference < HIGH_MAX)
		bin = 1;
	
	deci += bin * pow(2, count % 4);  // binary to decimal
	
	if (count % 4 == 0)
	{
		sprintf(hex_str, "%X", deci);  // decimal to hex
		strcat(result, hex_str); 
		deci = 0;
		hex_str[0] = '\0';
	}
}






