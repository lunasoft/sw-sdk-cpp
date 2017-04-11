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
		strcpy_s(token, 2000, Authentication(url, user, pass));
	}
	catch (const std::exception& exc)
	{
		token = "Error al obtener el Token: ";
	}
	return 0;

}
SWSDKCPP_API int __stdcall StampByTokenVB(LPSTR url, LPSTR token, LPSTR xml)
{
	try
	{
		strcpy_s(xml, 2000, StampByToken(url, token, xml));
	}
	catch (const std::exception& exc)
	{
		xml = "Error al obtener el Token: ";
	}
	return 0;

}
SWSDKCPP_API int __stdcall StampVB(LPSTR url, LPSTR user, LPSTR pass, LPSTR xml)
{
	try
	{
		strcpy_s(xml, 2000, Stamp(url, user, pass, xml));
	}
	catch (const std::exception& exc)
	{
		xml = "Error al obtener el Token: ";
	}
	return 0;

}
SWSDKCPP_API char *StampByToken(char * _url, char * _token, char *_xml)
{
	return StampRequest(_url, _token, _xml);
}

SWSDKCPP_API char *Stamp(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return StampRequest(_url, _token, _xml);
}

bool ValidateXML(char *xml)
{
	string xmlNew = xml;
	bool result = xmlNew.find("<?xml version=") != string::npos;
	return result;
}
char *StampRequest(char *_url, char *_token, char *_xml) {
	if (!ValidateXML(_xml))
	{
		return "XML mal Formado";
	}
	else
	{
		string url = _url;
		string xml = _xml;
		utility::string_t result;
		string path = "/cfdi33/stamp/v1";
		url = url + path;
		utility::string_t base;
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
		request.headers().add(L"Authorization", utility::conversions::to_string_t(_token));
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