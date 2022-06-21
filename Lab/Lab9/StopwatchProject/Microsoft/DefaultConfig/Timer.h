/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: Timer
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: Microsoft\DefaultConfig\Timer.h
*********************************************************************/

#ifndef Timer_H
#define Timer_H

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
#define Timer_Timeout_on_id 1
/*#]*/

/*## package StopwatchPkg */

/*## class TopLevel::Timer */
struct Timer_t {
    RiCReactive ric_reactive;
    int minutes;		/*## attribute minutes */
    int seconds;		/*## attribute seconds */
    struct Display_t* itsDisplay;		/*## link itsDisplay */
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    unsigned char running_subState;
    /*#]*/
};

/***    User implicit entries    ***/


/* Constructors and destructors:*/

/*## auto_generated */
void Timer_Init(struct Timer_t* const me, RiCTask * p_task);

/*## auto_generated */
void Timer_Cleanup(struct Timer_t* const me);

/*## auto_generated */
struct Display_t* Timer_getItsDisplay(const struct Timer_t* const me);

/*## auto_generated */
void Timer_setItsDisplay(struct Timer_t* const me, struct Display_t* p_Display);

/*## auto_generated */
RiCBoolean Timer_startBehavior(struct Timer_t* const me);

/***    Framework entries    ***/

/* rootState: */
/*## statechart_method */
#define Timer_rootState_IN(me)    \
    (1)

/* running: */
/*## statechart_method */
#define Timer_running_IN(me)    \
    ((me)->rootState_subState == Timer_running)

/*## statechart_method */
RiCTakeEventStatus Timer_running_takeEvent(struct Timer_t* const me, short id);

/* on: */
/*## statechart_method */
#define Timer_on_IN(me)    \
    ((me)->running_subState == Timer_on)

/* off: */
/*## statechart_method */
#define Timer_off_IN(me)    \
    ((me)->running_subState == Timer_off)

/*#[ ignore */
enum Timer_Enum {
    Timer_RiCNonState = 0,
    Timer_running = 1,
    Timer_on = 2,
    Timer_off = 3
};
/*#]*/

#endif
/*********************************************************************
	File Path	: Microsoft\DefaultConfig\Timer.h
*********************************************************************/
