/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: Monitor
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/Monitor.c
*********************************************************************/

/*## auto_generated */
#include <oxf/RiCTask.h>
/*## auto_generated */
#include "Monitor.h"
/*## link itsUbidots */
#include "Ubidots.h"
/*## package PBLPkg */

/*## class TopLevel::Monitor */


/*#[ ignore */
extern uint32_t RPM;
extern float torque;
/*#]*/


/*## auto_generated */
static void initStatechart(struct Monitor_t* const me);

/*## auto_generated */
static void cleanUpRelations(struct Monitor_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

/*## operation display(unsigned int,float) */
static void display(struct Monitor_t* const me, unsigned int RPM, float torque);

void Monitor_Init(struct Monitor_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl Monitor_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &Monitor_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    me->itsUbidots = NULL;
    initStatechart(me);
}

void Monitor_Cleanup(struct Monitor_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
    cleanUpRelations(me);
}

/*## operation display(unsigned int,float) */
static void display(struct Monitor_t* const me, unsigned int RPM, float torque) {
    /*#[ operation display(unsigned int,float) */
    printf("RPM :%ld \r\ntorque : %.2f\r\n",RPM,torque*0.1); 
    if(RPM>=1000)printf("RPM : warning\r\n");
    else printf("RPM : normal\r\n");
    /*#]*/
}

struct Ubidots_t* Monitor_getItsUbidots(const struct Monitor_t* const me) {
    return (struct Ubidots_t*)me->itsUbidots;
}

void Monitor_setItsUbidots(struct Monitor_t* const me, struct Ubidots_t* p_Ubidots) {
    me->itsUbidots = p_Ubidots;
}

RiCBoolean Monitor_startBehavior(struct Monitor_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct Monitor_t* const me) {
    me->rootState_subState = Monitor_RiCNonState;
    me->rootState_active = Monitor_RiCNonState;
}

static void cleanUpRelations(struct Monitor_t* const me) {
    if(me->itsUbidots != NULL)
        {
            me->itsUbidots = NULL;
        }
}

static void rootState_entDef(void * const void_me) {
    
    struct Monitor_t * const me = (struct Monitor_t *)void_me;
    {
        me->rootState_subState = Monitor_idel;
        me->rootState_active = Monitor_idel;
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct Monitor_t * const me = (struct Monitor_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    if(me->rootState_active == Monitor_idel)
        {
            if(id == evStart_PBLPkg_id)
                {
                    {
                        /*#[ transition 0 */
                        
                        CGEN(me->itsUbidots,evStartWiFi());
                        /*#]*/
                    }
                    me->rootState_subState = Monitor_SmarTTY;
                    me->rootState_active = Monitor_SmarTTY;
                    res = eventConsumed;
                }
        }
    return res;
}

/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/Monitor.c
*********************************************************************/
