/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: ButtonPkg
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: ButtonTest/MontaVista/ButtonPkg.cpp
*********************************************************************/

//## auto_generated
#include "ButtonPkg.h"
//## classInstance Button
#include "Button.h"
//## classInstance Led
#include "Led.h"
//## classInstance PushSwitch
#include "PushSwitch.h"
//## package ButtonPkg


//## classInstance Button
Button_C Button;

//## classInstance Led
Led_C Led;

//## classInstance PushSwitch
PushSwitch_C PushSwitch;

void ButtonPkg_initRelations() {
    {
        {
            Button.setShouldDelete(false);
        }
        {
            Led.setShouldDelete(false);
        }
        {
            PushSwitch.setShouldDelete(false);
        }
    }
    PushSwitch.setItsButton(&Button);
    Button.setItsLed(&Led);
}

bool ButtonPkg_startBehavior() {
    bool done = true;
    done &= Button.startBehavior();
    done &= Led.startBehavior();
    done &= PushSwitch.startBehavior();
    return done;
}

//#[ ignore
ButtonPkg_OMInitializer::ButtonPkg_OMInitializer() {
    ButtonPkg_initRelations();
    ButtonPkg_startBehavior();
}

ButtonPkg_OMInitializer::~ButtonPkg_OMInitializer() {
}
//#]

//## event evReset()
evReset::evReset() {
    setId(evReset_ButtonPkg_id);
}

bool evReset::isTypeOf(short id) const {
    return (evReset_ButtonPkg_id==id);
}

//## event evStartStop()
evStartStop::evStartStop() {
    setId(evStartStop_ButtonPkg_id);
}

bool evStartStop::isTypeOf(short id) const {
    return (evStartStop_ButtonPkg_id==id);
}

//## event evPress()
evPress::evPress() {
    setId(evPress_ButtonPkg_id);
}

bool evPress::isTypeOf(short id) const {
    return (evPress_ButtonPkg_id==id);
}

//## event evRelease()
evRelease::evRelease() {
    setId(evRelease_ButtonPkg_id);
}

bool evRelease::isTypeOf(short id) const {
    return (evRelease_ButtonPkg_id==id);
}

//## event evChange()
evChange::evChange() {
    setId(evChange_ButtonPkg_id);
}

bool evChange::isTypeOf(short id) const {
    return (evChange_ButtonPkg_id==id);
}

/*********************************************************************
	File Path	: ButtonTest/MontaVista/ButtonPkg.cpp
*********************************************************************/
