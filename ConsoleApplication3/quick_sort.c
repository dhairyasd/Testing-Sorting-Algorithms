#include "Header.h"


int partition(uint16 *arr, int low, int high)
{
	int middle = low;
	int i;
	for (i = low + 1; i <= high; i++)
	{
		if (arr[i] <= arr[middle])
		{
			pop_and_insert(arr, i, middle, arr[i], high + 1);
			middle++;
		}
	}
	return middle;
}


int Quick_sort(uint16 *arr, int low, int high, int size)
{
	if (low < high)
	{
		int middle;
		middle = partition(arr, low, high);
		Quick_sort(arr, low, middle - 1, middle - low);
		Quick_sort(arr, middle + 1, high, high - middle);
	}
	return 1;
}


int quick_sort(uint16 *arr, int size)
{
	return Quick_sort(arr, 0, size - 1, size);
}