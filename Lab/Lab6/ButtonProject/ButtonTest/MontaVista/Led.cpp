/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: Led
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: ButtonTest/MontaVista/Led.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Led.h"
//## package ButtonPkg

//## class TopLevel::Led

extern void onLed(unsigned char);extern int initLed(void);

Led_C::Led_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    initStatechart();
}

Led_C::~Led_C() {
}

bool Led_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Led_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Led_C::rootState_entDef() {
    {
        //#[ transition 0 
        initLed();
        //#]
        rootState_subState = On;
        rootState_active = On;
        //#[ state ROOT.On.(Entry) 
        onLed(1);
        //#]
    }
}

IOxfReactive::TakeEventStatus Led_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case On:
        {
            if(IS_EVENT_TYPE_OF(evChange_ButtonPkg_id))
                {
                    rootState_subState = Off;
                    rootState_active = Off;
                    //#[ state ROOT.Off.(Entry) 
                    onLed(0);
                    //#]
                    res = eventConsumed;
                }
            
        }
        break;
        case Off:
        {
            if(IS_EVENT_TYPE_OF(evChange_ButtonPkg_id))
                {
                    rootState_subState = On;
                    rootState_active = On;
                    //#[ state ROOT.On.(Entry) 
                    onLed(1);
                    //#]
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

/*********************************************************************
	File Path	: ButtonTest/MontaVista/Led.cpp
*********************************************************************/
