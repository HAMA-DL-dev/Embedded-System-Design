/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Timer
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/Timer.h
*********************************************************************/

#ifndef Timer_H
#define Timer_H

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
//## link itsDisplay
class Display_C;

//## package StopwatchPkg

//## class TopLevel::Timer
class Timer_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Timer_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Timer_C();
    
    ////    Operations    ////
    
    //## operation print()
    void print();
    
    //## operation reset()
    void reset();
    
    //## operation tick()
    void tick();
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getMinutes() const;
    
    //## auto_generated
    void setMinutes(int p_minutes);
    
    //## auto_generated
    int getSeconds() const;
    
    //## auto_generated
    void setSeconds(int p_seconds);
    
    //## auto_generated
    Display_C* getItsDisplay() const;
    
    //## auto_generated
    void setItsDisplay(Display_C* p_Display);
    
    //## auto_generated
    Display_C* getItsDisplay_1() const;
    
    //## auto_generated
    void setItsDisplay_1(Display_C* p_Display);
    
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
    
    ////    Attributes    ////
    
    int minutes;		//## attribute minutes
    
    int seconds;		//## attribute seconds
    
    ////    Relations and components    ////
    
    Display_C* itsDisplay;		//## link itsDisplay
    
    Display_C* itsDisplay_1;		//## link itsDisplay_1
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // running:
    //## statechart_method
    inline bool running_IN() const;
    
    //## statechart_method
    void running_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus running_handleEvent();
    
    // on:
    //## statechart_method
    inline bool on_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus on_handleEvent();
    
    // off:
    //## statechart_method
    inline bool off_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Timer_Enum {
        OMNonState = 0,
        running = 1,
        on = 2,
        off = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int running_subState;
    
    IOxfTimeout* running_timeout;
//#]
};

inline bool Timer_C::rootState_IN() const {
    return true;
}

inline bool Timer_C::running_IN() const {
    return rootState_subState == running;
}

inline bool Timer_C::on_IN() const {
    return running_subState == on;
}

inline bool Timer_C::off_IN() const {
    return running_subState == off;
}

#endif
/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Timer.h
*********************************************************************/
