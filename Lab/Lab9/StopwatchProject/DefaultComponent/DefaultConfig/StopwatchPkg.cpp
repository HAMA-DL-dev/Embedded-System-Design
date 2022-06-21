/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: StopwatchPkg
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\StopwatchPkg.cpp
*********************************************************************/

//## auto_generated
#include "StopwatchPkg.h"
//## classInstance Button
#include "Button.h"
//## classInstance Display
#include "Display.h"
//## classInstance Timer
#include "Timer.h"
//## package StopwatchPkg


//## classInstance Button
Button_C Button;

//## classInstance Display
Display_C Display;

//## classInstance Timer
Timer_C Timer;

void StopwatchPkg_initRelations() {
    Button.setItsTimer(&Timer);
    Timer.setItsDisplay(&Display);
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\StopwatchPkg.cpp
*********************************************************************/
