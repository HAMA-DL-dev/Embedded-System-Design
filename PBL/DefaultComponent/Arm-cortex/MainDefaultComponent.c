/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: Arm-cortex
	Model Element	: Arm-cortex
//!	Generated Date	: Wed, 8, Jun 2022  
	File Path	: DefaultComponent/Arm-cortex/MainDefaultComponent.c
*********************************************************************/

/*## auto_generated */
#include "MainDefaultComponent.h"
/*## auto_generated */
#include "PBLPkg.h"
void DefaultComponent_Init(void) {
    PBLPkg_initRelations();
    PBLPkg_startBehavior();
}

void DefaultComponent_Cleanup(void) {
    PBLPkg_OMInitializer_Cleanup();
}

int Cortex_main(int argc, char* argv[]) {
    int status = 0;
    if(RiCOXFInit(argc, argv, 6423, "", 0, 0, RiCTRUE))
        {
            DefaultComponent_Init();
            /*#[ configuration DefaultComponent::Arm-cortex */
            /*#]*/
            RiCOXFStart(FALSE);
            DefaultComponent_Cleanup();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: DefaultComponent/Arm-cortex/MainDefaultComponent.c
*********************************************************************/
