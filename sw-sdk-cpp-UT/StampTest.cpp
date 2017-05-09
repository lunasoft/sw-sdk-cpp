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

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{
	
	TEST_CLASS(StampTest)
	{
	private:
		char *_url = "http://swservicestest-rc.azurewebsites.net";
		char *_user = "demo";
		char *_password = "123456789";
		char *_token = FindMyToken();//"T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbXB3YVZxTHdOdHAwVXY2NTdJb1hkREtXTzE3dk9pMmdMdkFDR2xFWFVPUXpTUm9mTG1ySXdZbFNja3FRa0RlYURqbzdzdlI2UUx1WGJiKzViUWY2dnZGbFloUDJ6RjhFTGF4M1BySnJ4cHF0YjUvbmRyWWpjTkVLN3ppd3RxL0dJPQ.T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbFlVcU92YUJTZWlHU3pER1kySnlXRTF4alNUS0ZWcUlVS0NhelhqaXdnWTRncklVSWVvZlFZMWNyUjVxYUFxMWFxcStUL1IzdGpHRTJqdS9Zakw2UGRiMTFPRlV3a2kyOWI5WUZHWk85ODJtU0M2UlJEUkFTVXhYTDNKZVdhOXIySE1tUVlFdm1jN3kvRStBQlpLRi9NeWJrd0R3clhpYWJrVUMwV0Mwd3FhUXdpUFF5NW5PN3J5cklMb0FETHlxVFRtRW16UW5ZVjAwUjdCa2g0Yk1iTExCeXJkVDRhMGMxOUZ1YWlIUWRRVC8yalFTNUczZXdvWlF0cSt2UW0waFZKY2gyaW5jeElydXN3clNPUDNvU1J2dm9weHBTSlZYNU9aaGsvalpQMUxrUndzK0dHS2dpTittY1JmR3o2M3NqNkh4MW9KVXMvUHhZYzVLQS9UK2E1SVhEZFJKYWx4ZmlEWDFuSXlqc2ZRYXlUQk1ldlZkU2tEdU10NFVMdHZKUURLblBxakw0SDl5bUxabDFLNmNPbEp6b3Jtd2Q1V2htRHlTdDZ6eTFRdUNnYnVvK2tuVUdhMmwrVWRCZi9rQkU9.7k2gVCGSZKLzJK5Ky3Nr5tKxvGSJhL13Q8W-YhT0uIo";
		char *_resultExpect = "";
		char* _xml = GetXml();
		char* _xmlB64 = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48Y2ZkaTpDb21wcm9iYW50ZSB4c2k6c2NoZW1hTG9jYXRpb249Imh0dHA6Ly93d3cuc2F0LmdvYi5teC9jZmQvMyBodHRwOi8vd3d3LnNhdC5nb2IubXgvc2l0aW9faW50ZXJuZXQvY2ZkLzMvY2ZkdjMzLnhzZCIgVmVyc2lvbj0iMy4zIiBTZXJpZT0iUm9ndWVPbmUiIEZvbGlvPSJITkZLMjMxIiBGZWNoYT0iMjAxNy0wNS0wOFQxMTo0MzoyNCIgU2VsbG89Ikx0MGl4dXRTdU5xT3RJSmd6aFFLRUU4b3ZXaGI2VXlRcDBkNnpMOEZpTG95eHp3Ri9vcEpoNnBMdWs0OUpMaGh5ZVFRU3lwV2RjYmlXT1FHRmhaZ2cvWW0ya3hybmc1c1VBcUVYZkl5Z1hVVFFITnVrcFBmN041M01qNFlhbGpLYStwVW1OZFZpaEgxNEQ3V2NhdFpJVFlJajRmQXlFTUl0VndJZDJ4bk5wWEt0VW5wd0JSVVFKYllaZU13YnlFMEI5MGpnRE50R25EMFhWM3Vkcm9kWTJtM0VITmkxWVZ5NzVyYTR3UVFmdnR2Z093V0NpZzFFYUZLWXRka2M2TXhTTUZQbXdBS2ROUmZaWDltOGJMTGlET09TWFBySTgvNUZPdE51d3FFUmVOTDkwbmRINmFObXBvWXBscEdJempSZ3p5RzJKOStrTWNHYW5IUHJFYWRGUT09IiBGb3JtYVBhZ289IjAxIiBOb0NlcnRpZmljYWRvPSIyMDAwMTAwMDAwMDMwMDAyMjc2MyIgQ2VydGlmaWNhZG89Ik1JSUZ6RENDQTdTZ0F3SUJBZ0lVTWpBd01ERXdNREF3TURBek1EQXdNakkzTmpNd0RRWUpLb1pJaHZjTkFRRUxCUUF3Z2dGbU1TQXdIZ1lEVlFRRERCZEJMa011SURJZ1pHVWdjSEoxWldKaGN5ZzBNRGsyS1RFdk1DMEdBMVVFQ2d3bVUyVnlkbWxqYVc4Z1pHVWdRV1J0YVc1cGMzUnlZV05wdzdOdUlGUnlhV0oxZEdGeWFXRXhPREEyQmdOVkJBc01MMEZrYldsdWFYTjBjbUZqYWNPemJpQmtaU0JUWldkMWNtbGtZV1FnWkdVZ2JHRWdTVzVtYjNKdFlXTnB3N051TVNrd0p3WUpLb1pJaHZjTkFRa0JGaHBoYzJsemJtVjBRSEJ5ZFdWaVlYTXVjMkYwTG1kdllpNXRlREVtTUNRR0ExVUVDUXdkUVhZdUlFaHBaR0ZzWjI4Z056Y3NJRU52YkM0Z1IzVmxjbkpsY204eERqQU1CZ05WQkJFTUJUQTJNekF3TVFzd0NRWURWUVFHRXdKTldERVpNQmNHQTFVRUNBd1FSR2x6ZEhKcGRHOGdSbVZrWlhKaGJERVNNQkFHQTFVRUJ3d0pRMjk1YjJGanc2RnVNUlV3RXdZRFZRUXRFd3hUUVZRNU56QTNNREZPVGpNeElUQWZCZ2txaGtpRzl3MEJDUUlNRWxKbGMzQnZibk5oWW14bE9pQkJRMFJOUVRBZUZ3MHhOakV3TWpFeU1EVTBNREZhRncweU1ERXdNakV5TURVME1ERmFNSUc0TVJ3d0dnWURWUVFERXhOSlRrMVBRaUJGUkUxQklGTkJJRVJGSUVOV01Sd3dHZ1lEVlFRcEV4TkpUazFQUWlCRlJFMUJJRk5CSUVSRklFTldNUnd3R2dZRFZRUUtFeE5KVGsxUFFpQkZSRTFCSUZOQklFUkZJRU5XTVNVd0l3WURWUVF0RXh4VVRVVTVOakEzTURsTVVqSWdMeUJJUlVkVU56WXhNREF6TkZNeU1SNHdIQVlEVlFRRkV4VWdMeUJJUlVkVU56WXhNREF6VFVSR1VrNU9NRGt4RlRBVEJnTlZCQXNVREZCeWRXVmlZWE5mUTBaRVNUQ0NBU0l3RFFZSktvWklodmNOQVFFQkJRQURnZ0VQQURDQ0FRb0NnZ0VCQUpncVorZXpKeWVKWEFDTUs4ZWhGcDY0ZWNBbDhqZllLQjR4TUp5MFJSYitxWEtSZXd4dExvamlURkVDV2RDeDI4M3RFa2RIVWo4Ykx6c0NmRkFNbnNQMkc0Q1MyYUUyLzFMTENIb1pwZEltYWFzTFgxWUpMMmJVenhLUUtpK1JsTDYzTTQ5eXlmdkdCakVnRzdmNlRNd1ZTVVNiZ0RGcFlBRkhxeDRMSytwMkdWSHVVVXpvaUltOHhSWWFXMVlQTWE0NTdiZTVXOHdzancwbkdSTGZvOGhSSWpQSGVka3d0Y3FZUGo1N3hzUFhNZnhXUDQ1dk9sVzdHdUxrTXEvRUNjY0h4SmlQaXRpVGhjREZLbGYvbUFSMGthdXg5TFRmZnZXaWxBMnVRQWx5VnlOVmpxZmRwdkRkcTR5Y1Rhb0lNWUtydi85UjMxZFEwQW1kWFQ4Y2ZiY0NBd0VBQWFNZE1Cc3dEQVlEVlIwVEFRSC9CQUl3QURBTEJnTlZIUThFQkFNQ0JzQXdEUVlKS29aSWh2Y05BUUVMQlFBRGdnSUJBRjVrd3Z5QlVwN0FkOTlEa3R6RWhySnduTVF5aEE3OXNWYzROczJTcExPTi9jVjI0NFpuRzVoZ1hrMmF3S2JIRWlTai9rZTdFaGdFcEdTODE4RVJzajdlVy93Umd1Z0JacmFWbjQ4R09uNnFYMHVWOUVqd1dFR0s1dVQ2SUROMjVpZ2VYeFZKSFAzaG40MGZYMkJQcXNhcVJQNDlZTXhjT1dEN21oV1JoMkU2Qm5vS1lqZ0hWSmJhdlVONnBqQ0JMbXk0aEt3Zml0YmpxdFVpaVdPbUJEdnZtTEZwRUdYRzhPWG4yeGxhZEJVa2ZDNHNmZ01CcFZaVnVFVjdScUFnQ1NDWjJ4bzZVRXlkNEtLcFRqYmRwMFRqNWd3K05taW92QVpId1UvTlBSb2pOOTVmL2liajcyNjhMQnIyRGNPNXJsbXI3c3p3SjNkdHd1ODZON0hrVXhXM3ZvM3FHSFRWSzJIUkJBcmRhOVZONHBFeUlMMFF0NDZjaTVyRllYQjJjQ1dVOFhBaDhnYVpueEpvTlRTWTRBNHlNSkc5VWZNLzJySEMrWXZPb3VJWjJrSloyaCtTd0tPWUdKT1g3NDlQL1FlRjRaL0wvT0RzM0UwOGJWN0lRbmExWkhtZDZ5ZFloWlZwaGVNZ05vTm5JRzZqZHpmeXVvOE5aQUlJVy9KR21QVEFOUEN3VFNIcUJZMWxtbnAvb1pOcmt4R1d0R2hibHRSZkJvRlFmVHFDWkFMbTZmc1ZlUXFIUTZhN1c0NUZKMlJEMW5sdFBTZG5pTW8zSXovdDRlSENqRnZNM2FPUnZBOW9KRVByNVp6ekJWMmZRT1hreVM4UWRzU1ZiNVptSkcrRnFaS0tsc2lhWDZ4aHFLNmdxVEx5Sk4rNy95cjlUL1paNE03VnJSb0wiIFN1YlRvdGFsPSIyMDAuMDAiIE1vbmVkYT0iTVhOIiBUaXBvQ2FtYmlvPSIxIiBUb3RhbD0iNjAzLjI4IiBUaXBvRGVDb21wcm9iYW50ZT0iSSIgTWV0b2RvUGFnbz0iUFVFIiBMdWdhckV4cGVkaWNpb249IjA2MzAwIiB4bWxuczpjZmRpPSJodHRwOi8vd3d3LnNhdC5nb2IubXgvY2ZkLzMiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiPjxjZmRpOkVtaXNvciBSZmM9IlRNRTk2MDcwOUxSMiIgTm9tYnJlPSJJTk1PQiBFRE1BIFNBIERFIENWICIgUmVnaW1lbkZpc2NhbD0iNjAxIiAvPjxjZmRpOlJlY2VwdG9yIFJmYz0iQUFBMDEwMTAxQUFBIiBOb21icmU9IlJvZG9sZm8gQ2FycmFuemEgUmFtb3MiIFVzb0NGREk9IkcwMyIgLz48Y2ZkaTpDb25jZXB0b3M+PGNmZGk6Q29uY2VwdG8gQ2xhdmVQcm9kU2Vydj0iNTAyMTE1MDMiIE5vSWRlbnRpZmljYWNpb249IlVUNDIxNTExIiBDYW50aWRhZD0iMSIgQ2xhdmVVbmlkYWQ9Ikg4NyIgVW5pZGFkPSJQaWV6YSIgRGVzY3JpcGNpb249IkNpZ2Fycm9zIiBWYWxvclVuaXRhcmlvPSIyMDAuMDAiIEltcG9ydGU9IjIwMC4wMCI+PGNmZGk6SW1wdWVzdG9zPjxjZmRpOlRyYXNsYWRvcz48Y2ZkaTpUcmFzbGFkbyBCYXNlPSIyMDAuMDAiIEltcHVlc3RvPSIwMDIiIFRpcG9GYWN0b3I9IlRhc2EiIFRhc2FPQ3VvdGE9IjAuMTYwMDAwIiBJbXBvcnRlPSIzMi4wOCIgLz48Y2ZkaTpUcmFzbGFkbyBCYXNlPSIyMzIuMDAiIEltcHVlc3RvPSIwMDMiIFRpcG9GYWN0b3I9IlRhc2EiIFRhc2FPQ3VvdGE9IjEuNjAwMDAwIiBJbXBvcnRlPSIzNzEuMjAiIC8+PC9jZmRpOlRyYXNsYWRvcz48L2NmZGk6SW1wdWVzdG9zPjwvY2ZkaTpDb25jZXB0bz48L2NmZGk6Q29uY2VwdG9zPjxjZmRpOkltcHVlc3RvcyBUb3RhbEltcHVlc3Rvc1RyYXNsYWRhZG9zPSI0MDMuMjgiPjxjZmRpOlRyYXNsYWRvcz48Y2ZkaTpUcmFzbGFkbyBJbXB1ZXN0bz0iMDAyIiBUaXBvRmFjdG9yPSJUYXNhIiBUYXNhT0N1b3RhPSIwLjE2MDAwMCIgSW1wb3J0ZT0iMzIuMDgiIC8+PGNmZGk6VHJhc2xhZG8gSW1wdWVzdG89IjAwMyIgVGlwb0ZhY3Rvcj0iVGFzYSIgVGFzYU9DdW90YT0iMS42MDAwMDAiIEltcG9ydGU9IjM3MS4yMCIgLz48L2NmZGk6VHJhc2xhZG9zPjwvY2ZkaTpJbXB1ZXN0b3M+PGNmZGk6Q29tcGxlbWVudG8+PHRmZDpUaW1icmVGaXNjYWxEaWdpdGFsIHhzaTpzY2hlbWFMb2NhdGlvbj0iaHR0cDovL3d3dy5zYXQuZ29iLm14L1RpbWJyZUZpc2NhbERpZ2l0YWwgaHR0cDovL3d3dy5zYXQuZ29iLm14L3NpdGlvX2ludGVybmV0L2NmZC9UaW1icmVGaXNjYWxEaWdpdGFsL1RpbWJyZUZpc2NhbERpZ2l0YWx2MTEueHNkIiBWZXJzaW9uPSIxLjEiIFVVSUQ9ImY3ZWE0ZmUyLThjMDctNDQyOS1iNTlmLWZkMzkzYTUwZGUyOSIgRmVjaGFUaW1icmFkbz0iMjAxNy0wNS0wOFQxNzoyMzoxMCIgUmZjUHJvdkNlcnRpZj0iQUFBMDEwMTAxQUFBIiBTZWxsb0NGRD0iTHQwaXh1dFN1TnFPdElKZ3poUUtFRThvdldoYjZVeVFwMGQ2ekw4RmlMb3l4endGL29wSmg2cEx1azQ5SkxoaHllUVFTeXBXZGNiaVdPUUdGaFpnZy9ZbTJreHJuZzVzVUFxRVhmSXlnWFVUUUhOdWtwUGY3TjUzTWo0WWFsakthK3BVbU5kVmloSDE0RDdXY2F0WklUWUlqNGZBeUVNSXRWd0lkMnhuTnBYS3RVbnB3QlJVUUpiWVplTXdieUUwQjkwamdETnRHbkQwWFYzdWRyb2RZMm0zRUhOaTFZVnk3NXJhNHdRUWZ2dHZnT3dXQ2lnMUVhRktZdGRrYzZNeFNNRlBtd0FLZE5SZlpYOW04YkxMaURPT1NYUHJJOC81Rk90TnV3cUVSZU5MOTBuZEg2YU5tcG9ZcGxwR0l6alJnenlHMko5K2tNY0dhbkhQckVhZEZRPT0iIE5vQ2VydGlmaWNhZG9TQVQ9IjIwMDAxMDAwMDAwMzAwMDIyMzIzIiBTZWxsb1NBVD0ibkU5Z0JnejdRQzdHZUNHeFBJb214b2N4NWlkdkpqbkNHZDNrTEZxRVkvdDByeFJLWmlPR1hIcGpYWTVNaS8zZmx2TGZXcWRWajNlSzVjbVUvejloYSszSSs0dVNUaGg0Vnp6MlJRTzY3UUJWekpRZHZrbUthZnFnb2lFL291TmsrcUdnd25ZQVU4dWRjeDRpaEdzQ1VyLzRvd2F1bEc2M3haQ1VLZzVDYUJRS2dFMThNNlJhY0U4TnVjZGdsdk1kbmkxK1h4Sld3VG5RR2dBVlkvcytIY1RKYnlBakMyUjZDNk9DWk1WRzk1cEhENjJhL3FGZTV1RHh6Mm1lb3N4ZFhudUppNmJQa2l6RDJMYkJ1R0Y4R2p4Z2l4bE5SRHVqNGFkenl4dW80NmN4N2pveW5BSnBCcTRNWkl1QlRXenZTeDIwdE44SzB1R1ppWWFpdEI2ZWxBPT0iIHhtbG5zOnRmZD0iaHR0cDovL3d3dy5zYXQuZ29iLm14L1RpbWJyZUZpc2NhbERpZ2l0YWwiIHhtbG5zOnhzaT0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEtaW5zdGFuY2UiIC8+PC9jZmRpOkNvbXBsZW1lbnRvPjwvY2ZkaTpDb21wcm9iYW50ZT4=";

	public:
		
		TEST_METHOD(UT_Stamp_V1)
		{
			_resultExpect = "success";
			string resultByToken = StampByToken(_url, _token, _xml);
			string result = Stamp(_url, _user, _password, _xml);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_V2)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV2(_url, _token, _xml);
			string result = StampV2(_url, _user, _password, _xml);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV3)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV3(_url, _token, _xml);
			string result = StampV3(_url, _user, _password, _xml);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_Stamp_V4)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV4(_url, _token, _xml);
			string result = StampV4(_url, _user, _password, _xml);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV1B64)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenB64(_url, _token, _xmlB64);
			string result = StampB64(_url, _user, _password, _xmlB64);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV2B64)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV2B64(_url, _token, _xmlB64);
			string result = StampV2B64(_url, _user, _password, _xmlB64);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV3B64)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV3B64(_url, _token, _xmlB64);
			string result = StampV3B64(_url, _user, _password, _xmlB64);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_StampV4B64)
		{
			_resultExpect = "success";
			string resultByToken = StampByTokenV4B64(_url, _token, _xmlB64);
			string result = StampV4B64(_url, _user, _password, _xmlB64);
			char* status = SplitJson(280, result);
			char* statusByToken = SplitJson(280, resultByToken);
			Logger::WriteMessage(status);
			Logger::WriteMessage(statusByToken);
			Assert::IsTrue((std::strcmp(status, _resultExpect) == 0));
			Assert::IsTrue((std::strcmp(statusByToken, _resultExpect) == 0));
		}
		TEST_METHOD(UT_ValidateIsXML)
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