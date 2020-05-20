#include "Header.h"


void check_ascending_sort(uint16 *arr, int size)
{
	int i;
	for (i = 1; i < size; i++)
		if (arr[i] < arr[i - 1])
		{
			printf("\n\t Given array is NOT SORTED!!");
			return;
		}
}


/*
		This function opens the text file specified in the filename argument, reads its values into the global variable "Array"
		and returns the number of numbers read.
*/
int read_file(char *file_name)
{
	extern uint16 *Array;
	FILE *F;
	F = fopen(file_name, "r");
	if (F == NULL) {
		printf("\n\tNULL file pointer, exiting!");
		return 1;
	}

	int i = 0;
	Array = (uint16 *)malloc(sizeof(uint16));
	while (!feof(F))
	{
		int a;
		fscanf(F, "%d ", &a);
		Array[i] = (uint16)a;
		i++;
		if (i % 1000 == 1)
			Array = (uint16 *)realloc(Array, sizeof(uint16) * (i + 1000));
	}
	Array = (uint16 *)realloc(Array, sizeof(uint16) * i);
	fclose(F);
	return i;
}

/*
	This function removes an element from the position provided in the variable pop_pos, and replaces another position (insert_pos) in the 
	array with insert_val. This function first pops the value from the array and then inserts it so that the length or size of the array 
	isn't affected. 

	Return value:
	 0	:	if the 'pop_pos' and the 'insert_pos' values are outside the range of the array
	 1	:	if everything went fine
*/
int pop_and_insert(uint16 *arr, int pop_pos, int insert_pos, uint16 insert_val, int size)
{
	if (pop_pos > size || pop_pos < 0 || insert_pos > size || insert_pos < 0)
		return 0;

	if (pop_pos < insert_pos)
	{
		int i;
		for (i = pop_pos; i < insert_pos; i++)
			arr[i] = arr[i + 1];
		arr[insert_pos] = insert_val;
	}
	else if (pop_pos > insert_pos)
	{
		int i;
		for (i = pop_pos; i > insert_pos; i--)
			arr[i] = arr[i - 1];
		arr[insert_pos] = insert_val;
	}
	else if (pop_pos == insert_pos)
		arr[insert_pos] = insert_val;

	return 1;

}