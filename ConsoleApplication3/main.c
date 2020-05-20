#include "Header.h"


uint16 *Array;


int main()
{

	int size = read_file("Unsorted array.txt");

	printf("\n\tNumber of bytes read : %d", size);

	printf("\n\tPortion of Un-Sorted array is: ");
	int j;
	for (j = 0; j < 10; j++)
		printf("%d ", (unsigned int)Array[j]);
	printf("...... ");
	for (j = size - 10; j < size; j++)
		printf("%d ", (unsigned int)Array[j]);

	printf("\n\n\t\tFor Bubble Sort");
	Calc_time_for_sorting_algo("bubble", size);


	printf("\n\n\t\tFor Insertion Sort");
	Calc_time_for_sorting_algo("insertion", size);


	printf("\n\n\t\tFor Selection Sort");
	Calc_time_for_sorting_algo("Selection", size);


	printf("\n\n\t\tFor Quick Sort");
	Calc_time_for_sorting_algo("quick", size);


	printf("\n\n\t\tFor Merge Sort");
	Calc_time_for_sorting_algo("merge", size);

	free(Array);
	return 0;
}




//some changes













/*//Testing main Code
int main()
{
	uint16 *arr = (uint16 *)malloc(sizeof(uint16) * 20);
	{
		int temp;
		uint16 b[] = { 60, 43, 58, 43, 40, 91, 22, 46, 10, 48, 60, 62, 6, 52, 54, 30, 79, 98, 23, 7 };
		for (temp = 0; temp < 20; temp++)
			arr[temp] = b[temp];
	}
	//Array = arr;
	printf("\n\tUnSorted array is: ");
	int j;
	for (j = 0; j < 20; j++)
		printf("%d ", (unsigned int)arr[j]);
	quick_sort(arr, 20);
	printf("\n\n\tSorted array is: ");
	for (j = 0; j < 20; j++)
		printf("%d ", (unsigned int)arr[j]);

	check_ascending_sort(arr, 20);

	free(arr);
}*/