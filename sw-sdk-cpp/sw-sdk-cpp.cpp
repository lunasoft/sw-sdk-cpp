// sw-sdk-cpp.cpp : Defines the exported functions for the DLL application.
//

#include <objbase.h>
#include "stdafx.h"
#include "sw-sdk-cpp.h"
#include <cpprest\http_client.h>
using namespace web::http;
using namespace web::http::client;
using namespace Concurrency::streams;
short _code;
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
	
	string rr;
	try
	{
		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			_code = response.status_code();
			return response.extract_utf8string();
		});
		pro.wait();
		rr = pro.get();
		switch (_code)
		{
			case status_codes::Unauthorized:
				rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
				break;
			case status_codes::NotFound:
				rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
				break;
			default:
				break;
		}
		
	}
	catch (exception ex)
	{
		rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
	}
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
	catch (exception ex)
	{

		strcpy_s(token, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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
	catch (exception ex)
	{

		strcpy_s(tfd, strlen("Error al procesar la solicitud en la librería de CPP") + 1, "Error al procesar la solicitud en la librería de CPP");
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

SWSDKCPP_API char *CancelByXml(char *_url, char *_user, char *_password, char *_xml)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return CancelRequestByXml(_url, _token, _xml);
}

SWSDKCPP_API char *CancelByXmlToken(char *_url, char *_token, char *_xml)
{
	return CancelRequestByXml(_url, _token, _xml);
}

SWSDKCPP_API char *CancelByCSD(char *_url, char *_user, char* _password, char *_b64Cer, char *_b64Key, char *_csdPassword, char *_rfc, char *_uuid)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return CancelRequestByCSD(_url, _token, _b64Cer, _b64Key, _csdPassword, _rfc, _uuid);
}

SWSDKCPP_API char *CancelByCSDToken(char *_url, char *_token, char *_b64Cer, char *_b64Key, char *_csdPassword, char *_rfc, char *_uuid)
{
	return CancelRequestByCSD(_url, _token, _b64Cer, _b64Key, _csdPassword, _rfc, _uuid);
}
SWSDKCPP_API char *GetBalanceAccounByToken(char *_url, char *_token)
{
	string url = _url;
	string path = "/account/balance";
	url = url + path;
	utility::string_t base;
	string bearer = "bearer ";
	base = utility::conversions::to_string_t(url);
	http_client client(base);
	http_response httpResponse;
	http_request request(methods::GET);
	request.headers().add(L"Cache-Control", L"no-cache");
	request.headers().add(L"Content-Length", L"0");
	request.headers().add(L"Authorization", utility::conversions::to_string_t(bearer) + utility::conversions::to_string_t(_token));
	string rr;
	try
	{
		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			_code = response.status_code();
			return response.extract_utf8string();
		});
		pro.wait();
		rr = pro.get();
		switch (_code)
		{
		case status_codes::Unauthorized:
			rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
			break;
		case status_codes::NotFound:
			rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
			break;
		default:
			break;
		}
	}
	catch (exception ex)
	{
		rr = "{\"message\": \"413\", \"messageDetail\": \"Request Entity Too Large\", \"status\": \"error\"}";
	}
	char *last = new char[rr.size() + 1];
	last[rr.size()] = 0;
	memcpy(last, rr.c_str(), rr.size());
	return last;

}
SWSDKCPP_API char *GetBalanceAccount(char *_url, char *_user, char *_password)
{
	string result = Authentication(_url, _user, _password);
	char* _token = SplitJson(5, result);
	return GetBalanceAccounByToken(_url, _token);
}

char *CancelRequestByXml(char *_url, char *_token, char *_xml)
{
	string url = _url;
	string xml = _xml;
	utility::string_t result;
	GUID guid;
	CoCreateGuid(&guid);
	OLECHAR* guidString;
	StringFromCLSID(guid, &guidString);
	wstring ws(guidString);
	string strGuid(ws.begin(), ws.end());

	string path = "/cfdi33/cancel/xml";
	url = url + path;
	utility::string_t base;
	string bearer = "bearer ";
	base = utility::conversions::to_string_t(url);
	http_client client(base);
	http_response httpResponse;
	http_request request(methods::POST);

	std::string textBoundary = "------=_Part_" + strGuid;
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
	request.headers().set_content_type(utility::conversions::to_string_t("multipart/form-data; boundary=\"----=_Part_" + strGuid + "\""));
	request.set_body(textBody);
	string rr;
	try
	{
		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			_code = response.status_code();
			return response.extract_utf8string();
		});
		pro.wait();
		rr = pro.get();
		switch (_code)
		{
		case status_codes::Unauthorized:
			rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
			break;
		case status_codes::NotFound:
			rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
			break;
		default:
			break;
		}
	}
	catch (exception ex)
	{
		rr = "{\"message\": \"413\", \"messageDetail\": \"Request Entity Too Large\", \"status\": \"error\"}";
	}
	char *last = new char[rr.size() + 1];
	last[rr.size()] = 0;
	memcpy(last, rr.c_str(), rr.size());
	return last;
}

