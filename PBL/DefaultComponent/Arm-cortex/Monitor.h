/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: Monitor
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/Monitor.h
*********************************************************************/

#ifndef Monitor_H
#define Monitor_H

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

/*## class TopLevel::Monitor */
struct Monitor_t {
    RiCReactive ric_reactive;
    unsigned int RPM;		/*## attribute RPM */
    float torque;		/*## attribute torque */
    struct Ubidots_t* itsUbidots;		/*## link itsUbidots */
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    /*#]*/
};

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Monitor_Init(struct Monitor_t* const me, RiCTask * p_task);

/*## auto_generated */
void Monitor_Cleanup(struct Monitor_t* const me);

/*## auto_generated */
struct Ubidots_t* Monitor_getItsUbidots(const struct Monitor_t* const me);

/*## auto_generated */
void Monitor_setItsUbidots(struct Monitor_t* const me, struct Ubidots_t* p_Ubidots);

/*## auto_generated */
RiCBoolean Monitor_startBehavior(struct Monitor_t* const me);

/* rootState: */
/*## statechart_method */
#define Monitor_rootState_IN(me)    \
    (1)

/* SmarTTY: */
/*## statechart_method */
#define Monitor_SmarTTY_IN(me)    \
    ((me)->rootState_subState == Monitor_SmarTTY)

/* idel: */
/*## statechart_method */
#define Monitor_idel_IN(me)    \
    ((me)->rootState_subState == Monitor_idel)

/*#[ ignore */
enum Monitor_Enum {
    Monitor_RiCNonState = 0,
    Monitor_SmarTTY = 1,
    Monitor_idel = 2
};
/*#]*/

/***    Framework entries    ***/

#endif
/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/Monitor.h
*********************************************************************/
