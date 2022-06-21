/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: PushSwitch
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/PushSwitch.h
*********************************************************************/

#ifndef PushSwitch_H
#define PushSwitch_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include "StopwatchPkg.h"
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## link itsButton
class Button_C;

//## package StopwatchPkg

//## class TopLevel::PushSwitch
class PushSwitch_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    PushSwitch_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~PushSwitch_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Button_C* getItsButton() const;
    
    //## auto_generated
    void setItsButton(Button_C* p_Button);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);
    
    ////    Relations and components    ////
    
    Button_C* itsButton;		//## link itsButton
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // ReadSwitch:
    //## statechart_method
    inline bool ReadSwitch_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum PushSwitch_Enum {
        OMNonState = 0,
        ReadSwitch = 1
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    IOxfTimeout* rootState_timeout;
//#]
};

inline bool PushSwitch_C::rootState_IN() const {
    return true;
}

inline bool PushSwitch_C::ReadSwitch_IN() const {
    return rootState_subState == ReadSwitch;
}

#endif
/*********************************************************************
	File Path	: StopwatchTest/MontaVista/PushSwitch.h
*********************************************************************/
