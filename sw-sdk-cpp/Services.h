#include <string> 
#include <iostream> 
#include <ctime>

#ifndef ServicesObj_H
#define ServicesObj_H

using namespace std;

namespace SW
{
	class Services
	{
	private:
		string _token;
		string _url;
		string _user;
		string _password;
		time_t _expirationDate;
		int _timeSession = 2;


	public:
		string Token();
		string Url();
		string User();
		string Password();
		time_t ExpirationDate();
		
		//Services(string url, string token)
		//{

		//	_url = url;
		//	_token = token;
		//	/*struct tm* tm = localtime(&_expirationDate);
		//	tm->tm_hour += 2;
		//	_expirationDate = mktime(tm);*/
		//}
		
		Services::Services(string url, string user, string password);

		Services::Services(string url, string token);
		

	};

}

#endif