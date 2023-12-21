#include "pch.h"
#include "CppUnitTest.h"
#include <stack>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
	TEST_CLASS(StackTests)
	{
	public:

		TEST_METHOD(ObjectCreationOnStack)
		{
			std::stack<int> intStack;

			// Checking whether the created object is stored on the stack
			Assert::IsTrue(&intStack != nullptr);
		}
	};
}

namespace HeapTests
{
	TEST_CLASS(HeapTests)
	{
	public:

		TEST_METHOD(ObjectCreationOnHeap)
		{
			std::unique_ptr<int> intPtr(new int(42));

			// Checking if an object is created on hippy
			Assert::IsTrue(intPtr != nullptr);
		}
	};
}
