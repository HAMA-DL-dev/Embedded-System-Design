
#include"ssd1306.h"
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
	int fd;	
// Data buffer for the screen
static uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];
// A screen object to work on locally
static SSD1306_t SSD1306;
//
//	Send a byte to the command register
//	Cannot be used outside of this file
//
void ssd1306_WriteCommand(uint8_t command)
{
	unsigned char buf[2];	
	//HAL_I2C_Mem_Write(&hi2c1,SSD1306_I2C_ADDR,0x00,1,&command,1,10);
	buf[0]=0x00;
	buf[1]=command;
	write(fd, buf, 2);
	
}
void ssd1306_Init_alt(void)
{
	
	ssd1306_WriteCommand(0xAE);
	//ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);	// 0xD5
	ssd1306_WriteCommand(0xD5);
	//ssd1306_command(0x80);	// the suggested ratio 0x80
	ssd1306_WriteCommand(0x80);

	//ssd1306_command(SSD1306_SETMULTIPLEX);	// 0xA8
	ssd1306_WriteCommand(0xA8);
	//ssd1306_command(64 - 1);
	ssd1306_WriteCommand(63);

	//ssd1306_command(SSD1306_SETDISPLAYOFFSET);	// 0xD3
	ssd1306_WriteCommand(0xD3);
	//ssd1306_command(0x0);	// no offset
	ssd1306_WriteCommand(0x0);
	//ssd1306_command(SSD1306_SETSTARTLINE | 0x0);	// line #0
	ssd1306_WriteCommand(0x40);
	//ssd1306_command(SSD1306_CHARGEPUMP);	// 0x8D
	ssd1306_WriteCommand(0x8D);
	//if (vccstate == SSD1306_EXTERNALVCC) {
		//ssd1306_command(0x10);
	//} else {
		//ssd1306_command(0x14);
	//}
	ssd1306_WriteCommand(0x10);
	//ssd1306_command(SSD1306_MEMORYMODE);	// 0x20
	ssd1306_WriteCommand(0x20);
	//ssd1306_command(0x00);	// 0x0 act like ks0108
	ssd1306_WriteCommand(0x00);
	//ssd1306_command(SSD1306_SEGREMAP | 0x1);
	ssd1306_WriteCommand(0xA0 | 0x1);
	//ssd1306_command(SSD1306_COMSCANDEC);
	ssd1306_WriteCommand(0xC0);


	//ssd1306_command(SSD1306_SETCOMPINS);	// 0xDA
	ssd1306_WriteCommand(0xDA);
	//ssd1306_command(0x12);
	ssd1306_WriteCommand(0x12);
	//ssd1306_command(SSD1306_SETCONTRAST);	// 0x81
	ssd1306_WriteCommand(0x81);
	//if (vccstate == SSD1306_EXTERNALVCC) {
		//ssd1306_command(0x9F);
	//} else {
		//ssd1306_command(0xCF);
	//}
	ssd1306_WriteCommand(0x9F);

	//ssd1306_command(SSD1306_SETPRECHARGE);	// 0xd9
	ssd1306_WriteCommand(0xD9);
	//if (vccstate == SSD1306_EXTERNALVCC) {
		//ssd1306_command(0x22);
	//} else {
		//ssd1306_command(0xF1);
	//}
	ssd1306_WriteCommand(0x22);
	//ssd1306_command(SSD1306_SETVCOMDETECT);	// 0xDB
	ssd1306_WriteCommand(0xDB);
	//ssd1306_command(0x40);
	ssd1306_WriteCommand(0x40);
	//ssd1306_command(SSD1306_DISPLAYALLON_RESUME);	// 0xA4
	ssd1306_WriteCommand(0xA4);
	//ssd1306_command(SSD1306_NORMALDISPLAY);	// 0xA6
	ssd1306_WriteCommand(0xA6);

	//ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
	ssd1306_WriteCommand(0x2E);

	//ssd1306_command(SSD1306_DISPLAYON);	// --turn on oled panel
	ssd1306_WriteCommand(0xAF);



}
//
//	Het scherm initialiseren voor gebruik
//
uint8_t ssd1306_Init(void)
{	
	unsigned char buf[10];
	int  address = SSD1306_I2C_ADDR;
	// Wait a while so that the screen is definitely started
	//HAL_Delay(100);
	if ((fd = open("/dev/i2c-1", O_RDWR)) < 0) {	// Open port for reading and writing
		printf("Failed to open i2c port\n");
		return(1);
	}
	if (ioctl(fd, I2C_SLAVE, address) < 0) {	// Set the port options and set the address of the device we wish to speak to
		printf("Unable to get bus access to talk to slave\n");
		return(1);
	}
	/* Init LCD */
	ssd1306_WriteCommand(0xAE); //display off
	ssd1306_WriteCommand(0x20); //Set Memory Addressing Mode   
	ssd1306_WriteCommand(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	ssd1306_WriteCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
	ssd1306_WriteCommand(0xC8); //Set COM Output Scan Direction
	ssd1306_WriteCommand(0x00); //---set low column address
	ssd1306_WriteCommand(0x10); //---set high column address
	ssd1306_WriteCommand(0x40); //--set start line address
	ssd1306_WriteCommand(0x81); //--set contrast control register
	ssd1306_WriteCommand(0xFF); //ff
	ssd1306_WriteCommand(0xA1); //--set segment re-map 0 to 127
	ssd1306_WriteCommand(0xA6); //--set normal display
	ssd1306_WriteCommand(0xA8); //--set multiplex ratio(1 to 64)
	ssd1306_WriteCommand(0x3F); //
	ssd1306_WriteCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	ssd1306_WriteCommand(0xD3); //-set display offset
	ssd1306_WriteCommand(0x00); //-not offset
	ssd1306_WriteCommand(0xD5); //--set display clock divide ratio/oscillator frequency
	ssd1306_WriteCommand(0xF0); //--set divide ratio
	ssd1306_WriteCommand(0xD9); //--set pre-charge period
	ssd1306_WriteCommand(0x22); //
	ssd1306_WriteCommand(0xDA); //--set com pins hardware configuration
	ssd1306_WriteCommand(0x12);
	ssd1306_WriteCommand(0xDB); //--set vcomh
	ssd1306_WriteCommand(0x20); //0x20,0.77xVcc
	ssd1306_WriteCommand(0x8D); //--set DC-DC enable
	ssd1306_WriteCommand(0x14); //0x14
	ssd1306_WriteCommand(0xAF); //--turn on SSD1306 panel

	/* Clearen scherm */
	ssd1306_Fill(Black);
	
	/* Update screen */
	ssd1306_UpdateScreen();
		
	/* Set default values */
	SSD1306.CurrentX = 0;
	SSD1306.CurrentY = 0;
	
	/* Initialized OK */
	SSD1306.Initialized = 1;
	
	/* Return OK */
	return 1;
}

//
//	We set the entire buffer to a specific color
// 	color 	=> the color in which everything must be
//
void ssd1306_Fill(SSD1306_COLOR color) 
{
	/* Set memory */
	uint32_t i;

	for(i = 0; i < sizeof(SSD1306_Buffer); i++)
	{
		SSD1306_Buffer[i] = (color == Black) ? 0x00 : 0xFF;
	}
}

//
//	Send all changes in the buffer to the screen
//
void ssd1306_UpdateScreen(void) 
{
	uint8_t i;
	uint8_t buf[200];
	buf[0]=0x40;
	for (i = 0; i < 8; i++) {
		memcpy(buf+1,&SSD1306_Buffer[SSD1306_WIDTH * i],SSD1306_WIDTH);
		ssd1306_WriteCommand(0xB0 + i);
		ssd1306_WriteCommand(0x00);
		ssd1306_WriteCommand(0x10);
		// We write everything folder by folder
		//HAL_I2C_Mem_Write(&hi2c1,SSD1306_I2C_ADDR,0x40,1,&SSD1306_Buffer[SSD1306_WIDTH * i],SSD1306_WIDTH,100);
		write(fd, buf, SSD1306_WIDTH+1);
	}
}

//
//	Draw 1 pixel on the screen
//	X => X coordinate
//	Y => Y coordinate
//	color => color that pixel should get
//
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color)
{
	if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) 
	{
		// We are not going to write off-screen
		return;
	}
	
	// See if the pixel should be inverted
	if (SSD1306.Inverted) 
	{
		color = (SSD1306_COLOR)!color;
	}
	
	// We put the correct color for the pixel
	if (color == White)
	{
		SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
	} 
	else 
	{
		SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
	}
}

