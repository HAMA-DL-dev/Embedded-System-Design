/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: rxMessage
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/CANtranscevier.c
*********************************************************************/

/*## auto_generated */
#include <oxf/RiCTask.h>
/*## auto_generated */
#include "CANtranscevier.h"
/*## link itsMonitor */
#include "Monitor.h"
/*## link itsUbidots */
#include "Ubidots.h"
/*## auto_generated */
#include "MCP2515.h"
/*## dependency CANSPI */
#include "CANSPI.h"
/*## auto_generated */
#include "RiC_IdfP.h"
/*## attribute txMessage */
uCAN_MSG txMessage;

/*## attribute rxMessage */
uCAN_MSG rxMessage;

/*## package PBLPkg */

/*## class TopLevel::CANtranscevier */


/*#[ ignore */
extern void CANopen(void);uCAN_MSG txMessage; uCAN_MSG rxMessage; extern uint32_t RPM;
extern float torque;
/*#]*/


/*## auto_generated */
static void initStatechart(struct CANtranscevier_t* const me);

/*## auto_generated */
static void cleanUpRelations(struct CANtranscevier_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

void CANtranscevier_Init(struct CANtranscevier_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl CANtranscevier_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &CANtranscevier_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    me->itsMonitor = NULL;
    me->itsUbidots = NULL;
    initStatechart(me);
}

void CANtranscevier_Cleanup(struct CANtranscevier_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
    cleanUpRelations(me);
}

struct Monitor_t* CANtranscevier_getItsMonitor(const struct CANtranscevier_t* const me) {
    return (struct Monitor_t*)me->itsMonitor;
}

void CANtranscevier_setItsMonitor(struct CANtranscevier_t* const me, struct Monitor_t* p_Monitor) {
    me->itsMonitor = p_Monitor;
}

struct Ubidots_t* CANtranscevier_getItsUbidots(const struct CANtranscevier_t* const me) {
    return (struct Ubidots_t*)me->itsUbidots;
}

void CANtranscevier_setItsUbidots(struct CANtranscevier_t* const me, struct Ubidots_t* p_Ubidots) {
    me->itsUbidots = p_Ubidots;
}

RiCBoolean CANtranscevier_startBehavior(struct CANtranscevier_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct CANtranscevier_t* const me) {
    me->rootState_subState = CANtranscevier_RiCNonState;
    me->rootState_active = CANtranscevier_RiCNonState;
}

static void cleanUpRelations(struct CANtranscevier_t* const me) {
    if(me->itsMonitor != NULL)
        {
            me->itsMonitor = NULL;
        }
    if(me->itsUbidots != NULL)
        {
            me->itsUbidots = NULL;
        }
}

/*## operation initCAN() */
void CANtranscevier_initCAN(struct CANtranscevier_t* const me) {
    /*#[ operation initCAN() */
    CANopen();
    /*#]*/
}

static void rootState_entDef(void * const void_me) {
    
    struct CANtranscevier_t * const me = (struct CANtranscevier_t *)void_me;
    {
        {
            /*#[ transition 0 */
            CGEN(me->itsMonitor,evStart())
			CANopen();
            /*#]*/
        }
        me->rootState_subState = CANtranscevier_read;
        me->rootState_active = CANtranscevier_read;
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct CANtranscevier_t * const me = (struct CANtranscevier_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    return res;
}

/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/CANtranscevier.c
*********************************************************************/
