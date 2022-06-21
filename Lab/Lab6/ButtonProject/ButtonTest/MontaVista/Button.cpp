/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: Button
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: ButtonTest/MontaVista/Button.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Button.h"
//## link itsLed
#include "Led.h"
//## package ButtonPkg

//## class TopLevel::Button

extern  unsigned char readButton(void);

Button_C::Button_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsLed = NULL;
    initStatechart();
}

Button_C::~Button_C() {
    cleanUpRelations();
    cancelTimeouts();
}

Led_C* Button_C::getItsLed() const {
    return itsLed;
}

void Button_C::setItsLed(Led_C* p_Led) {
    itsLed = p_Led;
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
    held_timeout = NULL;
}

void Button_C::cleanUpRelations() {
    if(itsLed != NULL)
        {
            itsLed = NULL;
        }
}

void Button_C::cancelTimeouts() {
    if(held_timeout != NULL)
        {
            held_timeout->cancel();
            held_timeout = NULL;
        }
}

bool Button_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
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
            if(IS_EVENT_TYPE_OF(evPress_ButtonPkg_id))
                {
                    //#[ transition 0 
                    
                    Led.GEN(evChange);
                    //#]
                    rootState_subState = held;
                    held_subState = pressed;
                    rootState_active = pressed;
                    //#[ state ROOT.held.pressed.(Entry) 
                    if (readButton()) Button.GEN(evRelease);
                    
                    //#]
                    held_timeout = scheduleTimeout(30, NULL);
                    res = eventConsumed;
                }
            
        }
        break;
        case pressed:
        {
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
                            //#[ state ROOT.held.pressed.(Entry) 
                            if (readButton()) Button.GEN(evRelease);
                            
                            //#]
                            held_timeout = scheduleTimeout(30, NULL);
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evRelease_ButtonPkg_id))
                {
                    held_exit();
                    rootState_subState = idle;
                    rootState_active = idle;
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void Button_C::held_entDef() {
    rootState_subState = held;
    held_subState = pressed;
    rootState_active = pressed;
    //#[ state ROOT.held.pressed.(Entry) 
    if (readButton()) Button.GEN(evRelease);
    
    //#]
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
    
}

/*********************************************************************
	File Path	: ButtonTest/MontaVista/Button.cpp
*********************************************************************/
