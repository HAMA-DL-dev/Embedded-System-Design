/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: Button
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: Microsoft\DefaultConfig\Button.h
*********************************************************************/

#ifndef Button_H
#define Button_H

/*## auto_generated */
#include <oxf\Ric.h>
/*## auto_generated */
#include "stdio.h"
/*## auto_generated */
#include "StopwatchPkg.h"
/*## auto_generated */
#include <oxf\RiCReactive.h>
/*## auto_generated */
#include <oxf\RiCEvent.h>
/*#[ ignore */
#define Button_Timeout_pressed_id 2

#define Button_Timeout_held_id 1
/*#]*/

/*## package StopwatchPkg */

/*## class TopLevel::Button */
struct Button_t {
    RiCReactive ric_reactive;
    struct Timer_t* itsTimer;		/*## link itsTimer */
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    unsigned char held_subState;
    /*#]*/
};

/***    User implicit entries    ***/


/* Constructors and destructors:*/

/*## auto_generated */
void Button_Init(struct Button_t* const me, RiCTask * p_task);

/*## auto_generated */
void Button_Cleanup(struct Button_t* const me);

/*## auto_generated */
struct Timer_t* Button_getItsTimer(const struct Button_t* const me);

/*## auto_generated */
void Button_setItsTimer(struct Button_t* const me, struct Timer_t* p_Timer);

/*## auto_generated */
RiCBoolean Button_startBehavior(struct Button_t* const me);

/***    Framework entries    ***/

/* rootState: */
/*## statechart_method */
#define Button_rootState_IN(me)    \
    (1)

/* idle: */
/*## statechart_method */
#define Button_idle_IN(me)    \
    ((me)->rootState_subState == Button_idle)

/* held: */
/*## statechart_method */
#define Button_held_IN(me)    \
    ((me)->rootState_subState == Button_held)

/*## statechart_method */
void Button_held_exit(struct Button_t* const me);

/*## statechart_method */
RiCTakeEventStatus Button_held_takeEvent(struct Button_t* const me, short id);

/* pressed: */
/*## statechart_method */
#define Button_pressed_IN(me)    \
    ((me)->held_subState == Button_pressed)

/*#[ ignore */
enum Button_Enum {
    Button_RiCNonState = 0,
    Button_idle = 1,
    Button_held = 2,
    Button_pressed = 3
};
/*#]*/

#endif
/*********************************************************************
	File Path	: Microsoft\DefaultConfig\Button.h
*********************************************************************/
