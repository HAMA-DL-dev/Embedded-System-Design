/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: HaYeon
	Component	: Microsoft 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: Microsoft\DefaultConfig\MainMicrosoft.c
*********************************************************************/

/*## auto_generated */
#include "MainMicrosoft.h"
/*## auto_generated */
#include "StopwatchPkg.h"
void Microsoft_Init(void) {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

void Microsoft_Cleanup(void) {
    StopwatchPkg_OMInitializer_Cleanup();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(RiCOXFInit(argc, argv, 6423, "", 0, 0, RiCTRUE))
        {
            Microsoft_Init();
            /*#[ configuration Microsoft::DefaultConfig */
            /*#]*/
            RiCOXFStart(FALSE);
            Microsoft_Cleanup();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: Microsoft\DefaultConfig\MainMicrosoft.c
*********************************************************************/
