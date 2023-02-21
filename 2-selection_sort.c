#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - a function that uses selection sort
 * algorithm to sort an array
 * @array: array given by the user
 * @size: size of the given array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	int small;
	int m = -1;
	int val;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		small = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < small)
			{
				small = array[j];
				m = j;
			}
		}
		if (m >= 0)
		{
			val = array[i];
			array[i] = small;
			array[m] = val;
			print_array(array, size);
		}
	}
}
