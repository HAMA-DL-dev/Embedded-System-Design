/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: Linux
	Model Element	: Button
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/Linux/Button.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Button.h"
//## link itsTimer
#include "Timer.h"
//## package StopwatchPkg

//## class TopLevel::Button
Button_C::Button_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsTimer = NULL;
    initStatechart();
}

Button_C::~Button_C() {
    cleanUpRelations();
    cancelTimeouts();
}

Timer_C* Button_C::getItsTimer() const {
    return itsTimer;
}

void Button_C::setItsTimer(Timer_C* p_Timer) {
    itsTimer = p_Timer;
}

bool Button_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Button_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    held_subState = OMNonState;
    rootState_timeout = NULL;
    held_timeout = NULL;
}

void Button_C::cleanUpRelations() {
    if(itsTimer != NULL)
        {
            itsTimer = NULL;
        }
}

void Button_C::cancelTimeouts() {
    if(rootState_timeout != NULL)
        {
            rootState_timeout->cancel();
            rootState_timeout = NULL;
        }
    if(held_timeout != NULL)
        {
            held_timeout->cancel();
            held_timeout = NULL;
        }
}

bool Button_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    if(held_timeout == arg)
        {
            held_timeout = NULL;
            res = true;
        }
    return res;
}

void Button_C::rootState_entDef() {
    {
        rootState_subState = idle;
        rootState_active = idle;
    }
}

IOxfReactive::TakeEventStatus Button_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case idle:
        {
            if(IS_EVENT_TYPE_OF(evPressed_StopwatchPkg_id))
                {
                    //#[ transition 1 
                    
                    Timer.GEN(evStartStop);
                    //#]
                    rootState_subState = held;
                    rootState_timeout = scheduleTimeout(3000, NULL);
                    held_subState = pressed;
                    rootState_active = pressed;
                    held_timeout = scheduleTimeout(30, NULL);
                    res = eventConsumed;
                }
            
        }
        break;
        case pressed:
        {
            res = pressed_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

void Button_C::held_entDef() {
    rootState_subState = held;
    rootState_timeout = scheduleTimeout(3000, NULL);
    held_subState = pressed;
    rootState_active = pressed;
    held_timeout = scheduleTimeout(30, NULL);
}

void Button_C::held_exit() {
    if(held_subState == pressed)
        {
            if(held_timeout != NULL)
                {
                    held_timeout->cancel();
                    held_timeout = NULL;
                }
        }
    held_subState = OMNonState;
    if(rootState_timeout != NULL)
        {
            rootState_timeout->cancel();
            rootState_timeout = NULL;
        }
}

IOxfReactive::TakeEventStatus Button_C::held_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == rootState_timeout)
                {
                    held_exit();
                    //#[ transition 3 
                    
                    Timer.GEN(evReset);
                    //#]
                    rootState_subState = idle;
                    rootState_active = idle;
                    res = eventConsumed;
                }
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Button_C::pressed_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == held_timeout)
                {
                    if(held_timeout != NULL)
                        {
                            held_timeout->cancel();
                            held_timeout = NULL;
                        }
                    held_subState = pressed;
                    rootState_active = pressed;
                    held_timeout = scheduleTimeout(30, NULL);
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evRelease_StopwatchPkg_id))
        {
            held_exit();
            rootState_subState = idle;
            rootState_active = idle;
            res = eventConsumed;
        }
    
    if(res == eventNotConsumed)
        {
            res = held_handleEvent();
        }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/Linux/Button.cpp
*********************************************************************/
