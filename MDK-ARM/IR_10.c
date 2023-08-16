// This file transform IR signal as 1 and 0.
#include "IR_10.h"
#include "main.h"
#include <math.h>
#include <string.h>
#include "ssd1306_fonts.h"
#include "OLED.h"


#define HIGH_MAX	2400
#define HIGH_MIN	2100
#define LOW_MAX		1300
#define LOW_MIN		1000



uint8_t Is_First_Captured = 0;
uint8_t count = 0;

uint32_t Difference = 0;
uint8_t lead_code_received = 0;
uint8_t bin = 0;
uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;


uint8_t deci = 0;
char hex_str[1];

char result[100];

void reset_IR_var(void)
{
	count = 0;
	lead_code_received = 0;
	result[0] = '\0';
	Is_First_Captured = 0;	
}

char * signal_received(TIM_HandleTypeDef *htim, uint8_t data_bits)
{
	if (Is_First_Captured==0)
	{
		IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
		Is_First_Captured = 1;
	}
	else
	{
		IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	
		count_pulse_width();
		
		
		if (Difference > 1100 && Difference < 1200)
			lead_code_received = 1;
		
		if (lead_code_received)
		{
			Difference2hex();  // pulse width -> binary -> decimal -> hex
		
			if (count == data_bits)
			{
				user_define_func();
				
				reset_IR_var();
			}
			
			count ++;
		}
	}	
	
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






