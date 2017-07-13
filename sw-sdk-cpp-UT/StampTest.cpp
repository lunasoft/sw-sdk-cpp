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
		char *_resultExpect401 = "401";
		char *_resultExpect404 = "404";
		char *_resultExpect500 = "500";
		char* _xml = GetXml("XMLFile.xml");
		char* _pago10 = GetXml("pago10.xml");
		char* _comercioExterior = GetXml("ComercioExterior.xml");
		char* _conceptos = GetXml("conceptos1024.xml");
		char* _nomina = GetXml("nomina.xml");
		char* _cancelationXml = GetXml("cancelacion.xml");
		std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
									"abcdefghijklmnopqrstuvwxyz"
								"0123456789+/";
		char *_b64Cer = "MIIFxTCCA62gAwIBAgIUMjAwMDEwMDAwMDAzMDAwMjI4MTUwDQYJKoZIhvcNAQELBQAwggFmMSAwHgYDVQQDDBdBLkMuIDIgZGUgcHJ1ZWJhcyg0MDk2KTEvMC0GA1UECgwmU2VydmljaW8gZGUgQWRtaW5pc3RyYWNpw7NuIFRyaWJ1dGFyaWExODA2BgNVBAsML0FkbWluaXN0cmFjacOzbiBkZSBTZWd1cmlkYWQgZGUgbGEgSW5mb3JtYWNpw7NuMSkwJwYJKoZIhvcNAQkBFhphc2lzbmV0QHBydWViYXMuc2F0LmdvYi5teDEmMCQGA1UECQwdQXYuIEhpZGFsZ28gNzcsIENvbC4gR3VlcnJlcm8xDjAMBgNVBBEMBTA2MzAwMQswCQYDVQQGEwJNWDEZMBcGA1UECAwQRGlzdHJpdG8gRmVkZXJhbDESMBAGA1UEBwwJQ295b2Fjw6FuMRUwEwYDVQQtEwxTQVQ5NzA3MDFOTjMxITAfBgkqhkiG9w0BCQIMElJlc3BvbnNhYmxlOiBBQ0RNQTAeFw0xNjEwMjUyMTUyMTFaFw0yMDEwMjUyMTUyMTFaMIGxMRowGAYDVQQDExFDSU5ERU1FWCBTQSBERSBDVjEaMBgGA1UEKRMRQ0lOREVNRVggU0EgREUgQ1YxGjAYBgNVBAoTEUNJTkRFTUVYIFNBIERFIENWMSUwIwYDVQQtExxMQU43MDA4MTczUjUgLyBGVUFCNzcwMTE3QlhBMR4wHAYDVQQFExUgLyBGVUFCNzcwMTE3TURGUk5OMDkxFDASBgNVBAsUC1BydWViYV9DRkRJMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAgvvCiCFDFVaYX7xdVRhp/38ULWto/LKDSZy1yrXKpaqFXqERJWF78YHKf3N5GBoXgzwFPuDX+5kvY5wtYNxx/Owu2shNZqFFh6EKsysQMeP5rz6kE1gFYenaPEUP9zj+h0bL3xR5aqoTsqGF24mKBLoiaK44pXBzGzgsxZishVJVM6XbzNJVonEUNbI25DhgWAd86f2aU3BmOH2K1RZx41dtTT56UsszJls4tPFODr/caWuZEuUvLp1M3nj7Dyu88mhD2f+1fA/g7kzcU/1tcpFXF/rIy93APvkU72jwvkrnprzs+SnG81+/F16ahuGsb2EZ88dKHwqxEkwzhMyTbQIDAQABox0wGzAMBgNVHRMBAf8EAjAAMAsGA1UdDwQEAwIGwDANBgkqhkiG9w0BAQsFAAOCAgEAJ/xkL8I+fpilZP+9aO8n93+20XxVomLJjeSL+Ng2ErL2GgatpLuN5JknFBkZAhxVIgMaTS23zzk1RLtRaYvH83lBH5E+M+kEjFGp14Fne1iV2Pm3vL4jeLmzHgY1Kf5HmeVrrp4PU7WQg16VpyHaJ/eonPNiEBUjcyQ1iFfkzJmnSJvDGtfQK2TiEolDJApYv0OWdm4is9Bsfi9j6lI9/T6MNZ+/LM2L/t72Vau4r7m94JDEzaO3A0wHAtQ97fjBfBiO5M8AEISAV7eZidIl3iaJJHkQbBYiiW2gikreUZKPUX0HmlnIqqQcBJhWKRu6Nqk6aZBTETLLpGrvF9OArV1JSsbdw/ZH+P88RAt5em5/gjwwtFlNHyiKG5w+UFpaZOK3gZP0su0sa6dlPeQ9EL4JlFkGqQCgSQ+NOsXqaOavgoP5VLykLwuGnwIUnuhBTVeDbzpgrg9LuF5dYp/zs+Y9ScJqe5VMAagLSYTShNtN8luV7LvxF9pgWwZdcM7lUwqJmUddCiZqdngg3vzTactMToG16gZA4CWnMgbU4E+r541+FNMpgAZNvs2CiW/eApfaaQojsZEAHDsDv4L5n3M1CC7fYjE/d61aSng1LaO6T1mh+dEfPvLzp7zyzz+UgWMhi5Cs4pcXx1eic5r7uxPoBwcCTt3YI1jKVVnV7/w=";
		char *_b64Key = "MIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDgQIAgEAAoIBAQACAggAMBQGCCqGSIb3DQMHBAgwggS9AgEAMASCBMh4EHl7aNSCaMDA1VlRoXCZ5UUmqErAbucRBAKNQXH8t1GNfLDIQejtcocS39VvWnpNXjZJeCg65Y2wI36UGn78gvnU0NOmyUkXksPVrkz7hqNtAVojPUtN65l+MVAsIRVD6OLJeKZ2bLx5z78zrx6Tp1zCGT/NpxL+CJSy5iY6TKqbJcK/9198noOvT2p8rKVqUUF3wLRvD6R/b3BC5wCon/exp3BUTZeiWJqGRRgaW4rn49ZbJPVIcDmUO8mojPesFHjJDSnA0nBnWaUvTYXi0srT+dLZOewsBR8d5GdSWh9ZkM29wJbjYHCMsXkObZjaap3YM8fU29zRyZ8KAqaCnBHCfYjbib56m+Lmnk+ScqMkQQ+S/+2pzn2LzauvBI4p/OjQgBDeblo22X7sX9OA9YaqB3q6CCjQ5tkDNrz3HOgTm+amh/kI8TEn9rcKf4Ru7mC1T7VMaFgBqpIS8YJNbcgegF0IF1FpCS05wjdU5CktYAnPnvC+Pj+MFDeH+184kIHBWqPNG6dAzALxRgtKTlGdJ1l5Do+4EWI+0mvKojREnKoDczFnDeCFnM51u3I9Vce3rkf0djRQKFomPVUnPDqxlR5lDAssYAYNcECAkvGxKcBDbjWi/6NHlwjS1r28+0Jhvfxjx9O6hi4AW82Q2/kBE5P/eOwln/jKSbLgi7Iyim1FFHxkQH1FY5kcKhAzFcIq85rGFlzHRfPF9OIQSmONI9kcWQCxkk8aG1u1zwbjZRYLTxlwmZvynOgaWRpTN8Y4ReBDIG1klhva7nqqoM416oXBG71IKaCtjAwRlE6pgaqnIz/WQAb2FR541pqynX6dB6DB1nIWnatsWZJZlu+Bnhf9DBlUsO9ZSAf9Fa9nJAzwFCzaKIsvGJIeKSZ/h+vInkjaO/rxswErVROTfZy1lO2CJ/xnAgzFGrpDxNJPliv3McO9TGwYy/zHhE6Pdo8Xu6NsMisNU6TB8Bc26uLNv/7kWhNmNnBA1qt5akln6hOHrPBXGBiTNUL0IoFVPNdCbS0834zAYXfgtZLDzVpeLqmeMpqXbIYK0/NXe9etxuOcN40O+B/fTHHmO7dMgBZ4vAApVQUPr7ilumVHsWSMRP/0p5R9q4qr1bDm9S5YCPevdyYWTSceGSrXHmjYzJLBtpc/s77mynNqZEYjhnKk2XRNp6kp/FYRu+QdsX9vaDJbLKR2EnSC4fU6UOTO03IZU15j3wOsg30QrXoKntSJ/beF99cvFHuPrQPWxCtws0lLwkkHNVOm6XNO948Moy1w1pL4i68CwmceYZaYrYhmHGdLuescFQrZQaULDWhpK2Stys8Vs/XwwxNi9MHAFSXpdy/b+Aro5n87w+0MHRcllF8ZKbtQ/ym4oG7aREuo7o71JXJQPjZKTOtVM1EQx/FLM/5brnDSoyvLtoYtv9/tTnIC+8gR6eErkzaGmn8pftPhGNuz6yzx8JeLFoMD7VWbGTefj46KS+yMweFJnpReHEqwnukXpEYq19EWVyQa/Sb7navtKt80y/vRs0aNZp3iL23AOs0u1kQ1CFNY2y12Gor1koaH2FUd5jAQnaSKmgarLy0H/QVvR2g8B3+Fh49QhKYrd8N6LvvI80cwbEoqYWn5DWA=";
		char *_csdPassword = "12345678a";
		char *_uuid = "06a46e4b-b154-4c12-bb77-f9a63ed55ff2";
		char *_rfc = "LAN7008173R5";

	public:
		
		TEST_METHOD(UT_Stamp_V1)
		{
			
			string resultByToken = StampByToken(_url, _token, _pago10);
			string result = Stamp(_url, _user, _password, _pago10);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_Stamp_Pagos)
		{
			char* _cfdi = GetBase64(_pago10);
			
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			result = StampV2B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			result = StampV3B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			result = StampV4B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			_cfdi = _pago10;
			resultByToken = StampByToken(_url, _token, _cfdi);
			result = Stamp(_url, _user, _password, _cfdi);
			 status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV2(_url, _token, _cfdi);
			result = StampV2(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV3(_url, _token, _cfdi);
			result = StampV3(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV4(_url, _token, _cfdi);
			result = StampV4(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

		}
		TEST_METHOD(UT_Stamp_Conceptos)
		{
			char* _cfdi = GetBase64(_conceptos);
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

		}
		TEST_METHOD(UT_Stamp_ComercioExterior)
		{
			char* _cfdi = GetBase64(_comercioExterior);
			_resultExpect401 = "success";
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			result = StampV2B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			result = StampV3B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			result = StampV4B64(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			_cfdi = _comercioExterior;
			resultByToken = StampByToken(_url, _token, _cfdi);
			result = Stamp(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV2(_url, _token, _cfdi);
			result = StampV2(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV3(_url, _token, _cfdi);
			result = StampV3(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));

			resultByToken = StampByTokenV4(_url, _token, _cfdi);
			result = StampV4(_url, _user, _password, _cfdi);
			status = SplitJson(3, result);
			statusByToken = SplitJson(3, resultByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_Stamp_V2)
		{
			char* _cfdi = _pago10;
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV2(_url, _token, _cfdi);
			string result = StampV2(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_StampV3)
		{
			char* _cfdi = _pago10;
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV3(_url, _token, _cfdi);
			string result = StampV3(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_Stamp_V4)
		{
			char* _cfdi = _pago10;
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV4(_url, _token, _cfdi);
			string result = StampV4(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_StampV1B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect401 = "success";
			string resultByToken = StampByTokenB64(_url, _token, _cfdi);
			string result = StampB64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_StampV2B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV2B64(_url, _token, _cfdi);
			string result = StampV2B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_StampV3B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV3B64(_url, _token, _cfdi);
			string result = StampV3B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_StampV4B64)
		{
			char* _cfdi = GetBase64(_pago10);
			_resultExpect401 = "success";
			string resultByToken = StampByTokenV4B64(_url, _token, _cfdi);
			string result = StampV4B64(_url, _user, _password, _cfdi);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue(!(std::strcmp(status, _resultExpect401) == 0) && !(std::strcmp(status, _resultExpect404) == 0) && !(std::strcmp(status, _resultExpect500) == 0));
			Assert::IsTrue(!(std::strcmp(statusByToken, _resultExpect401) == 0) && !(std::strcmp(statusByToken, _resultExpect404) == 0) && !(std::strcmp(statusByToken, _resultExpect500) == 0));
		}
		TEST_METHOD(UT_CancelByXml)
		{
			char *_cancelation = _cancelationXml;
			_resultExpect401 = "acuse";
			string resultCancelationByXml = CancelByXml(_url, _user, _password, _cancelationXml);
			char* status = SplitJson(3, resultCancelationByXml);
			Assert::IsTrue(std::strcmp(status, _resultExpect401) == 0);
		}
		TEST_METHOD(UT_CancelByXmlToken)
		{
			char *_cancelation = _cancelationXml;
			_resultExpect401 = "acuse";
			string resultCancelationByXml = CancelByXmlToken(_url, _token, _cancelationXml);
			char* status = SplitJson(3, resultCancelationByXml);
			Assert::IsTrue(std::strcmp(status, _resultExpect401) == 0);
		}
		TEST_METHOD(UT_CancelByCSD)
		{
			char *_cancelation = _cancelationXml;
			_resultExpect401 = "acuse";
			string resultCancelationByXml = CancelByCSD(_url, _user, _password, _b64Cer, _b64Key, _csdPassword,_rfc,_uuid);
			char* status = SplitJson(3, resultCancelationByXml);
			Assert::IsTrue(std::strcmp(status, _resultExpect401) == 0);
		}
		TEST_METHOD(UT_CancelByCSDToken)
		{
			char *_cancelation = _cancelationXml;
			_resultExpect401 = "acuse";
			string resultCancelationByXml = CancelByCSDToken(_url, _token, _b64Cer, _b64Key, _csdPassword, _rfc, _uuid);
			char* status = SplitJson(3, resultCancelationByXml);
			Assert::IsTrue(std::strcmp(status, _resultExpect401) == 0);
		}
		TEST_METHOD(UT_Stamp_Error401)
		{
			_resultExpect401 = "401";
			string result = Stamp(_url, _user, "", _pago10);
			string resultByToken = StampByToken(_url, "ff", _pago10);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect401) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect401) == 0));
		}
		TEST_METHOD(UT_Stamp_Error404)
		{
			_resultExpect404 = "404";
			string result = Stamp("http://badendpoint.com", _user, _password, _pago10);
			string resultByToken = StampByToken("http://badendpoint.com", _token, _pago10);
			char* status = SplitJson(3, result);
			char* statusByToken = SplitJson(3, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect404) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect404) == 0));
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