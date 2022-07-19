#include "ISort.h"
#include "Sorts.h"
#include "Names.h"

int ISort::GetComprasionCounter()
{
	return comparisonCounter;
}

int ISort::GetSwapCountrt()
{
	return swapCounter;
}

void ISort::PrintCounters()
{
	std::cout << comparisonCounter << "\t\t" << swapCounter << std::endl;
}


