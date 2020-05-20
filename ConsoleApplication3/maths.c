#include "Header.h"
#include <math.h>

double average(double * values,int size)
{
	int i;
	double total = 0;
	for (i = 0; i < size; i++)
	{
		total += values[i];
	}
	return (double)total / size;
}


double stddev(double * values, int size)
{
	double mean = average(values, size);
	double total = 0;
	int i;
	for (i = 0; i < size; i++)
		total += pow(values[i] - mean, 2);

	return sqrt(total / size);
}


double minimum(double * values, int size)
{
	double min = values[0];
	int i;
	for (i = 0; i < size; i++)
		if (values[i] < min)
			min = values[i];
	return min;
}


double maximum(double * values, int size)
{
	double max = values[0];
	int i;
	for (i = 0; i < size; i++)
		if (values[i] > max)
			max = values[i];
	return max;
}