/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Timer
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/Timer.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Timer.h"
//## link itsDisplay
#include "Display.h"
//## package StopwatchPkg

//## class TopLevel::Timer
Timer_C::Timer_C(IOxfActive* theActiveContext) : minutes(0), seconds(0) {
    setActiveContext(theActiveContext, false);
    itsDisplay = NULL;
    itsDisplay_1 = NULL;
    initStatechart();
}

Timer_C::~Timer_C() {
    cleanUpRelations();
    cancelTimeouts();
}

void Timer_C::print() {
    //#[ operation print()
    Display.print(minutes,seconds);
    //#]
}

void Timer_C::reset() {
    //#[ operation reset()
    minutes = 0;
    seconds = 0;
    //#]
}

void Timer_C::tick() {
    //#[ operation tick()
    seconds++;
    if(seconds>59){
    	seconds = 0;
    	minutes++;
    }
    
    //#]
}

int Timer_C::getMinutes() const {
    return minutes;
}

void Timer_C::setMinutes(int p_minutes) {
    minutes = p_minutes;
}

int Timer_C::getSeconds() const {
    return seconds;
}

void Timer_C::setSeconds(int p_seconds) {
    seconds = p_seconds;
}

Display_C* Timer_C::getItsDisplay() const {
    return itsDisplay;
}

void Timer_C::setItsDisplay(Display_C* p_Display) {
    itsDisplay = p_Display;
}

Display_C* Timer_C::getItsDisplay_1() const {
    return itsDisplay_1;
}

void Timer_C::setItsDisplay_1(Display_C* p_Display) {
    itsDisplay_1 = p_Display;
}

bool Timer_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Timer_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    running_subState = OMNonState;
    running_timeout = NULL;
}

void Timer_C::cleanUpRelations() {
    if(itsDisplay != NULL)
        {
            itsDisplay = NULL;
        }
    if(itsDisplay_1 != NULL)
        {
            itsDisplay_1 = NULL;
        }
}

void Timer_C::cancelTimeouts() {
    if(running_timeout != NULL)
        {
            running_timeout->cancel();
            running_timeout = NULL;
        }
}

bool Timer_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(running_timeout == arg)
        {
            running_timeout = NULL;
            res = true;
        }
    return res;
}

void Timer_C::rootState_entDef() {
    {
        running_entDef();
    }
}

IOxfReactive::TakeEventStatus Timer_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case off:
        {
            if(IS_EVENT_TYPE_OF(evStartStop_StopwatchPkg_id))
                {
                    running_subState = on;
                    rootState_active = on;
                    running_timeout = scheduleTimeout(1000, NULL);
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = running_handleEvent();
                }
        }
        break;
        case on:
        {
            res = on_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

void Timer_C::running_entDef() {
    rootState_subState = running;
    //#[ transition 1 
    reset();print();
    //#]
    running_subState = on;
    rootState_active = on;
    running_timeout = scheduleTimeout(1000, NULL);
}

IOxfReactive::TakeEventStatus Timer_C::running_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evReset_StopwatchPkg_id))
        {
            switch (running_subState) {
                case on:
                {
                    if(running_timeout != NULL)
                        {
                            running_timeout->cancel();
                            running_timeout = NULL;
                        }
                }
                break;
                default:
                    break;
            }
            running_subState = OMNonState;
            //#[ transition 0 
            
            reset();print();
            //#]
            running_entDef();
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Timer_C::on_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == running_timeout)
                {
                    if(running_timeout != NULL)
                        {
                            running_timeout->cancel();
                            running_timeout = NULL;
                        }
                    //#[ transition 2 
                    
                    tick();print();
                    //#]
                    running_subState = on;
                    rootState_active = on;
                    running_timeout = scheduleTimeout(1000, NULL);
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evStartStop_StopwatchPkg_id))
        {
            if(running_timeout != NULL)
                {
                    running_timeout->cancel();
                    running_timeout = NULL;
                }
            running_subState = off;
            rootState_active = off;
            res = eventConsumed;
        }
    
    if(res == eventNotConsumed)
        {
            res = running_handleEvent();
        }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Timer.cpp
*********************************************************************/
