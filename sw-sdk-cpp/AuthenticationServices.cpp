#include "AuthenticationServices.h"
#include "Services.h"
#include <iostream>
#include <string>
#include <cpprest\http_client.h>
#include <sstream>

using namespace std;
using namespace web::http;
using namespace web::http::client;
using namespace Concurrency::streams;

namespace SW
{
	
	string AuthenticationServices::GetToken()
	{

		
		string url = AuthenticationServices::Url();
		utility::string_t result;
		utility::string_t user = utility::conversions::to_string_t(AuthenticationServices::User());
		utility::string_t password = utility::conversions::to_string_t(AuthenticationServices::Password());
		string path = "/security/authenticate";
		url = url + path;
		utility::string_t base;
		base = utility::conversions::to_string_t(url);
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
		return pro.get();
	}
}