#include "main.h"

extern uint32_t Difference;
extern uint8_t bin;
extern uint32_t IC_Val1;
extern uint32_t IC_Val2;



extern uint8_t Is_First_Captured;
extern uint8_t count;

extern uint32_t Difference;
extern uint8_t lead_code_received;
extern uint8_t bin;
extern uint32_t IC_Val1;
extern uint32_t IC_Val2;

extern uint8_t deci;
extern char hex_str[1];

extern char result[100];


char * signal_receive(uint8_t data_bits);
void count_pulse_width(void);
void Difference2hex(void);
