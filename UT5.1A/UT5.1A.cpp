#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.1A/Pay.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT51A
{
	TEST_CLASS(UT51A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pay a(1, 1);

			a.SetFirst(2);
			a.SetSecond(2);

			Assert::AreEqual(1.0, a.Summa(1));
		}
	};
}