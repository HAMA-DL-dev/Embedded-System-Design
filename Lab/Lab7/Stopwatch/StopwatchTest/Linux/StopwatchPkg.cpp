/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: Linux
	Model Element	: StopwatchPkg
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/Linux/StopwatchPkg.cpp
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
    {
        {
            Button.setShouldDelete(false);
        }
        {
            Timer.setShouldDelete(false);
        }
    }
    Button.setItsTimer(&Timer);
    Timer.setItsDisplay(&Display);
}

bool StopwatchPkg_startBehavior() {
    bool done = true;
    done &= Button.startBehavior();
    done &= Timer.startBehavior();
    return done;
}

//#[ ignore
StopwatchPkg_OMInitializer::StopwatchPkg_OMInitializer() {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

StopwatchPkg_OMInitializer::~StopwatchPkg_OMInitializer() {
}
//#]

//## event evPressed()
evPressed::evPressed() {
    setId(evPressed_StopwatchPkg_id);
}

bool evPressed::isTypeOf(short id) const {
    return (evPressed_StopwatchPkg_id==id);
}

//## event evRelease()
evRelease::evRelease() {
    setId(evRelease_StopwatchPkg_id);
}

bool evRelease::isTypeOf(short id) const {
    return (evRelease_StopwatchPkg_id==id);
}

//## event evReset()
evReset::evReset() {
    setId(evReset_StopwatchPkg_id);
}

bool evReset::isTypeOf(short id) const {
    return (evReset_StopwatchPkg_id==id);
}

//## event evStartStop()
evStartStop::evStartStop() {
    setId(evStartStop_StopwatchPkg_id);
}

bool evStartStop::isTypeOf(short id) const {
    return (evStartStop_StopwatchPkg_id==id);
}

/*********************************************************************
	File Path	: StopwatchTest/Linux/StopwatchPkg.cpp
*********************************************************************/
