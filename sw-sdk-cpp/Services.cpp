#include <string> 
#include "Services.h"

using namespace std;

namespace SW
{
	Services::Services(string url, string token)
	 {
		 this->_url = url;
		 this->_token = token;
		 /*time_t now = time(0);
		 struct tm* tm = localtime(&now);
		 tm->tm_hour += 2;
		 this->_expirationDate = mktime(tm);*/
	 }
	Services::Services(string url, string user, string password)
	{
		this->_url = url;
		this->_user = user;
		this->_password = password;
	}
	 string Services::Url()
	 {
		return this->_url;
	 }
	 string Services::Token()
	 {
		 return this->_token;
	 }
	 string Services::User()
	 {
		 return this->_user;
	 }
	 string Services::Password()
	 {
		 return this->_password;
	 }
	 time_t Services::ExpirationDate()
	 {
		 return this->_expirationDate;
	 }
	 
}