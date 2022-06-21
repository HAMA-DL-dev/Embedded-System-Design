/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Display
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/Display.cpp
*********************************************************************/

//## auto_generated
#include "Display.h"
//## package StopwatchPkg

//## class TopLevel::Display

extern int initLcd(void);extern void onLcd(int min, int sec);

Display_C::Display_C() {
}

Display_C::~Display_C() {
}

void Display_C::print(int min, int sec) {
    //#[ operation print(int,int)
    printf("%d:%d\n",min,sec);       
    initLcd();
    onLcd(min,sec);
    //#]
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Display.cpp
*********************************************************************/
