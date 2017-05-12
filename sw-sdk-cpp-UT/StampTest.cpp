#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../sw-sdk-cpp/sw-sdk-cpp.h"
#include <iostream>
#include <string>
#include <fstream>
#include "base64.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{
	
	TEST_CLASS(StampTest)
	{
	private:
		char *_url = "http://services.test.sw.com.mx";
		char *_user = "demo";
		char *_password = "123456789";
		char *_token = FindMyToken();
		char *_resultExpect = "";
		char* _xml = GetXml("XMLFile.xml");
		char* _pago10 = GetXml("pago10.xml");
		char* _comercioExterior = GetXml("ComercioExterior.xml");
		char* _conceptos = GetXml("conceptos5.xml");
		char* _nomina = GetXml("nomina.xml");

		std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
									"abcdefghijklmnopqrstuvwxyz"
								"0123456789+/";

	public:
		
		TEST_METHOD(UT_Stamp_V1)
		{
			_resultExpect = "success";
			string resultByToken = StampByToken(_url, _token, _pago10);
			string result = Stamp(_url, _user, _password, _pago10);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_Pagos)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect = "success";
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			result = StampV2B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			result = StampV3B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			result = StampV4B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			_cfdi = _pago10;
			resultByToken = StampByToken(_url, _token, _cfdi);
			result = Stamp(_url, _user, _password, _cfdi);
			 status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2(_url, _token, _cfdi);
			result = StampV2(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3(_url, _token, _cfdi);
			result = StampV3(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4(_url, _token, _cfdi);
			result = StampV4(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

		}
		TEST_METHOD(UT_Stamp_Conceptos)
		{
			char* _cfdi = _conceptos;
			_resultExpect = "success";
	/*		string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			result = StampV2B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			result = StampV3B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			result = StampV4B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));*/
/*
			string resultByToken;
			string result;
			char* status;
			char* statusByToken;

			_cfdi = _conceptos;
			resultByToken = StampByToken(_url, _token, _cfdi);
			result = Stamp(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2(_url, _token, _cfdi);
			result = StampV2(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3(_url, _token, _cfdi);
			result = StampV3(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4(_url, _token, _cfdi);
			result = StampV4(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));*/

		}
		TEST_METHOD(UT_Stamp_ComercioExterior)
		{
			char* _cfdi = GetBase64(_comercioExterior);
			_resultExpect = "success";
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			result = StampV2B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			result = StampV3B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			result = StampV4B64(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			_cfdi = _comercioExterior;
			resultByToken = StampByToken(_url, _token, _cfdi);
			result = Stamp(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV2(_url, _token, _cfdi);
			result = StampV2(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV3(_url, _token, _cfdi);
			result = StampV3(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));

			resultByToken = StampByTokenV4(_url, _token, _cfdi);
			result = StampV4(_url, _user, _password, _cfdi);
			status = SplitJson(280, result);
			statusByToken = SplitJson(280, resultByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_V2)
		{
			char* _cfdi = _pago10;
			_resultExpect = "success";
			string resultByToken = StampByTokenV2(_url, _token, _cfdi);
			string result = StampV2(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV3)
		{
			char* _cfdi = _pago10;
			_resultExpect = "success";
			string resultByToken = StampByTokenV3(_url, _token, _cfdi);
			string result = StampV3(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_V4)
		{
			char* _cfdi = _pago10;
			_resultExpect = "success";
			string resultByToken = StampByTokenV4(_url, _token, _cfdi);
			string result = StampV4(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV1B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect = "success";
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV2B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect = "success";
			string resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			string result = StampV2B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV3B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect = "success";
			string resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			string result = StampV3B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV4B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect = "success";
			string resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			string result = StampV4B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_Error401)
		{
			_resultExpect = "401";
			string result = Stamp(_url, _user, "", _pago10);
			string resultByToken = StampByToken(_url, "ff", _pago10);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_Error404)
		{
			_resultExpect = "404";
			string result = Stamp("http://badendpoint.com", _user, _password, _pago10);
			string resultByToken = StampByToken("http://badendpoint.com", _token, _pago10);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		char* FindMyToken() {
			string result = Authentication(_url, _user, _password);
			return SplitJson(5, result);
		}
		char* SplitJson(int find, string str) {
			std::string delimiter = "\"";
			size_t pos = 0;
			std::string itemToFind;
			int itemToGet = 0;
			while ((pos = str.find(delimiter)) != std::string::npos)
			{
				itemToFind = str.substr(0, pos);
				if (itemToGet != find)
				{
					str.erase(0, pos + delimiter.length());
					itemToGet++;
				}
				else
				{
					itemToFind = str.substr(0, pos);
					break;
				}
			}
			char *last = new char[itemToFind.size() + 1];
			last[itemToFind.size()] = 0;
			memcpy(last, itemToFind.c_str(), itemToFind.size());
			return last;
		}
		char* GetXml(string nameFile, string pathFile = "")
		{
			if (pathFile.empty())
			{
				char path[] = "..\\sw-sdk-cpp-UT\\Resources\\";
				string file = nameFile;
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
		char* GetBase64(char* xml) {
			string base64string = base64_encode(xml, strlen(xml));
			char* newXml = strdup(base64string.c_str());
			return newXml;
		}


		static inline bool is_base64(unsigned char c) {
			return (isalnum(c) || (c == '+') || (c == '/'));
		}

		std::string base64_encode(char* bytes_to_encode, int in_len) {
			std::string ret;
			int i = 0;
			int j = 0;
			unsigned char char_array_3[3];
			unsigned char char_array_4[4];

			while (in_len--) {
				char_array_3[i++] = *(bytes_to_encode++);
				if (i == 3) {
					char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
					char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
					char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
					char_array_4[3] = char_array_3[2] & 0x3f;

					for (i = 0; (i <4); i++)
						ret += base64_chars[char_array_4[i]];
					i = 0;
				}
			}

			if (i)
			{
				for (j = i; j < 3; j++)
					char_array_3[j] = '\0';

				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for (j = 0; (j < i + 1); j++)
					ret += base64_chars[char_array_4[j]];

				while ((i++ < 3))
					ret += '=';

			}

			return ret;

		}

		std::string base64_decode(std::string const& encoded_string) {
			size_t in_len = encoded_string.size();
			size_t i = 0;
			size_t j = 0;
			int in_ = 0;
			unsigned char char_array_4[4], char_array_3[3];
			std::string ret;

			while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
				char_array_4[i++] = encoded_string[in_]; in_++;
				if (i == 4) {
					for (i = 0; i <4; i++)
						char_array_4[i] = static_cast<unsigned char>(base64_chars.find(char_array_4[i]));

					char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
					char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
					char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

					for (i = 0; (i < 3); i++)
						ret += char_array_3[i];
					i = 0;
				}
			}

			if (i) {
				for (j = i; j <4; j++)
					char_array_4[j] = 0;

				for (j = 0; j <4; j++)
					char_array_4[j] = static_cast<unsigned char>(base64_chars.find(char_array_4[j]));

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
			}

			return ret;
		}
		
	};
}