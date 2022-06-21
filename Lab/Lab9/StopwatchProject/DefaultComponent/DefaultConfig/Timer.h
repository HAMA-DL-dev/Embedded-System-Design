/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Timer
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\Timer.h
*********************************************************************/

#ifndef Timer_H
#define Timer_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include "StopwatchPkg.h"
//## link itsButton
class Button_C;

//## link itsDisplay
class Display_C;

//## package StopwatchPkg

//## class TopLevel::Timer
class Timer_C {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Timer_C();
    
    //## auto_generated
    ~Timer_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Button_C* getItsButton() const;
    
    //## auto_generated
    void setItsButton(Button_C* p_Button);
    
    //## auto_generated
    Display_C* getItsDisplay() const;
    
    //## auto_generated
    void setItsDisplay(Display_C* p_Display);

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Button_C* itsButton;		//## link itsButton
    
    Display_C* itsDisplay;		//## link itsDisplay
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsButton(Button_C* p_Button);
    
    //## auto_generated
    void _setItsButton(Button_C* p_Button);
    
    //## auto_generated
    void _clearItsButton();
    
    //## auto_generated
    void __setItsDisplay(Display_C* p_Display);
    
    //## auto_generated
    void _setItsDisplay(Display_C* p_Display);
    
    //## auto_generated
    void _clearItsDisplay();
};

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Timer.h
*********************************************************************/
