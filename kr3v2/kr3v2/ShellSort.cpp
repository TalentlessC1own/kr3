#include "ShellSort.h"

void ShellSort::PrintCounters()
{
    std::cout << "Shellsort\t";
    ISort::PrintCounters();
}

void ShellSort::Sort(std::vector<int>& arr, int size)
{
    for (int gap = size/2; gap > 0; gap--)
        for (int i = 0; (i + gap) < size; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                std::swap(arr[i], arr[i + gap]); swapCounter++;
            }
            comparisonCounter++;
        }
        

    

}
