// This file transform IR signal as 1 and 0.
#include "IR_10.h"


#define HIGH_TIME	 
#define LOW_TIME		


//uint32_t measurePulseDuration(void) 
//{
//    uint32_t startTime = HAL_GetTick();
//    while (HAL_GPIO_ReadPin(IR_READ_GPIO_Port, IR_READ_Pin) == GPIO_PIN_SET) {
//        // Wait for the pulse to start
//    }
//    while (HAL_GPIO_ReadPin(IR_READ_GPIO_Port, IR_READ_Pin) == GPIO_PIN_RESET) {
//        // Wait for the pulse to end
//    }
//    uint32_t endTime = HAL_GetTick();
//    return endTime - startTime;
//}

