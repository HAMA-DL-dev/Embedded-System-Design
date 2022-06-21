
#include "ssd1306.h"
#include "fonts.h"
#include <unistd.h>

int main(void)
{

	ssd1306_Init();
	//HAL_Delay(1000);
	
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();

	//HAL_Delay(1000);
	

	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Hello World", Font_11x18, White);
	ssd1306_SetCursor(0, 50);
	ssd1306_WriteString("Raspberry Pi", Font_7x10, White);
	ssd1306_UpdateScreen();
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	int counter;
	unsigned char string[10];
  while (1)
  {
	  string[0] = counter / 100 + 0x30;
	  string[1] = (counter % 100) / 10 + 0x30;
	  string[2] = (counter % 100) % 10 + 0x30;
	  string[3] = 0;
	  ssd1306_SetCursor(40, 20);
	  ssd1306_WriteString(string, Font_16x26, White);
	  counter++;
	  if (counter > 999) counter = 0;
	  ssd1306_UpdateScreen();
  }
  /* USER CODE END 3 */
}

