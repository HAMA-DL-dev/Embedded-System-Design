/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: Ubidots
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/Ubidots.c
*********************************************************************/

/*## auto_generated */
#include <oxf/RiCTask.h>
/*## auto_generated */
#include "Ubidots.h"
/*## auto_generated */
#include "wifi_ubidots.h"
/*## package PBLPkg */

/*## class TopLevel::Ubidots */


/*#[ ignore */
extern uint32_t RPM;
extern float torque;extern void WifiSetup(void);extern void WifiUbidots(void);
/*#]*/


/*## auto_generated */
static void initStatechart(struct Ubidots_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

void Ubidots_Init(struct Ubidots_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl Ubidots_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &Ubidots_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    initStatechart(me);
}

void Ubidots_Cleanup(struct Ubidots_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
}

/*## operation WiFi() */
void Ubidots_WiFi(struct Ubidots_t* const me) {
    /*#[ operation WiFi() */
    WifiSetup();
    WifiUbidots();
    /*#]*/
}

RiCBoolean Ubidots_startBehavior(struct Ubidots_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct Ubidots_t* const me) {
    me->rootState_subState = Ubidots_RiCNonState;
    me->rootState_active = Ubidots_RiCNonState;
}

static void rootState_entDef(void * const void_me) {
    
    struct Ubidots_t * const me = (struct Ubidots_t *)void_me;
    {
        me->rootState_subState = Ubidots_idle;
        me->rootState_active = Ubidots_idle;
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct Ubidots_t * const me = (struct Ubidots_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    if(me->rootState_active == Ubidots_idle)
        {
            if(id == evStartWiFi_PBLPkg_id)
                {
                    {
                        /*#[ transition 1 */
                        WifiSetup();
                        WifiUbidots();
                        /*#]*/
                    }
                    me->rootState_subState = Ubidots_wifi;
                    me->rootState_active = Ubidots_wifi;
                    res = eventConsumed;
                }
        }
    return res;
}

/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/Ubidots.c
*********************************************************************/
