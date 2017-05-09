#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../sw-sdk-cpp/sw-sdk-cpp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{
	
	TEST_CLASS(StampTest)
	{
	private:
		char *_url = "http://services.test.sw.com.mx";
		char *_user = "demo";
		char *_password = "123456789";
		char *_token = FindMyToken();//"T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbXB3YVZxTHdOdHAwVXY2NTdJb1hkREtXTzE3dk9pMmdMdkFDR2xFWFVPUXpTUm9mTG1ySXdZbFNja3FRa0RlYURqbzdzdlI2UUx1WGJiKzViUWY2dnZGbFloUDJ6RjhFTGF4M1BySnJ4cHF0YjUvbmRyWWpjTkVLN3ppd3RxL0dJPQ.T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbFlVcU92YUJTZWlHU3pER1kySnlXRTF4alNUS0ZWcUlVS0NhelhqaXdnWTRncklVSWVvZlFZMWNyUjVxYUFxMWFxcStUL1IzdGpHRTJqdS9Zakw2UGRiMTFPRlV3a2kyOWI5WUZHWk85ODJtU0M2UlJEUkFTVXhYTDNKZVdhOXIySE1tUVlFdm1jN3kvRStBQlpLRi9NeWJrd0R3clhpYWJrVUMwV0Mwd3FhUXdpUFF5NW5PN3J5cklMb0FETHlxVFRtRW16UW5ZVjAwUjdCa2g0Yk1iTExCeXJkVDRhMGMxOUZ1YWlIUWRRVC8yalFTNUczZXdvWlF0cSt2UW0waFZKY2gyaW5jeElydXN3clNPUDNvU1J2dm9weHBTSlZYNU9aaGsvalpQMUxrUndzK0dHS2dpTittY1JmR3o2M3NqNkh4MW9KVXMvUHhZYzVLQS9UK2E1SVhEZFJKYWx4ZmlEWDFuSXlqc2ZRYXlUQk1ldlZkU2tEdU10NFVMdHZKUURLblBxakw0SDl5bUxabDFLNmNPbEp6b3Jtd2Q1V2htRHlTdDZ6eTFRdUNnYnVvK2tuVUdhMmwrVWRCZi9rQkU9.7k2gVCGSZKLzJK5Ky3Nr5tKxvGSJhL13Q8W-YhT0uIo";
		char *_resultExpect = "";
		char* _xml = GetXml();

	public:
		
		TEST_METHOD(StampV1)
		{
			_resultExpect = "success";
			Logger::WriteMessage(StampByToken(_url, _token, _xml));
			string result = Stamp(_url, _user, _password, _xml);
			//Logger::WriteMessage(SplitJson(29, result));
			char* status = SplitJson(29, result);
			
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
		}

		TEST_METHOD(Stamp_V2)
		{
			_resultExpect = "success";
			Logger::WriteMessage(StampV2(_url, _user, _password, _xml));
			string result = StampV2(_url, _user, _password, _xml);
			//Logger::WriteMessage(SplitJson(29, result));
			char* status = SplitJson(280, result);
			Logger::WriteMessage(status);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
		}
		
		TEST_METHOD(StampV1ByToken)
		{
			_resultExpect = "success";
			string result = StampByToken(_url, _token, _xml);
			Logger::WriteMessage(StampByToken(_url, _token, _xml));
			char* status = SplitJson(29, result);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
		}
		TEST_METHOD(StampV2ByToken)
		{
			_resultExpect = "success";
			string result = StampByTokenV2(_url, _token, _xml);
			Logger::WriteMessage(StampByTokenV2(_url, _token, _xml));
			char* status = SplitJson(280, result);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
		}
		TEST_METHOD(ValidateIsXML)
		{
			_resultExpect = "XML mal Formado";
			char* xmlNew = GetXml("no es valido");
			string result = StampByToken(_url, _token, xmlNew);
			Assert::IsTrue(result == _resultExpect);
		}
		char* FindMyToken() {
			string result = Authentication(_url, _user, _password);
			return SplitJson(5, result);
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
		char* GetXml(string pathFile = "")
		{
			if (pathFile.empty())
			{
				char path[] = "..\\sw-sdk-cpp-UT\\Resources\\";
				string file = "XMLFile.xml";
				stringstream complete;
				complete << path << file;
				pathFile = complete.str();
			}
			string line;
			string xml = "";
			ifstream myfile(pathFile);

			if (myfile.is_open())
			{
				while (getline(myfile, line)) {
					xml += line;
				}
				myfile.close();

				char *last = new char[xml.size() + 1];
				last[xml.size()] = 0;
				memcpy(last, xml.c_str(), xml.size());
				return last;
			}
			else {
				return "Unable to open file";
			}
		}
	};
}