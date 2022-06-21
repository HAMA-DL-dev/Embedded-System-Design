/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Timer
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\Timer.cpp
*********************************************************************/

//## auto_generated
#include "Timer.h"
//## link itsButton
#include "Button.h"
//## link itsDisplay
#include "Display.h"
//## package StopwatchPkg

//## class TopLevel::Timer
Timer_C::Timer_C() {
    itsButton = NULL;
    itsDisplay = NULL;
}

Timer_C::~Timer_C() {
    cleanUpRelations();
}

Button_C* Timer_C::getItsButton() const {
    return itsButton;
}

void Timer_C::setItsButton(Button_C* p_Button) {
    if(p_Button != NULL)
        {
            p_Button->_setItsTimer(this);
        }
    _setItsButton(p_Button);
}

Display_C* Timer_C::getItsDisplay() const {
    return itsDisplay;
}

void Timer_C::setItsDisplay(Display_C* p_Display) {
    if(p_Display != NULL)
        {
            p_Display->_setItsTimer(this);
        }
    _setItsDisplay(p_Display);
}

void Timer_C::cleanUpRelations() {
    if(itsButton != NULL)
        {
            Timer_C* p_Timer = itsButton->getItsTimer();
            if(p_Timer != NULL)
                {
                    itsButton->__setItsTimer(NULL);
                }
            itsButton = NULL;
        }
    if(itsDisplay != NULL)
        {
            Timer_C* p_Timer = itsDisplay->getItsTimer();
            if(p_Timer != NULL)
                {
                    itsDisplay->__setItsTimer(NULL);
                }
            itsDisplay = NULL;
        }
}

void Timer_C::__setItsButton(Button_C* p_Button) {
    itsButton = p_Button;
}

void Timer_C::_setItsButton(Button_C* p_Button) {
    if(itsButton != NULL)
        {
            itsButton->__setItsTimer(NULL);
        }
    __setItsButton(p_Button);
}

void Timer_C::_clearItsButton() {
    itsButton = NULL;
}

void Timer_C::__setItsDisplay(Display_C* p_Display) {
    itsDisplay = p_Display;
}

void Timer_C::_setItsDisplay(Display_C* p_Display) {
    if(itsDisplay != NULL)
        {
            itsDisplay->__setItsTimer(NULL);
        }
    __setItsDisplay(p_Display);
}

void Timer_C::_clearItsDisplay() {
    itsDisplay = NULL;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Timer.cpp
*********************************************************************/
