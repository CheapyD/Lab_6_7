#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6_7/Lab_6_7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest67
{
	TEST_CLASS(Labtest67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[6] = {-3, 4, 12, -5, 2, 3 };
			int elem = Search_End(&a[0], &a[6], &a[0]);
			Assert::AreEqual(elem, 3);
		}
	};
}
