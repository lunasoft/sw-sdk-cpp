#include "Services.h"

namespace SW
{
	class StampServices : public Services
	{
	public:
		StampServices(string url, string user, string password) : Services(url, user, password)
		{

		}
		StampServices(string url, string token) : Services(url, token)
		{

		}
		//~Stamp();
		string Timbrar();
	};
}