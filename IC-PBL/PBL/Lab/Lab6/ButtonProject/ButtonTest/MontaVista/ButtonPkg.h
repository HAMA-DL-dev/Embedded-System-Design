/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: ButtonPkg
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: ButtonTest/MontaVista/ButtonPkg.h
*********************************************************************/

#ifndef ButtonPkg_H
#define ButtonPkg_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <oxf/event.h>
//## classInstance Button
class Button_C;

//## classInstance Led
class Led_C;

//## classInstance PushSwitch
class PushSwitch_C;

//#[ ignore
#define evReset_ButtonPkg_id 10401

#define evStartStop_ButtonPkg_id 10402

#define evPress_ButtonPkg_id 10403

#define evRelease_ButtonPkg_id 10404

#define evChange_ButtonPkg_id 10405
//#]

//## package ButtonPkg


//## classInstance Button
extern Button_C Button;

//## classInstance Led
extern Led_C Led;

//## classInstance PushSwitch
extern PushSwitch_C PushSwitch;

//## auto_generated
void ButtonPkg_initRelations();

//## auto_generated
bool ButtonPkg_startBehavior();

//#[ ignore
class ButtonPkg_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    ButtonPkg_OMInitializer();
    
    //## auto_generated
    ~ButtonPkg_OMInitializer();
};
//#]

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

//## event evPress()
class evPress : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evPress();
    
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

//## event evChange()
class evChange : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evChange();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

#endif
/*********************************************************************
	File Path	: ButtonTest/MontaVista/ButtonPkg.h
*********************************************************************/
