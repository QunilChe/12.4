#include "pch.h"
#include "CppUnitTest.h"
#include "../12.4/12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			Elem* L = NULL;
			insert(L, 1);
			hasAdjacentDuplicates(L);
			Assert::AreEqual(t, 0);
		}
	};
}
