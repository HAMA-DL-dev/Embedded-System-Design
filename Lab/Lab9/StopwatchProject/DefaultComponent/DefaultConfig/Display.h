/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Display
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\Display.h
*********************************************************************/

#ifndef Display_H
#define Display_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include "StopwatchPkg.h"
//## link itsTimer
class Timer_C;

//## package StopwatchPkg

//## class TopLevel::Display
class Display_C {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Display_C();
    
    //## auto_generated
    ~Display_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Timer_C* getItsTimer() const;
    
    //## auto_generated
    void setItsTimer(Timer_C* p_Timer);

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Timer_C* itsTimer;		//## link itsTimer
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsTimer(Timer_C* p_Timer);
    
    //## auto_generated
    void _setItsTimer(Timer_C* p_Timer);
    
    //## auto_generated
    void _clearItsTimer();
};

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Display.h
*********************************************************************/
