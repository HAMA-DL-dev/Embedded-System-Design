
//#include "stm32f4xx_hal.h"
#ifndef Fonts
#define Fonts

//
//	Structure om font te definieren
//
typedef struct {
	const unsigned char FontWidth;    /*!< Font width in pixels */
	unsigned char FontHeight;   /*!< Font height in pixels */
	const unsigned short *data; /*!< Pointer to data font data array */
} FontDef;


//
//	De 3 fonts
//
extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

#endif

