#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sw-sdk-cpp/sw-sdk-cpp.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{
	TEST_CLASS(AccountTest)
	{
	public:
		char *_user = "demo";
		char *_password = "123456789";
		char *_url = "http://services.test.sw.com.mx";
		char *_result200 = "idSaldoCliente";
		char *_result401 = "401";

		TEST_METHOD(GetBalanceByUserPasswordUT)
		{
			string balance = GetBalanceAccount(_url, _user, _password);
			char* result = SplitJson(3, balance);
			Assert::IsTrue(std::strcmp(_result200, result) == 0);
		}
		TEST_METHOD(GetBalanceByTokenUT)
		{
			char* tkn = FindMyToken();
			string balance = GetBalanceAccounByToken(_url, tkn);
			char* result = SplitJson(3, balance);
			Assert::IsTrue(std::strcmp(_result200, result) == 0);
			
		}
		TEST_METHOD(GetBalanceError401)
		{
			_password = "53a4s84a6s84";
			string balance = GetBalanceAccount(_url, _user, _password);
			char* result = SplitJson(3, balance);
			Assert::IsTrue(std::strcmp(_result401, result) == 0);
		}
		char* FindMyToken() {
			string result = Authentication(_url, _user, _password);
			return SplitJson(5, result);
		}
	};
}