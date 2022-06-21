/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Display
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\Display.cpp
*********************************************************************/

//## auto_generated
#include "Display.h"
//## link itsTimer
#include "Timer.h"
//## package StopwatchPkg

//## class TopLevel::Display
Display_C::Display_C() {
    itsTimer = NULL;
}

Display_C::~Display_C() {
    cleanUpRelations();
}

Timer_C* Display_C::getItsTimer() const {
    return itsTimer;
}

void Display_C::setItsTimer(Timer_C* p_Timer) {
    if(p_Timer != NULL)
        {
            p_Timer->_setItsDisplay(this);
        }
    _setItsTimer(p_Timer);
}

void Display_C::cleanUpRelations() {
    if(itsTimer != NULL)
        {
            Display_C* p_Display = itsTimer->getItsDisplay();
            if(p_Display != NULL)
                {
                    itsTimer->__setItsDisplay(NULL);
                }
            itsTimer = NULL;
        }
}

void Display_C::__setItsTimer(Timer_C* p_Timer) {
    itsTimer = p_Timer;
}

void Display_C::_setItsTimer(Timer_C* p_Timer) {
    if(itsTimer != NULL)
        {
            itsTimer->__setItsDisplay(NULL);
        }
    __setItsTimer(p_Timer);
}

void Display_C::_clearItsTimer() {
    itsTimer = NULL;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Display.cpp
*********************************************************************/
