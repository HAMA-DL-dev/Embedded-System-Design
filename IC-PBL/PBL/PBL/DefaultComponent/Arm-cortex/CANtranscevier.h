/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: CANtranscevier
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/CANtranscevier.h
*********************************************************************/

#ifndef CANtranscevier_H
#define CANtranscevier_H

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

/*## class TopLevel::CANtranscevier */
struct CANtranscevier_t {
    RiCReactive ric_reactive;
    unsigned int RPM;		/*## attribute RPM */
    float torque;		/*## attribute torque */
    struct Monitor_t* itsMonitor;		/*## link itsMonitor */
    struct Ubidots_t* itsUbidots;		/*## link itsUbidots */
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    /*#]*/
};

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void CANtranscevier_Init(struct CANtranscevier_t* const me, RiCTask * p_task);

/*## auto_generated */
void CANtranscevier_Cleanup(struct CANtranscevier_t* const me);

/***    User explicit entries    ***/

/* Operations */

/*## auto_generated */
struct Monitor_t* CANtranscevier_getItsMonitor(const struct CANtranscevier_t* const me);

/*## auto_generated */
void CANtranscevier_setItsMonitor(struct CANtranscevier_t* const me, struct Monitor_t* p_Monitor);

/*## auto_generated */
struct Ubidots_t* CANtranscevier_getItsUbidots(const struct CANtranscevier_t* const me);

/*## auto_generated */
void CANtranscevier_setItsUbidots(struct CANtranscevier_t* const me, struct Ubidots_t* p_Ubidots);

/*## auto_generated */
RiCBoolean CANtranscevier_startBehavior(struct CANtranscevier_t* const me);

/*## operation initCAN() */
void CANtranscevier_initCAN(struct CANtranscevier_t* const me);

/* rootState: */
/*## statechart_method */
#define CANtranscevier_rootState_IN(me)    \
    (1)

/* read: */
/*## statechart_method */
#define CANtranscevier_read_IN(me)    \
    ((me)->rootState_subState == CANtranscevier_read)

/*#[ ignore */
enum CANtranscevier_Enum {
    CANtranscevier_RiCNonState = 0,
    CANtranscevier_read = 1
};
/*#]*/

/***    Framework entries    ***/

#endif
/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/CANtranscevier.h
*********************************************************************/
