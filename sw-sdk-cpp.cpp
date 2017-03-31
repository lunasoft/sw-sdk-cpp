// sw-sdk-cpp.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "sw-sdk-cpp.h"


// This is an example of an exported variable
SWSDKCPP_API int nswsdkcpp=0;

// This is an example of an exported function.
SWSDKCPP_API int fnswsdkcpp(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see sw-sdk-cpp.h for the class definition
Cswsdkcpp::Cswsdkcpp()
{
    return;
}
