/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: StopwatchPkg
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: Microsoft\DefaultConfig\StopwatchPkg.c
*********************************************************************/

/*## auto_generated */
#include "StopwatchPkg.h"
/*## classInstance Button */
#include "Button.h"
/*## classInstance Display */
#include "Display.h"
/*## classInstance Timer */
#include "Timer.h"
/*## package StopwatchPkg */


/*## classInstance Button */
struct Button_t Button;

/*## classInstance Display */
struct Display_t Display;

/*## classInstance Timer */
struct Timer_t Timer;

void StopwatchPkg_OMInitializer_Init(void) {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

void StopwatchPkg_OMInitializer_Cleanup(void) {
}

void StopwatchPkg_initRelations(void) {
    Button_Init(&(Button), RiCMainTask());
    Display_Init(&(Display));
    Timer_Init(&(Timer), RiCMainTask());
    Button_setItsTimer(&(Button), &(Timer));
    Timer_setItsDisplay(&(Timer), &(Display));
}

RiCBoolean StopwatchPkg_startBehavior(void) {
    RiCBoolean done = RiCTRUE;
    done &= Button_startBehavior(&(Button));
    done &= Timer_startBehavior(&(Timer));
    return done;
}

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evPress, 9, 0, TRUE)

void evPress_Init(evPress* const me) {
    RiCEvent_init(&(me->ric_event), evPress_StopwatchPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evPress);
}

void evPress_Cleanup(evPress* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evPress * RiC_Create_evPress(void) {
    evPress* me = RIC_MEMORY_ALLOCATOR_GET(evPress);
    if(me!=NULL)
        {
            evPress_Init(me);
        }
    return me;
}

void RiC_Destroy_evPress(evPress* const me) {
    if(me!=NULL)
        {
            evPress_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evPress);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evRelease, 9, 0, TRUE)

void evRelease_Init(evRelease* const me) {
    RiCEvent_init(&(me->ric_event), evRelease_StopwatchPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evRelease);
}

void evRelease_Cleanup(evRelease* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evRelease * RiC_Create_evRelease(void) {
    evRelease* me = RIC_MEMORY_ALLOCATOR_GET(evRelease);
    if(me!=NULL)
        {
            evRelease_Init(me);
        }
    return me;
}

void RiC_Destroy_evRelease(evRelease* const me) {
    if(me!=NULL)
        {
            evRelease_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evRelease);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evStartStop, 9, 0, TRUE)

void evStartStop_Init(evStartStop* const me) {
    RiCEvent_init(&(me->ric_event), evStartStop_StopwatchPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evStartStop);
}

void evStartStop_Cleanup(evStartStop* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evStartStop * RiC_Create_evStartStop(void) {
    evStartStop* me = RIC_MEMORY_ALLOCATOR_GET(evStartStop);
    if(me!=NULL)
        {
            evStartStop_Init(me);
        }
    return me;
}

void RiC_Destroy_evStartStop(evStartStop* const me) {
    if(me!=NULL)
        {
            evStartStop_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evStartStop);
}
/*#]*/

RIC_IMPLEMENT_MEMORY_ALLOCATOR(evReset, 9, 0, TRUE)

void evReset_Init(evReset* const me) {
    RiCEvent_init(&(me->ric_event), evReset_StopwatchPkg_id, NULL);
    RIC_SET_EVENT_DESTROY_OP(me, evReset);
}

void evReset_Cleanup(evReset* const me) {
    RiCEvent_cleanup(&(me->ric_event));
}

/*#[ ignore */
evReset * RiC_Create_evReset(void) {
    evReset* me = RIC_MEMORY_ALLOCATOR_GET(evReset);
    if(me!=NULL)
        {
            evReset_Init(me);
        }
    return me;
}

void RiC_Destroy_evReset(evReset* const me) {
    if(me!=NULL)
        {
            evReset_Cleanup(me);
        }
    RIC_MEMORY_ALLOCATOR_RETURN(me, evReset);
}
/*#]*/

/*********************************************************************
	File Path	: Microsoft\DefaultConfig\StopwatchPkg.c
*********************************************************************/
