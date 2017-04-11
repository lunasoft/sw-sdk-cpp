#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sw-sdk-cpp/sw-sdk-cpp.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{		
	TEST_CLASS(AuthenticationTest)
	{
	public:
		
		TEST_METHOD(AuthTEST)
		{
			char *url = "http://services.test.sw.com.mx";
			char *user = "demo";
			char *password = "123456789";
			string tkn = Authentication(url, user, password);
			cout << tkn;
			Assert::IsTrue(!tkn.empty());
		}

	};
}