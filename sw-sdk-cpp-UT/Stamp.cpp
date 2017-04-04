#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\sw-sdk-cpp\StampServices.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace swsdkcppUT
{
	TEST_CLASS(Stamp)
	{
	public:

		TEST_METHOD(StampV1byToken)
		{
			SW::StampServices stamp = SW::StampServices("myUrl...", "mytoken...");
			string result = stamp.Timbrar();
			Assert::IsTrue(!result.empty());
		}

	};
}