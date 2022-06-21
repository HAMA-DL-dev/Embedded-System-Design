/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: Led
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: ButtonTest/MontaVista/Led.h
*********************************************************************/

#ifndef Led_H
#define Led_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include "ButtonPkg.h"
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## package ButtonPkg

//## class TopLevel::Led
class Led_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Led_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Led_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // On:
    //## statechart_method
    inline bool On_IN() const;
    
    // Off:
    //## statechart_method
    inline bool Off_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Led_Enum {
        OMNonState = 0,
        On = 1,
        Off = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

inline bool Led_C::rootState_IN() const {
    return true;
}

inline bool Led_C::On_IN() const {
    return rootState_subState == On;
}

inline bool Led_C::Off_IN() const {
    return rootState_subState == Off;
}

#endif
/*********************************************************************
	File Path	: ButtonTest/MontaVista/Led.h
*********************************************************************/
