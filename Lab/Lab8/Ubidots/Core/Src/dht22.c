/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "dht22.h"
uint8_t check = 0;
GPIO_InitTypeDef GPIO_InitStruct;

void set_gpio_output(void)
{
	/*Configure GPIO pin output: PE0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}
void set_gpio_input(void)
{
	/*Configure GPIO pin input: PE0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}
void DHT22_start(void)
{
	set_gpio_output();   // set the pin as output
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 0);    // pull the pin low
	Delay_us(500);    // wait for 500us
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 1);    // pull the pin high
	Delay_us(30);    // wait for 30us
	set_gpio_input();    // set as input
}
void check_response(void)
{
	Delay_us(40);
	if (!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0)))
	{
		Delay_us(80);
		if ((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0))) check = 1;
	}
	while ((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0))) ;   // wait for the pin to go low
}
uint8_t read_data(void)
{
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		while (!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0))) ;   // wait for the pin to go high
		Delay_us(40);    // wait for 40 us
		if((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0)) == 0)   // if the pin is low 
		{
			i &= ~(1 << (7 - j));    // write 0
		}
		else i |= (1 << (7 - j));   // if the pin is high, write 1
		while((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0)));   // wait for the pin to go low
	}
	return i;
}