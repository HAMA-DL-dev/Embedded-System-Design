/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: PBLPkg
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/PBLPkg.c
*********************************************************************/

/*## auto_generated */
#include "PBLPkg.h"
/*## classInstance CANtranscevier */
#include "CANtranscevier.h"
/*## classInstance Monitor */
#include "Monitor.h"
/*## classInstance Ubidots */
#include "Ubidots.h"
/*## package PBLPkg */


/*## classInstance Ubidots */
struct Ubidots_t Ubidots;

void PBLPkg_OMInitializer_Init(void) {
    PBLPkg_initRelations();
    PBLPkg_startBehavior();
}

void PBLPkg_OMInitializer_Cleanup(void) {
}

void PBLPkg_initRelations(void) {
    CANtranscevier_Init(&(CANtranscevier), RiCMainTask());
    Monitor_Init(&(Monitor), RiCMainTask());
    Ubidots_Init(&(Ubidots), RiCMainTask());
    CANtranscevier_setItsMonitor(&(CANtranscevier), &(Monitor));
    CANtranscevier_setItsUbidots(&(CANtranscevier), &(Ubidots));
    Monitor_setItsUbidots(&(Monitor), &(Ubidots));
}

RiCBoolean PBLPkg_startBehavior(void) {
    RiCBoolean done = RiCTRUE;
    done &= CANtranscevier_startBehavior(&(CANtranscevier));
    done &= Monitor_startBehavior(&(Monitor));
    done &= Ubidots_startBehavior(&(Ubidots));
    return done;
}

/*## classInstance CANtranscevier */
struct CANtranscevier_t CANtranscevier;

/*## classInstance Monitor */
struct Monitor_t Monitor;

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evReceivedCAN, 9, 0, TRUE)

void evReceivedCAN_Init(evReceivedCAN* const me) {
    RiCEvent_init(&(me->ric_event), evReceivedCAN_PBLPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evReceivedCAN);
}

void evReceivedCAN_Cleanup(evReceivedCAN* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evReceivedCAN * RiC_Create_evReceivedCAN(void) {
    evReceivedCAN* me = RIC_MEMORY_ALLOCATOR_GET(evReceivedCAN);
    if(me!=NULL)
        {
            evReceivedCAN_Init(me);
        }
    return me;
}

void RiC_Destroy_evReceivedCAN(evReceivedCAN* const me) {
    if(me!=NULL)
        {
            evReceivedCAN_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evReceivedCAN);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evReceiveMsg, 9, 0, TRUE)

void evReceiveMsg_Init(evReceiveMsg* const me) {
    RiCEvent_init(&(me->ric_event), evReceiveMsg_PBLPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evReceiveMsg);
}

void evReceiveMsg_Cleanup(evReceiveMsg* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evReceiveMsg * RiC_Create_evReceiveMsg(void) {
    evReceiveMsg* me = RIC_MEMORY_ALLOCATOR_GET(evReceiveMsg);
    if(me!=NULL)
        {
            evReceiveMsg_Init(me);
        }
    return me;
}

void RiC_Destroy_evReceiveMsg(evReceiveMsg* const me) {
    if(me!=NULL)
        {
            evReceiveMsg_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evReceiveMsg);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evStart, 9, 0, TRUE)

void evStart_Init(evStart* const me) {
    RiCEvent_init(&(me->ric_event), evStart_PBLPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evStart);
}

void evStart_Cleanup(evStart* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evStart * RiC_Create_evStart(void) {
    evStart* me = RIC_MEMORY_ALLOCATOR_GET(evStart);
    if(me!=NULL)
        {
            evStart_Init(me);
        }
    return me;
}

void RiC_Destroy_evStart(evStart* const me) {
    if(me!=NULL)
        {
            evStart_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evStart);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evStartWiFi, 9, 0, TRUE)

void evStartWiFi_Init(evStartWiFi* const me) {
    RiCEvent_init(&(me->ric_event), evStartWiFi_PBLPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evStartWiFi);
}

void evStartWiFi_Cleanup(evStartWiFi* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evStartWiFi * RiC_Create_evStartWiFi(void) {
    evStartWiFi* me = RIC_MEMORY_ALLOCATOR_GET(evStartWiFi);
    if(me!=NULL)
        {
            evStartWiFi_Init(me);
        }
    return me;
}

void RiC_Destroy_evStartWiFi(evStartWiFi* const me) {
    if(me!=NULL)
        {
            evStartWiFi_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evStartWiFi);
}
/*#]*/

/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/PBLPkg.c
*********************************************************************/
