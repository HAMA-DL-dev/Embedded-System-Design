/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: MontaVista
//!	Generated Date	: Tue, 28, Apr 2020  
	File Path	: ButtonTest/MontaVista/MainButtonTest.cpp
*********************************************************************/

//## auto_generated
#include "MainButtonTest.h"
//## auto_generated
#include "ButtonPkg.h"
ButtonTest::ButtonTest() {
    ButtonPkg_initRelations();
    ButtonPkg_startBehavior();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize())
        {
            ButtonTest initializer_ButtonTest;
            //#[ configuration ButtonTest::MontaVista 
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
	File Path	: ButtonTest/MontaVista/MainButtonTest.cpp
*********************************************************************/
