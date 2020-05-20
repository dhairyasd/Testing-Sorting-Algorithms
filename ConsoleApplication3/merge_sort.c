#include "Header.h"

void merge(uint16 *arr, int low, int middle, int high)
{
	int i = low, j = middle + 1;
	while (i <= middle && j <= high)
	{
		if (arr[i] >= arr[j])
		{
			pop_and_insert(arr, j, i, arr[j], high);
			middle++;
			j++;
		}
		i++;
	}
}


int Merge_sort(uint16 *arr, int low, int high)
{
	if (low < high)
	{
		int middle = low + ((high - low) / 2);
		Merge_sort(arr, low, middle);
		Merge_sort(arr, middle + 1, high);

		merge(arr, low, middle, high);
	}
	return 1;
}

int merge_sort(uint16 *arr, int size)
{
	return Merge_sort(arr, 0, size - 1);
}