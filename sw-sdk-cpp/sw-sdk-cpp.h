// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SWSDKCPP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SWSDKCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "stdafx.h"

#ifdef SWSDKCPP_EXPORTS
#define SWSDKCPP_API __declspec(dllexport)
#else
#define SWSDKCPP_API __declspec(dllimport)
#endif

#include <string> 
using namespace std;
SWSDKCPP_API char *Authentication(char *_url, char *_user, char *_password);

SWSDKCPP_API int __stdcall AuthenticationVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR token);

SWSDKCPP_API char *StampByToken(char *_url, char *_token, char *_xml);
SWSDKCPP_API int __stdcall StampByTokenVB(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd);

SWSDKCPP_API char *Stamp(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API int __stdcall StampVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd);

char *StampRequest(char *_url, char *_token, char *_xml);

char *SplitJson(int find, string str);

bool ValidateXML(char *xml);