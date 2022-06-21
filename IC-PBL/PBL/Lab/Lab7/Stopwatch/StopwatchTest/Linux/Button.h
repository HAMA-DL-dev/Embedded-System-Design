/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: Linux
	Model Element	: Button
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/Linux/Button.h
*********************************************************************/

#ifndef Button_H
#define Button_H

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
//## link itsTimer
class Timer_C;

//## package StopwatchPkg

//## class TopLevel::Button
class Button_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Button_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Button_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Timer_C* getItsTimer() const;
    
    //## auto_generated
    void setItsTimer(Timer_C* p_Timer);
    
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
    
    Timer_C* itsTimer;		//## link itsTimer
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // idle:
    //## statechart_method
    inline bool idle_IN() const;
    
    // held:
    //## statechart_method
    inline bool held_IN() const;
    
    //## statechart_method
    void held_entDef();
    
    //## statechart_method
    virtual void held_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus held_handleEvent();
    
    // pressed:
    //## statechart_method
    inline bool pressed_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus pressed_handleEvent();
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Button_Enum {
        OMNonState = 0,
        idle = 1,
        held = 2,
        pressed = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int held_subState;
    
    IOxfTimeout* rootState_timeout;
    
    IOxfTimeout* held_timeout;
//#]
};

inline bool Button_C::rootState_IN() const {
    return true;
}

inline bool Button_C::idle_IN() const {
    return rootState_subState == idle;
}

inline bool Button_C::held_IN() const {
    return rootState_subState == held;
}

inline bool Button_C::pressed_IN() const {
    return held_subState == pressed;
}

#endif
/*********************************************************************
	File Path	: StopwatchTest/Linux/Button.h
*********************************************************************/
