
#ifndef _HEADER_SORT_
#define _HEADER_SORT_

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


#define uint16 unsigned short


//	All sorting algos
int bubble_sort(uint16 * arr, int size);
int insertion_sort(uint16 *arr, int size);
int selection_sort(uint16 *arr, int size);
int quick_sort(uint16 *arr, int size);

//	Math functions
double average(double * values, int size);
double stddev(double * values, int size);
double minimum(double * values, int size);
double maximum(double * values, int size);


//	Other Miscallaneous functions
int read_file(char *file_name);
void check_ascending_sort(uint16 *arr, int size);
int pop_and_insert(uint16 *arr, int pop_pos, int insert_pos, uint16 insert_val, int size);


//	Dispatcher functions
void Calc_time_for_sorting_algo(char const *type_of_sort, int size);

#endif //_HEADER_SORT_