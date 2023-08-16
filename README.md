# STM32_IR

## How to use
1. Download the code.
2. Open keil uvision 5(recommanded).
3. Open the ".mxproject" file under MDK-ARM directory in keil.
4. Define an input capture callback function(it will be called automatically) in your main.c.
	```C
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) 
	{
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{	
		  signal_received();
		}
	}
	```
5. Define a function named "user_define_func" in main.c, it's going to be called automatically after <data_bits> of data is received.\
For example:\
	***note: result is the received <data_bit> long data in hex.***
	```C
	void user_define_func(void)
	{
		OLED_Clear();  					// replace this
		oled_str(result, 0, 0, ssd1306xled_font6x8); 	// replace this
		oled_RefreshGram(); 				// replace this
	}
	```

6. By now you should able to get the IR data by extracting "result" (type: char *). 
