#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlab102
{
	TEST_CLASS(testlab102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(Count(), 1);
		}
	};
}
