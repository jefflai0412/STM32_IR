# STM32_IR

## How to use
1. Declare and define a input capture callback function(it will be called automatically)
'''C
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) 
{
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{	
	  signal_received();
	}
}
'''
