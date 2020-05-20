#include "Header.h"

int selection_sort(uint16 *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		int j, min;
		min = i;
		for (j = i+1; j < size; j++)
			if (arr[min] > arr[j])
				min = j;
		
		j = arr[min];
		arr[min] = arr[i];
		arr[i] = j;

	}
	return 1;
}