char *CancelRequestByCSD(char *_url, char *_token, char *_b64Cer, char *_b64Key, char *_password, char *_rfc, char *_uuid)
{
	string url = _url;
	string b64Cer = _b64Cer;
	string b64Key = _b64Key;
	string password = _password;
	string rfc = _rfc;
	string uuid = _uuid;

	
	utility::string_t result;
	string path = "/cfdi33/cancel/csd";
	url = url + path;
	utility::string_t base;
	string bearer = "bearer ";
	base = utility::conversions::to_string_t(url);
	http_client client(base);
	http_response httpResponse;
	http_request request(methods::POST);
	std::string body = "";
	body += "\r\n";
	body += "{\"uuid\":\""+uuid+"\", \"rfc\":\""+rfc+"\", \"b64Cer\":\""+b64Cer+"\", \"b64Key\":\""+b64Key+"\", \"password\":\""+password+"\"}";
	body += "\r\n";
	request.headers().add(L"Authorization", utility::conversions::to_string_t(bearer) + utility::conversions::to_string_t(_token));
	request.headers().set_content_type(utility::conversions::to_string_t("application/json"));
	request.set_body(body);
	string rr;
	try
	{
		pplx::task<string> pro = client.request(request).then([](http_response response)
		{
			_code = response.status_code();
			return response.extract_utf8string();
		});
		pro.wait();
		rr = pro.get();
		switch (_code)
		{
		case status_codes::Unauthorized:
			rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
			break;
		case status_codes::NotFound:
			rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
			break;
		default:
			break;
		}
	}
	catch (exception ex)
	{
		rr = "{\"message\": \"413\", \"messageDetail\": \"Request Entity Too Large\", \"status\": \"error\"}";
	}
	char *last = new char[rr.size() + 1];
	last[rr.size()] = 0;
	memcpy(last, rr.c_str(), rr.size());
	return last;
}

char *StampRequestFormated(char *_url, char *_token, char *_xml, char *_version, char *_formato) {
	
		string url = _url;
		string xml = _xml;
		utility::string_t result;

		GUID guid;
		CoCreateGuid(&guid);
		OLECHAR* guidString;
		StringFromCLSID(guid, &guidString);
		wstring ws(guidString);
		string strGuid(ws.begin(), ws.end());

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

		std::string textBoundary = "------=_Part_" + strGuid;
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
		request.headers().set_content_type(utility::conversions::to_string_t("multipart/form-data; boundary=\"----=_Part_" + strGuid + "\""));
		request.set_body(textBody);

		string rr;
		try
		{
			pplx::task<string> pro = client.request(request).then([](http_response response)
			{
				_code = response.status_code();
				return response.extract_utf8string();
			});
			pro.wait();
			rr = pro.get();
			switch (_code)
			{
			case status_codes::Unauthorized:
				rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
				break;
			case status_codes::NotFound:
				rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
				break;
			default:
				break;
			}
		}
		catch (exception ex)
		{
			rr = "{\"message\": \"413\", \"messageDetail\": \"Request Entity Too Large\", \"status\": \"error\"}";
		}
		char *last = new char[rr.size() + 1];
		last[rr.size()] = 0;
		memcpy(last, rr.c_str(), rr.size());
		return last;
	
}
char *StampRequest(char *_url, char *_token, char *_xml, char *_version) {
		string url = _url;
		string xml = _xml;
		utility::string_t result;
		
		GUID guid;
		CoCreateGuid(&guid);
		OLECHAR* guidString;
		StringFromCLSID(guid, &guidString);
		wstring ws(guidString);
		string strGuid(ws.begin(), ws.end());

		string path = "/cfdi33/stamp/";
		path += _version;
		url = url + path;
		utility::string_t base;
		string bearer = "bearer ";
		
		base = utility::conversions::to_string_t(url);
		http_client client(base);
		http_response httpResponse;
		http_request request(methods::POST);

		std::string textBoundary = "------=_Part_"+ strGuid;
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
		request.headers().set_content_type(utility::conversions::to_string_t("multipart/form-data; boundary=\"----=_Part_" + strGuid+"\""));
		request.set_body(textBody);

		string rr;
		try
		{
			pplx::task<string> pro = client.request(request).then([](http_response response)
			{
				_code = response.status_code();
				return response.extract_utf8string();
			});
			pro.wait();
			rr = pro.get();
			switch (_code)
			{
			case status_codes::Unauthorized:
				rr = "{\"message\": \"401\", \"messageDetail\": \"Unauthorized\", \"status\": \"error\"}";
				break;
			case status_codes::NotFound:
				rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
				break;
			default:
				break;
			}

		}
		catch (exception ex)
		{
			rr = "{\"message\": \"404\", \"messageDetail\": \"Not Found\", \"status\": \"error\"}";
		}
		char *last = new char[rr.size() + 1];
		last[rr.size()] = 0;
		memcpy(last, rr.c_str(), rr.size());
		return last;
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
