#include "Services.h"



namespace SW
{
	class AuthenticationServices : public Services
	{
	public:
		AuthenticationServices(string url, string user, string password) : Services(url, user, password)
		{

		}
		//~Authentication();
		string GetToken();
	};
}
