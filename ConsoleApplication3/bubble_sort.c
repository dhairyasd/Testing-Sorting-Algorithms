#include "header.h"

int bubble_sort(uint16 * arr, int size)
{
	int i;
	for( i = 0; i < size; i++)// i in range(0,len(arr)):
	{
		int j;
		for(j = 0; j < size - i - 1; j++)//j in range(0,len(arr)-i-1):
		{
			if(arr[j] > arr[j+1])
			{
				int swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
				//arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
	return 1;
}