// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SWSDKCPP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SWSDKCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SWSDKCPP_EXPORTS
#define SWSDKCPP_API __declspec(dllexport)
#else
#define SWSDKCPP_API __declspec(dllimport)
#endif

#include <string> 
using namespace std;
SWSDKCPP_API char *Authentication(char *_url, char *_user, char *_password);

SWSDKCPP_API char *StampV1(char *_url, char *_token, char *_xml);
