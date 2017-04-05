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

SWSDKCPP_API char *StampV1(char * _url, char * _token, char * _xml)
{
	
	utility::string_t token = utility::conversions::to_string_t(_token);
	
	string path = "/cfdi33/stamp/v1";
	string s_url = _url;
	s_url = s_url + path;
	utility::string_t base;
	base = utility::conversions::to_string_t(s_url);
	http_client client(base);
	http_response httpResponse;
	http_request request(methods::POST);
	request.headers().add(L"Cache-Control", L"no-cache");
	request.headers().add(L"authorization", token);
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
