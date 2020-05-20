#include "Header.h"



int insertion_sort (uint16 *arr, int size)
{
	int i;
	for (i = 1; i < size; i++)
	{
		int j;
		for (j = 0; j < i; j++)
			if (arr[j] > arr[i])
			{
				pop_and_insert(arr, i, j, arr[i], size);
				break;
			}
	}
	return 1;
}