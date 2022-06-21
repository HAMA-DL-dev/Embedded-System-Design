/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: Timer
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: Microsoft\DefaultConfig\Timer.c
*********************************************************************/

/*## auto_generated */
#include <oxf\RiCTask.h>
/*## auto_generated */
#include "Timer.h"
/*## link itsDisplay */
#include "Display.h"
/*## package StopwatchPkg */

/*## class TopLevel::Timer */
/*## operation print() */
static void print(struct Timer_t* const me);

/*## operation reset() */
static void reset(struct Timer_t* const me);

/*## operation tick() */
static void tick(struct Timer_t* const me);

/*## auto_generated */
static void initStatechart(struct Timer_t* const me);

/*## auto_generated */
static void cleanUpRelations(struct Timer_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

/*## statechart_method */
static void running_entDef(struct Timer_t* const me);

void Timer_Init(struct Timer_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl Timer_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &Timer_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    me->itsDisplay = NULL;
    initStatechart(me);
}

void Timer_Cleanup(struct Timer_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
    cleanUpRelations(me);
}

/*## operation print() */
static void print(struct Timer_t* const me) {
    /*#[ operation print() */
    Display_print(me->itsDisplay,me->minutes,me->seconds);
    /*#]*/
}

/*## operation reset() */
static void reset(struct Timer_t* const me) {
    /*#[ operation reset() */
    me->seconds=0;
    me->minutes=0;
    /*#]*/
}

/*## operation tick() */
static void tick(struct Timer_t* const me) {
    /*#[ operation tick() */
    me->seconds++;
    if(me->seconds>59){
    	me->seconds=0;
    	me->minutes++;
    }
    /*#]*/
}

struct Display_t* Timer_getItsDisplay(const struct Timer_t* const me) {
    return (struct Display_t*)me->itsDisplay;
}

void Timer_setItsDisplay(struct Timer_t* const me, struct Display_t* p_Display) {
    me->itsDisplay = p_Display;
}

RiCBoolean Timer_startBehavior(struct Timer_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct Timer_t* const me) {
    me->rootState_subState = Timer_RiCNonState;
    me->rootState_active = Timer_RiCNonState;
    me->running_subState = Timer_RiCNonState;
}

static void cleanUpRelations(struct Timer_t* const me) {
    if(me->itsDisplay != NULL)
        {
            me->itsDisplay = NULL;
        }
}

RiCTakeEventStatus Timer_running_takeEvent(struct Timer_t* const me, short id) {
    RiCTakeEventStatus res = eventNotConsumed;
    if(id == evReset_StopwatchPkg_id)
        {
            switch (me->running_subState) {
                case Timer_on:
                {
                    RiCTask_unschedTm(me->ric_reactive.myTask, Timer_Timeout_on_id, &(me->ric_reactive));
                }
                break;
                default:
                    break;
            }
            me->running_subState = Timer_RiCNonState;
            {
                /*#[ transition 0 */
                
                reset(me);print(me);
                /*#]*/
            }
            running_entDef(me);
            res = eventConsumed;
        }
    return res;
}

static void rootState_entDef(void * const void_me) {
    
    struct Timer_t * const me = (struct Timer_t *)void_me;
    {
        running_entDef(me);
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct Timer_t * const me = (struct Timer_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    switch (me->rootState_active) {
        case Timer_off:
        {
            if(id == evStartStop_StopwatchPkg_id)
                {
                    me->running_subState = Timer_on;
                    me->rootState_active = Timer_on;
                    RiCTask_schedTm(me->ric_reactive.myTask, 1000, Timer_Timeout_on_id, &(me->ric_reactive), NULL);
                    res = eventConsumed;
                }
            if(res == eventNotConsumed)
                {
                    res = Timer_running_takeEvent(me, id);
                }
        }
        break;
        case Timer_on:
        {
            switch (id) {
                case Timeout_id:
                {
                    if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == Timer_Timeout_on_id)
                        {
                            RiCTask_unschedTm(me->ric_reactive.myTask, Timer_Timeout_on_id, &(me->ric_reactive));
                            {
                                /*#[ transition 4 */
                                
                                tick(me);print(me);
                                /*#]*/
                            }
                            me->running_subState = Timer_on;
                            me->rootState_active = Timer_on;
                            RiCTask_schedTm(me->ric_reactive.myTask, 1000, Timer_Timeout_on_id, &(me->ric_reactive), NULL);
                            res = eventConsumed;
                        }
                }
                break;
                case evStartStop_StopwatchPkg_id:
                {
                    RiCTask_unschedTm(me->ric_reactive.myTask, Timer_Timeout_on_id, &(me->ric_reactive));
                    me->running_subState = Timer_off;
                    me->rootState_active = Timer_off;
                    res = eventConsumed;
                }
                break;
                default:
                    break;
            }
            if(res == eventNotConsumed)
                {
                    res = Timer_running_takeEvent(me, id);
                }
        }
        break;
        default:
            break;
    }
    return res;
}

static void running_entDef(struct Timer_t* const me) {
    me->rootState_subState = Timer_running;
    {
        /*#[ transition 3 */
        reset(me);
        print(me);
        /*#]*/
    }
    me->running_subState = Timer_on;
    me->rootState_active = Timer_on;
    RiCTask_schedTm(me->ric_reactive.myTask, 1000, Timer_Timeout_on_id, &(me->ric_reactive), NULL);
}

/*********************************************************************
	File Path	: Microsoft\DefaultConfig\Timer.c
*********************************************************************/
