#include "BubbleSort.h"

void BubbleSort::PrintCounters()
{
	std::cout << "Bubblesort\t";
	ISort::PrintCounters();
}

void BubbleSort::Sort(std::vector<int>& arr, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		bool end = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			comparisonCounter++;
			if (arr[j] > arr[j + 1])
			{
				end = false;
				swapCounter++;
				std::swap(arr[j], arr[j + 1]);
			}
		}
		if (end)
			return;
	}
}