//
//	We willen 1 char naar het scherm sturen
//	ch 		=> char om weg te schrijven
//	Font 	=> Font waarmee we gaan schrijven
//	color 	=> Black or White
//
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color)
{
	uint32_t i, b, j;
	
	// Kijken of er nog plaats is op deze lijn
	if (SSD1306_WIDTH <= (SSD1306.CurrentX + Font.FontWidth) ||
		SSD1306_HEIGHT <= (SSD1306.CurrentY + Font.FontHeight))
	{
		// Er is geen plaats meer
		return 0;
	}
	
	// We gaan door het font
	for (i = 0; i < Font.FontHeight; i++)
	{
		b = Font.data[(ch - 32) * Font.FontHeight + i];
		for (j = 0; j < Font.FontWidth; j++)
		{
			if ((b << j) & 0x8000) 
			{
				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR) color);
			} 
			else 
			{
				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR)!color);
			}
		}
	}
	
	// De huidige positie is nu verplaatst
	SSD1306.CurrentX += Font.FontWidth;
	
	// We geven het geschreven char terug voor validatie
	return ch;
}

//
//	Function for writing a whole string
// 	str => string to write on the screen
//	Font => The font to use
//	color => Black or White
//
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color)
{
	// We schrijven alle char tot een nulbyte
	while (*str) 
	{
		if (ssd1306_WriteChar(*str, Font, color) != *str)
		{
			// Het karakter is niet juist weggeschreven
			return *str;
		}
		
		// Volgende char
		str++;
	}
	
	// Alles gelukt, we sturen dus 0 terug
	return *str;
}

//
//	Zet de cursor op een coordinaat
//
void ssd1306_SetCursor(uint8_t x, uint8_t y) 
{
	/* Set write pointers */
	SSD1306.CurrentX = x;
	SSD1306.CurrentY = y;
}
