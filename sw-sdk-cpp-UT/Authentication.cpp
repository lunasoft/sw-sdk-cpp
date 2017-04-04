#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\sw-sdk-cpp\AuthenticationServices.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace swsdkcppUT
{		
	TEST_CLASS(Authentication)
	{
	public:
		
		TEST_METHOD(GetToken)
		{
			SW::AuthenticationServices auth = SW::AuthenticationServices("http://services.test.sw.com.mx", "demo", "123456789");
			
		
			cout << auth.GetToken();
			string result = auth.GetToken();
			Assert::IsTrue(!result.empty());

		}

	};
}