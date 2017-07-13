// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SWSDKCPP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SWSDKCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "stdafx.h"
#include <objbase.h>
#include <string> 

#ifdef SWSDKCPP_EXPORTS
#define SWSDKCPP_API __declspec(dllexport)
#else
#define SWSDKCPP_API __declspec(dllimport)
#endif

using namespace std;
SWSDKCPP_API char *Authentication(char *_url, char *_user, char *_password);
SWSDKCPP_API int __stdcall AuthenticationVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR token);

SWSDKCPP_API char *StampByToken(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV2(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV3(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV4(char *_url, char *_token, char *_xml);

SWSDKCPP_API char *StampByTokenB64(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV2B64(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV3B64(char *_url, char *_token, char *_xml);
SWSDKCPP_API char *StampByTokenV4B64(char *_url, char *_token, char *_xml);

SWSDKCPP_API int __stdcall StampByTokenVB(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampByTokenVBV2(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampByTokenVBV3(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampByTokenVBV4(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd);

SWSDKCPP_API char *Stamp(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV2(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV3(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV4(char *_url, char *_user, char *_password, char *_xml);

SWSDKCPP_API char *StampB64(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV2B64(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV3B64(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *StampV4B64(char *_url, char *_user, char *_password, char *_xml);

SWSDKCPP_API int __stdcall StampVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampVBV2(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampVBV3(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd);
SWSDKCPP_API int __stdcall StampVBV4(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd);

SWSDKCPP_API char *StampRequestFormated(char *_url, char *_token, char *_xml, char *_version, char *_formato);
SWSDKCPP_API char *StampRequest(char *_url, char *_token, char *_xml, char *_version);
SWSDKCPP_API char *CancelRequestByXml(char *_url, char *_token, char *_xml);


SWSDKCPP_API char *SplitJson(int find, string str);
SWSDKCPP_API string dummy(string d);

SWSDKCPP_API char *CancelByXml(char *_url, char *_user, char *_password, char *_xml);
SWSDKCPP_API char *CancelByXmlToken(char *_url, char *_token, char *_xml);

SWSDKCPP_API char *CancelByCSD(char *_url, char *_user, char *_password, char *_b64Cer, char *_b64Key, char *_csdPassword, char *_rfc, char *_uuid);
SWSDKCPP_API char *CancelByCSDToken(char *_url, char *_token, char *_b64Cer, char *_b64Key, char *_password, char *_rfc, char *_uuid);
SWSDKCPP_API char *CancelRequestByCSD(char *_url, char *_token, char *_b64Cer, char *_b64Key, char *_password, char *_rfc, char *_uuid);