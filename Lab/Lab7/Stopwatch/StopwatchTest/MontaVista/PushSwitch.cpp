/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: PushSwitch
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/PushSwitch.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "PushSwitch.h"
//## link itsButton
#include "Button.h"
//## package StopwatchPkg

//## class TopLevel::PushSwitch

extern int initButton(void);extern unsigned char readButton(void);

PushSwitch_C::PushSwitch_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsButton = NULL;
    initStatechart();
}

PushSwitch_C::~PushSwitch_C() {
    cleanUpRelations();
    cancelTimeouts();
}

Button_C* PushSwitch_C::getItsButton() const {
    return itsButton;
}

void PushSwitch_C::setItsButton(Button_C* p_Button) {
    itsButton = p_Button;
}

bool PushSwitch_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void PushSwitch_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    rootState_timeout = NULL;
}

void PushSwitch_C::cleanUpRelations() {
    if(itsButton != NULL)
        {
            itsButton = NULL;
        }
}

void PushSwitch_C::cancelTimeouts() {
    if(rootState_timeout != NULL)
        {
            rootState_timeout->cancel();
            rootState_timeout = NULL;
        }
}

bool PushSwitch_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

void PushSwitch_C::rootState_entDef() {
    {
        //#[ transition 0 
        initButton();
        //#]
        rootState_subState = ReadSwitch;
        rootState_active = ReadSwitch;
        //#[ state ROOT.ReadSwitch.(Entry) 
        if (!readButton()) Button.GEN(evPressed);
        //#]
        rootState_timeout = scheduleTimeout(30, NULL);
    }
}

IOxfReactive::TakeEventStatus PushSwitch_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(rootState_active == ReadSwitch)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            if(rootState_timeout != NULL)
                                {
                                    rootState_timeout->cancel();
                                    rootState_timeout = NULL;
                                }
                            rootState_subState = ReadSwitch;
                            rootState_active = ReadSwitch;
                            //#[ state ROOT.ReadSwitch.(Entry) 
                            if (!readButton()) Button.GEN(evPressed);
                            //#]
                            rootState_timeout = scheduleTimeout(30, NULL);
                            res = eventConsumed;
                        }
                }
            
        }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/PushSwitch.cpp
*********************************************************************/
