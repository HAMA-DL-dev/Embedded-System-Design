/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: PBLPkg
//!	Generated Date	: Thu, 9, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/PBLPkg.h
*********************************************************************/

#ifndef PBLPkg_H
#define PBLPkg_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "RiC_IdfP.h"
/*## auto_generated */
#include <oxf/MemAlloc.h>
/*## auto_generated */
#include <oxf/RiCEvent.h>
/*#[ ignore */
#define evReceivedCAN_PBLPkg_id 10001

#define evReceiveMsg_PBLPkg_id 10002

#define evStart_PBLPkg_id 10003

#define evStartWiFi_PBLPkg_id 10004
/*#]*/

/*## package PBLPkg */


/*## classInstance CANtranscevier */
extern struct CANtranscevier_t CANtranscevier;

/*## classInstance Monitor */
extern struct Monitor_t Monitor;

/*## classInstance Ubidots */
extern struct Ubidots_t Ubidots;

/*## auto_generated */
void PBLPkg_OMInitializer_Init(void);

/*## auto_generated */
void PBLPkg_OMInitializer_Cleanup(void);

/*## auto_generated */
void PBLPkg_initRelations(void);

/*## auto_generated */
RiCBoolean PBLPkg_startBehavior(void);

typedef struct evReceivedCAN evReceivedCAN;
/*## event evReceivedCAN() */
struct evReceivedCAN {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evReceivedCAN)
};

/*## auto_generated */
void evReceivedCAN_Init(evReceivedCAN* const me);

/*## auto_generated */
void evReceivedCAN_Cleanup(evReceivedCAN* const me);

/*#[ ignore */
evReceivedCAN * RiC_Create_evReceivedCAN(void);

void RiC_Destroy_evReceivedCAN(evReceivedCAN* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evReceivedCAN)

typedef struct evReceiveMsg evReceiveMsg;
/*## event evReceiveMsg() */
struct evReceiveMsg {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evReceiveMsg)
};

/*## auto_generated */
void evReceiveMsg_Init(evReceiveMsg* const me);

/*## auto_generated */
void evReceiveMsg_Cleanup(evReceiveMsg* const me);

/*#[ ignore */
evReceiveMsg * RiC_Create_evReceiveMsg(void);

void RiC_Destroy_evReceiveMsg(evReceiveMsg* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evReceiveMsg)

typedef struct evStart evStart;
/*## event evStart() */
struct evStart {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evStart)
};

/*## auto_generated */
void evStart_Init(evStart* const me);

/*## auto_generated */
void evStart_Cleanup(evStart* const me);

/*#[ ignore */
evStart * RiC_Create_evStart(void);

void RiC_Destroy_evStart(evStart* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evStart)

typedef struct evStartWiFi evStartWiFi;
/*## event evStartWiFi() */
struct evStartWiFi {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evStartWiFi)
};

/*## auto_generated */
void evStartWiFi_Init(evStartWiFi* const me);

/*## auto_generated */
void evStartWiFi_Cleanup(evStartWiFi* const me);

/*#[ ignore */
evStartWiFi * RiC_Create_evStartWiFi(void);

void RiC_Destroy_evStartWiFi(evStartWiFi* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evStartWiFi)

#endif
/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/PBLPkg.h
*********************************************************************/
