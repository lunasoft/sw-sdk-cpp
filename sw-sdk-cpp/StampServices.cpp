#include "StampServices.h"
#include "Services.h"


namespace SW
{
	string StampServices::Timbrar()
	{
		try
		{
			return Services::Token();
		}
		catch (int e)
		{
			return "services exception";
		}
	}
}