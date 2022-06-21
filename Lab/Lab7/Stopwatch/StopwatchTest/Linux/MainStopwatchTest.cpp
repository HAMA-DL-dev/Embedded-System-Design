/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: Linux
	Model Element	: Linux
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/Linux/MainStopwatchTest.cpp
*********************************************************************/

//## auto_generated
#include "MainStopwatchTest.h"
//## auto_generated
#include "StopwatchPkg.h"
StopwatchTest::StopwatchTest() {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize(argc, argv, 6423))
        {
            StopwatchTest initializer_StopwatchTest;
            //#[ configuration StopwatchTest::Linux 
            //#]
            OXF::start();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: StopwatchTest/Linux/MainStopwatchTest.cpp
*********************************************************************/
