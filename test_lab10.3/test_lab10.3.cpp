#include "pch.h"
#include "../lab10.3/Source.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlab103
{
	TEST_CLASS(testlab103)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(main(), 0);
		}
	};
}
