#include "stm32f4xx_hal.h"

//int temp_low, temp_high, rh_low, rh_high;
//char temp_char1[2], temp_char2, rh_char1[2], rh_char2;

void set_gpio_output(void);
void set_gpio_input(void);
void DHT22_start(void);
void check_response(void);
uint8_t read_data(void);
void Delay_us(uint16_t usec);