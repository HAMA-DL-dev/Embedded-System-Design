#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "main.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern uint32_t RPM;
extern float torque;
extern float temp;

extern void CANopen();

#define UBIDOTS_TOKEN   "BBFF-WeWEmnH1dQ1qd8Dtbk2DzKCCIaXiKQ"
#define UBIDOTS_DEVICE  "STM32F407"

void my_itoa(uint32_t val, uint8_t* str, uint8_t len)	// integer to array
{
	uint8_t i;

	for (i = 1; i <= len; i++)
	{
		str[len - i] = (uint8_t)((val % 10UL) + '0');
		val /= 10;
	}
	str[i - 1] = '\0';
}
void FloatToString(uint8_t *str, float f, char size, char after_point) {
	int count;
	uint8_t* curr;
	int value;
	
	size++; /* to include NULL */
	value = (int)f;
	my_itoa(value, str, size-after_point-2);
	count = 0;
	curr = str;
	while (*curr != 0) {
		++count;
		++curr;
	}
 
	if (count + 1 >= size) {
		str[size - 1] = 0;
		return;	
	}
 	
	str[count++] = '.';
	++curr;
	f = f - (float)value;
 	
	while (count + 1 < size) {
		f *= 10;
		++count;	
	}
 	
	value = (int)f;
	my_itoa(value, curr, after_point);
	str[size - 1] = 0;
	
	count = 0;
	while (*(str + count) == '0')
	{
		*(str + count) = ' ';
		count++;
	}
	return;
}
 
void WifiSetup(void)
{
	uint8_t  string[200];
	uint8_t  buffer[200];
	int length;
	
	for (int i = 0; i < 200; i++)buffer[i] = ' ';
	strcpy((char *)string, "AT+CWMODE=3");
	length = strlen((char *)string);
	string[length] = 0x0D;
	string[length + 1] = 0x0A;
	string[length + 2] = 0;
	HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);
	HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 1000);
	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);
	string[0] = 0x0D;
	string[1] = 0x0A;
	HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
	
	strcpy((char *)string, (char *)"AT+CWJAP=\"FOURTOR\",""");
//	strcpy((char *)string, (char *)"AT+CWJAP=\"iPhone (3)\",\"gkdus713\"");
	length = strlen((char *)string);
	string[length] = 0x0D;
	string[length + 1] = 0x0A;
	string[length + 2] = 0;
	HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);
	HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 4000);
//	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);
	string[0] = 0x0D;
	string[1] = 0x0A;
//	HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
}
void OpenUbidots(void)
{
	uint8_t  string[200];
	uint8_t  buffer[200];
	int length;
	int ret;
	
	do
	{
		for (int i = 0; i < 200; i++)buffer[i] = ' ';
		strcpy((char *)string, (char *)"AT+CIPSTART=\"TCP\",\"things.ubidots.com\",80");
		length = strlen((char *)string);
		string[length] = 0x0D;
		string[length + 1] = 0x0A;
		string[length + 2] = 0;
		HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
		HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 4000); 		
		HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);
		string[0] = 0x0D;
		string[1] = 0x0A;
		HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
		ret = (int)strstr((char *)buffer, (char *)"CONNECT");
	} while (ret == 0);
}
void CloseUbidots(void)
{
	uint8_t  string[200];
	uint8_t  buffer[200];
	int length;
	
	for (int i = 0; i < 200; i++)buffer[i] = ' ';
	strcpy((char *)string, (char *)"AT+CIPCLOSE");
	length = strlen((char *)string);
	string[length] = 0x0D;
	string[length + 1] = 0x0A;
	string[length + 2] = 0;
	HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);
	HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 4000); 		
	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);
	string[0] = 0x0D;
	string[1] = 0x0A;
	HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
}
// uint32_t rpm,uint16_t torque,uint16_t temperature
void WifiUbidots(void)
{
	uint8_t  string[200];
	uint8_t  buffer[2000];
	/*uint8_t  query[500];*/
	char sendBuffer[256];
	uint8_t sendBufferLength;
	uint8_t sendBufferLengthString[5];

	uint8_t rpm_string[100];
	uint8_t torque_string[100];
	uint8_t temp_string[100];
	char message[64];
	int length;
	int ret;
	
	for (;;)
	{
		OpenUbidots();
		do
		{
			CANopen();
			FloatToString(rpm_string, RPM, sizeof(rpm_string), 1);
			FloatToString(torque_string, torque, sizeof(rpm_string), 1);
			FloatToString(temp_string, temp, sizeof(rpm_string), 1);
//			sprintf(message, "{\"RPM\": %ld,\"torque\": %.2f,\"temperature\": %.2f}",RPM,torque,temp);
			sprintf(message, "{\"RPM\": %ld,\"torque\": %.2f}",RPM,torque);
			// rpm_string,torque_string,temp_string
			// rpm,torque,temperature
			HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), 0xFFFF);
			sprintf(sendBuffer, "POST /api/v1.6/devices/%s/?token=%s HTTP/1.1\r\nHost: things.ubidots.com\r\nContent-Type: application/json\r\nContent-Length: %d\r\n\r\n%s", UBIDOTS_DEVICE, UBIDOTS_TOKEN, (int)strlen(message), message); 
			sendBufferLength = strlen((char *)sendBuffer);
			for (int i = 0; i < 50; i++)buffer[i] = ' ';
			my_itoa(sendBufferLength, sendBufferLengthString, 3);
			sprintf((char *)string, "AT+CIPSEND=%s", sendBufferLengthString);
			length = strlen((char *)string);
			string[length] = 0x0D;
			string[length + 1] = 0x0A;
			string[length + 2] = 0;
			HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
			HAL_UART_Receive(&huart3, (uint8_t *)buffer, 24, 4000);	
		
			for (int i = 0; i < 2000; i++)buffer[i] = ' ';
			HAL_Delay(1);
			HAL_UART_Transmit(&huart3, (uint8_t *)(sendBuffer), sendBufferLength, 0xFFFF);
			HAL_UART_Receive(&huart3, (uint8_t *)buffer, 500, 4000);
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 500, 0xFFFF);
			string[0] = 0x0D;
			string[1] = 0x0A;
			HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
			ret = (int)strstr((char *)buffer, (char *)"ERROR");
			/* wait for a while to slow down */    
			HAL_Delay(20000);
		} while (ret == 0);
		CloseUbidots();
	}
}
