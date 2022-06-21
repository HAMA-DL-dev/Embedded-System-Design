/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: StopwatchPkg
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/StopwatchPkg.h
*********************************************************************/

#ifndef StopwatchPkg_H
#define StopwatchPkg_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <oxf/event.h>
//## classInstance Button
class Button_C;

//## classInstance Display
class Display_C;

//## classInstance PushSwitch
class PushSwitch_C;

//## classInstance Timer
class Timer_C;

//#[ ignore
#define evPressed_StopwatchPkg_id 10401

#define evRelease_StopwatchPkg_id 10402

#define evReset_StopwatchPkg_id 10403

#define evStartStop_StopwatchPkg_id 10404
//#]

//## package StopwatchPkg


//## classInstance Button
extern Button_C Button;

//## classInstance Display
extern Display_C Display;

//## classInstance PushSwitch
extern PushSwitch_C PushSwitch;

//## classInstance Timer
extern Timer_C Timer;

//## auto_generated
void StopwatchPkg_initRelations();

//## auto_generated
bool StopwatchPkg_startBehavior();

//#[ ignore
class StopwatchPkg_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    StopwatchPkg_OMInitializer();
    
    //## auto_generated
    ~StopwatchPkg_OMInitializer();
};
//#]

//## event evPressed()
class evPressed : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evPressed();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evRelease()
class evRelease : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evRelease();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evReset()
class evReset : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evReset();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evStartStop()
class evStartStop : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evStartStop();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

#endif
/*********************************************************************
	File Path	: StopwatchTest/MontaVista/StopwatchPkg.h
*********************************************************************/
