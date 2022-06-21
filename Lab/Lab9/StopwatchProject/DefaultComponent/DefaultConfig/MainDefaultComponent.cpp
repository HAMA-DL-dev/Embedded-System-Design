/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: HaYeon
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Thu, 26, May 2022  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

//## auto_generated
#include "MainDefaultComponent.h"
//## auto_generated
#include "StopwatchPkg.h"
DefaultComponent::DefaultComponent() {
    StopwatchPkg_initRelations();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize())
        {
            DefaultComponent initializer_DefaultComponent;
            //#[ configuration DefaultComponent::DefaultConfig 
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
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/
