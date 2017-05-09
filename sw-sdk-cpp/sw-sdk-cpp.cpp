// sw-sdk-cpp.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "sw-sdk-cpp.h"
#include <cpprest\http_client.h>
using namespace web::http;
using namespace web::http::client;
using namespace Concurrency::streams;

SWSDKCPP_API char *Authentication(char *_url, char *_user, char *_password)
{

	utility::string_t result;
	utility::string_t user = utility::conversions::to_string_t(_user);
	utility::string_t password = utility::conversions::to_string_t(_password);
	string path = "/security/authenticate";

	string s_url = _url;
	s_url = s_url + path;
	utility::string_t base;
	base = utility::conversions::to_string_t(s_url);
	http_client client(base);
	http_response httpResponse;
	http_request request(methods::POST);
	request.headers().add(L"Cache-Control", L"no-cache");
	request.headers().add(L"Content-Length", L"0");
	request.headers().add(L"user", user);
	request.headers().add(L"password", password);
	pplx::task<string> pro = client.request(request).then([](http_response response)
	{
		return response.extract_utf8string();
	});
	pro.wait();
	string rr = pro.get();
	char *last = new char[rr.size() + 1];
	last[rr.size()] = 0;
	memcpy(last, rr.c_str(), rr.size());
	return last;
}
SWSDKCPP_API int __stdcall AuthenticationVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR token)
{
	try
	{
		char * authen = Authentication(url, user, pass);
		strcpy_s(token, strlen(authen)+1 , authen);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(token, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;

}
SWSDKCPP_API int __stdcall StampByTokenVB(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampByTokenB64(url, token, xml);
		strcpy_s(tfd, strlen(tfdStamped)+1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}

SWSDKCPP_API int __stdcall StampByTokenVBV2(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampByTokenV2B64(url, token, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}
SWSDKCPP_API int __stdcall StampByTokenVBV3(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampByTokenV3B64(url, token, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}

SWSDKCPP_API int __stdcall StampByTokenVBV4(LPSTR url, LPSTR token, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampByTokenV4B64(url, token, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}
SWSDKCPP_API int __stdcall StampVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampB64(url, user, pass, xml);
		strcpy_s(tfd, strlen(tfdStamped)+1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}

SWSDKCPP_API int __stdcall StampVBV2(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampV2B64(url, user, pass, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}
SWSDKCPP_API int __stdcall StampVBV3(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampV3B64(url, user, pass, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}

SWSDKCPP_API int __stdcall StampVBV4(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml, LPSTR tfd)
{
	try
	{
		char *tfdStamped = StampV4B64(url, user, pass, xml);
		strcpy_s(tfd, strlen(tfdStamped) + 1, tfdStamped);
	}
	catch (const std::exception& exc)
	{
		strcpy_s(tfd, 100, "Error al timbrar por token");
		return -1;
	}
	return 0;
}
SWSDKCPP_API char *StampByToken(char * _url, char * _token, char *_xml)
{
	return StampRequest(_url, _token, _xml, "v1");
}

SWSDKCPP_API char *StampByTokenV2(char * _url, char * _token, char *_xml)
{

	return StampRequest(_url, _token, _xml,"v2");
}
SWSDKCPP_API char *StampByTokenV3(char * _url, char * _token, char *_xml)
{
	return StampRequest(_url, _token, _xml, "v3");
}

SWSDKCPP_API char *StampByTokenV4(char * _url, char * _token, char *_xml)
{

	return StampRequest(_url, _token, _xml, "v4");
}
SWSDKCPP_API char *StampByTokenB64(char * _url, char * _token, char *_xml)
{
	return StampRequestFormated(_url, _token, _xml, "v1", "b64");
}

SWSDKCPP_API char *StampByTokenV2B64(char * _url, char * _token, char *_xml)
{

	return StampRequestFormated(_url, _token, _xml, "v2", "b64");
}
SWSDKCPP_API char *StampByTokenV3B64(char * _url, char * _token, char *_xml)
{
	return StampRequestFormated(_url, _token, _xml, "v3", "b64");
}

SWSDKCPP_API char *StampByTokenV4B64(char * _url, char * _token, char *_xml)
{

	return StampRequestFormated(_url, _token, _xml, "v4", "b64");
}
SWSDKCPP_API char *Stamp(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequest(_url, _token, _xml, "v1");
}

SWSDKCPP_API char *StampV2(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequest(_url, _token, _xml, "v2");
}
SWSDKCPP_API char *StampV3(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequest(_url, _token, _xml, "v3");
}

SWSDKCPP_API char *StampV4(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequest(_url, _token, _xml, "v4");
}
SWSDKCPP_API char *StampB64(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequestFormated(_url, _token, _xml, "v1", "b64");
}

SWSDKCPP_API char *StampV2B64(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequestFormated(_url, _token, _xml, "v2", "b64");
}
SWSDKCPP_API char *StampV3B64(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequestFormated(_url, _token, _xml, "v3", "b64");
}

SWSDKCPP_API char *StampV4B64(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequestFormated(_url, _token, _xml, "v4", "b64");
}
bool ValidateXML(char *xml)
{
	string xmlNew = xml;
	bool result = xmlNew.find("<?xml version=") != string::npos;
	return result;
}
char *StampRequestFormated(char *_url, char *_token, char *_xml, char *_version, char *_formato) {
	
		string url = _url;
		string xml = _xml;
		utility::string_t result;
		string path = "/cfdi33/stamp/";
		path += _version;
		string format = _formato;
		path += "/"+ format;
		url = url + path;
		utility::string_t base;
		string bearer = "bearer ";

		base = utility::conversions::to_string_t(url);
		http_client client(base);
		http_response httpResponse;
		http_request request(methods::POST);

		std::string textBoundary = "------=_Part_11_11939969.1490230712432";
		std::string textBody = "";
		textBody += textBoundary + "\r\n";
		textBody += "Content-Type: text/xml";
		textBody += "\r\n";
		textBody += "Content-Transfer-Encoding: binary";
		textBody += "\r\n";
		textBody += "Content-Disposition: form-data; name=\"xml\"; filename=\"file.xml\"";
		textBody += "\r\n";
		textBody += "\r\n";
		textBody += xml;
		textBody += "\r\n";
		textBody += textBoundary + "--";
		textBody += "\r\n";
		request.headers().add(L"Authorization", utility::conversions::to_string_t(bearer) + utility::conversions::to_string_t(_token));
		request.headers().set_content_type(L"multipart/form-data; boundary=\"----=_Part_11_11939969.1490230712432\"");
		request.set_body(textBody);

		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			return response.extract_utf8string();
		});
		pro.wait();
		string rr = pro.get();
		char *last = new char[rr.size() + 1];
		last[rr.size()] = 0;
		memcpy(last, rr.c_str(), rr.size());
		return last;
	
}
char *StampRequest(char *_url, char *_token, char *_xml, char *_version) {
	if (!ValidateXML(_xml))
	{
		return "XML mal Formado";
	}
	else
	{
		string url = _url;
		string xml = _xml;
		utility::string_t result;
		string path = "/cfdi33/stamp/";
		path += _version;
		url = url + path;
		utility::string_t base;
		string bearer = "bearer ";
		
		base = utility::conversions::to_string_t(url);
		http_client client(base);
		http_response httpResponse;
		http_request request(methods::POST);

		std::string textBoundary = "------=_Part_11_11939969.1490230712432";
		std::string textBody = "";
		textBody += textBoundary + "\r\n";
		textBody += "Content-Type: text/xml";
		textBody += "\r\n";
		textBody += "Content-Transfer-Encoding: binary";
		textBody += "\r\n";
		textBody += "Content-Disposition: form-data; name=\"xml\"; filename=\"file.xml\"";
		textBody += "\r\n";
		textBody += "\r\n";
		textBody += xml;
		textBody += "\r\n";
		textBody += textBoundary + "--";
		textBody += "\r\n";
		request.headers().add(L"Authorization", utility::conversions::to_string_t(bearer)+utility::conversions::to_string_t(_token));
		request.headers().set_content_type(L"multipart/form-data; boundary=\"----=_Part_11_11939969.1490230712432\"");
		request.set_body(textBody);

		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			return response.extract_utf8string();
		});
		pro.wait();
		string rr = pro.get();
		char *last = new char[rr.size() + 1];
		last[rr.size()] = 0;
		memcpy(last, rr.c_str(), rr.size());
		return last;
	}
}

char* SplitJson(int find, string str) {
	std::string delimiter = "\"";
	size_t pos = 0;
	std::string token;
	int itemToGet = 0;
	while ((pos = str.find(delimiter)) != std::string::npos)
	{
		token = str.substr(0, pos);
		if (itemToGet != find)
		{
			str.erase(0, pos + delimiter.length());
			itemToGet++;
		}
		else
		{
			token = str.substr(0, pos);
			break;
		}
	}
	char *last = new char[token.size() + 1];
	last[token.size()] = 0;
	memcpy(last, token.c_str(), token.size());
	return last;
}

string dummy(string d)
{
	return d;
}
