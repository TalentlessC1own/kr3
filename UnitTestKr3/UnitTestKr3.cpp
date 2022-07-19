
#include "CppUnitTest.h"
#include "..\kr3v2\ISort.h"
#include "..\kr3v2\ISort.cpp"
#include"..\kr3v2\BubbleSort.h"
#include "..\kr3v2\InsertionSort.h"
#include "..\kr3v2\QuickSort.h"
#include "..\kr3v2\SelectionSort.h"
#include"..\kr3v2\ShellSort.h"
#include"..\kr3v2\BubbleSort.cpp"
#include "..\kr3v2\InsertionSort.cpp"
#include "..\kr3v2\QuickSort.cpp"
#include "..\kr3v2\SelectionSort.cpp"
#include"..\kr3v2\ShellSort.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKr3
{

	TEST_CLASS(UnitTestKr3)
	{
	private:
		BubbleSort buble_sort;
		InsertionSort insertion_sort;
		SelectionSort selection_sort;
		ShellSort shell_sort;
		QuickSort quick_sort;
		std::vector <int> result = { 1,2,3,4,5 };
		std::vector <int> start = { 5,4,1,2,3 };
	public:
		
		TEST_METHOD(BubleTest)
		{
			std::vector <int> temp = start;
			buble_sort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(InsertionTest)
		{
			std::vector <int> temp = start;
			insertion_sort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(SelectionTest)
		{
			std::vector <int> temp = start;
			selection_sort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(ShellTest)
		{
			std::vector <int> temp = start;
			shell_sort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(QuickTest)
		{
			std::vector <int> temp = start;
			quick_sort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}
	};
}
