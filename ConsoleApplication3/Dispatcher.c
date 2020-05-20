#include "Header.h"
#include <time.h>
#include <string.h>

extern uint16 *Array;
#define NO_OF_TIMES 10

#define BUBBLE_TEXT "bubble"
#define INSERTION_TEXT "insertion"
#define SELECTION_TEXT "selection"
#define QUICK_TEXT "quick"
#define MERGE_TEXT "merge"

typedef enum
{
	BUBBLE_SORT,
	INSERTION_SORT,
	SELECTION_SORT,
	QUICK_SORT,
	MERGE_SORT
} algos;


double dispatch(enum algos algo, int size)
{
	clock_t t;
	switch (algo)
	{
		case BUBBLE_SORT:
		{
			t = clock();
			bubble_sort(Array, size);							//call to sorting algo
			t = clock() - t;
		}
		break;
		case INSERTION_SORT:
		{
			t = clock();
			insertion_sort(Array, size);							//call to sorting algo
			t = clock() - t;
		}
		break;
		case SELECTION_SORT:
		{
			t = clock();
			selection_sort(Array, size);							//call to sorting algo
			t = clock() - t;
		}
		break;
		case QUICK_SORT:
		{
			t = clock();
			quick_sort(Array, size);							//call to sorting algo
			t = clock() - t;
		}
		break;
		case MERGE_SORT:
		{
			t = clock();
			merge_sort(Array, size);							//call to sorting algo
			t = clock() - t;
		}
		break;
		default:
			return -1;
	}
	return (double)t;
}


void copy_paste(uint16 *to, uint16 *from, int size)
{
	int temp;
	for (temp = 0; temp < size; temp++)
		to[temp] = from[temp];
}


void Calc_time_for_sorting_algo(char const *type_of_sort, int size)
{

	enum algos algo;
	if (!_strcmpi(type_of_sort, BUBBLE_TEXT))
		algo = BUBBLE_SORT;
	else if (!_strcmpi(type_of_sort, INSERTION_TEXT))
		algo = INSERTION_SORT;
	else if (!_strcmpi(type_of_sort, SELECTION_TEXT))
		algo = SELECTION_SORT;
	else if (!_strcmpi(type_of_sort, QUICK_TEXT))
		algo = QUICK_SORT;
	else if (!_strcmpi(type_of_sort, MERGE_TEXT))
		algo = MERGE_SORT;
	else
	{
		printf("\n\tInvalid type of sorting, returning! ");
		return;
	}


	uint16 *backup = (uint16 *)malloc(sizeof(uint16) * size);
	copy_paste(backup, Array, size);

	int k;
	double all_times[NO_OF_TIMES];
	for (k = 0; k < NO_OF_TIMES; k++)
	{
		all_times[k] = dispatch(algo, size);

		check_ascending_sort(Array, size);

		if (k != NO_OF_TIMES - 1)
			copy_paste(Array, backup, size);
	}

	printf("\n\tPortion of Sorted array is: ");
	int j;
	for (j = 0; j < 10; j++)
		printf("%d ", (unsigned int)Array[j]);
	printf("...... ");
	for (j = size - 10; j < size; j++)
		printf("%d ", (unsigned int)Array[j]);

	copy_paste(Array, backup, size);

	printf("\n\n\
	Average Time taken to execute the sorting:	%f\n\
	Standard Deviation in the time is:		%f\n\
	Minimum value of time is:			%f\n\
	Maximum value of time is:			%f",
		average(all_times, NO_OF_TIMES),
		stddev(all_times, NO_OF_TIMES),
		minimum(all_times, NO_OF_TIMES),
		maximum(all_times, NO_OF_TIMES));
	
	free(backup);
}