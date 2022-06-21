/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: Ubidots
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/Ubidots.h
*********************************************************************/

#ifndef Ubidots_H
#define Ubidots_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "RiC_IdfP.h"
/*## auto_generated */
#include "PBLPkg.h"
/*## auto_generated */
#include <oxf/RiCReactive.h>
/*## auto_generated */
#include <oxf/RiCEvent.h>
/*## package PBLPkg */

/*## class TopLevel::Ubidots */
struct Ubidots_t {
    RiCReactive ric_reactive;
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    /*#]*/
};

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Ubidots_Init(struct Ubidots_t* const me, RiCTask * p_task);

/*## auto_generated */
void Ubidots_Cleanup(struct Ubidots_t* const me);

/***    User explicit entries    ***/

/* Operations */

/*## operation WiFi() */
void Ubidots_WiFi(struct Ubidots_t* const me);

/*## auto_generated */
RiCBoolean Ubidots_startBehavior(struct Ubidots_t* const me);

/* rootState: */
/*## statechart_method */
#define Ubidots_rootState_IN(me)    \
    (1)

/* wifi: */
/*## statechart_method */
#define Ubidots_wifi_IN(me)    \
    ((me)->rootState_subState == Ubidots_wifi)

/* idle: */
/*## statechart_method */
#define Ubidots_idle_IN(me)    \
    ((me)->rootState_subState == Ubidots_idle)

/*#[ ignore */
enum Ubidots_Enum {
    Ubidots_RiCNonState = 0,
    Ubidots_wifi = 1,
    Ubidots_idle = 2
};
/*#]*/

/***    Framework entries    ***/

#endif
/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/Ubidots.h
*********************************************************************/
