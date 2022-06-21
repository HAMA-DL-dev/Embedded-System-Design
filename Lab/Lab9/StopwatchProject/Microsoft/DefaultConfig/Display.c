/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: Display
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: Microsoft\DefaultConfig\Display.c
*********************************************************************/

/*## auto_generated */
#include "Display.h"
/*## package StopwatchPkg */

/*## class TopLevel::Display */
void Display_Init(struct Display_t* const me) {
}

void Display_Cleanup(struct Display_t* const me) {
}

/*## operation print(int,int) */
void Display_print(struct Display_t* const me, int min, int sec) {
    /*#[ operation print(int,int) */
    print("%d:%d\r\n",min,sec);
    /*#]*/
}

/*********************************************************************
	File Path	: Microsoft\DefaultConfig\Display.c
*********************************************************************/
