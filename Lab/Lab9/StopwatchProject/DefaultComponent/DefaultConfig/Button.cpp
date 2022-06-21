/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Button
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\Button.cpp
*********************************************************************/

//## auto_generated
#include "Button.h"
//## link itsTimer
#include "Timer.h"
//## package StopwatchPkg

//## class TopLevel::Button
Button_C::Button_C() {
    itsTimer = NULL;
}

Button_C::~Button_C() {
    cleanUpRelations();
}

Timer_C* Button_C::getItsTimer() const {
    return itsTimer;
}

void Button_C::setItsTimer(Timer_C* p_Timer) {
    if(p_Timer != NULL)
        {
            p_Timer->_setItsButton(this);
        }
    _setItsTimer(p_Timer);
}

void Button_C::cleanUpRelations() {
    if(itsTimer != NULL)
        {
            Button_C* p_Button = itsTimer->getItsButton();
            if(p_Button != NULL)
                {
                    itsTimer->__setItsButton(NULL);
                }
            itsTimer = NULL;
        }
}

void Button_C::__setItsTimer(Timer_C* p_Timer) {
    itsTimer = p_Timer;
}

void Button_C::_setItsTimer(Timer_C* p_Timer) {
    if(itsTimer != NULL)
        {
            itsTimer->__setItsButton(NULL);
        }
    __setItsTimer(p_Timer);
}

void Button_C::_clearItsTimer() {
    itsTimer = NULL;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Button.cpp
*********************************************************************/
