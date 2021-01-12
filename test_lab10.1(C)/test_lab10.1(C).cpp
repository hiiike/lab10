#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.1(C)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlab811
{
	TEST_CLASS(testlab811)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(search(), 4);

		}

	};
}
