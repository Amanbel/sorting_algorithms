#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - function that swaps to elements
 * @a: first element
 * @b: second element
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int temp;

	if (*a == *b)
		return;
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - sorting algorithm that is an extension of insertion sort
 * @array: user given array
 * @size: length of the given array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int n = 1;
	unsigned int m;

	while (n < size)
	{
		n = n * 3 + 1;
	}

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			j = i;
			m = i;
			while (j >= n && array[j - n] > array[m])
			{
				swap(&array[j - n], &array[m]);
				j = j - n;
				m--;
			}
		}
		if (n < size)
			print_array(array, size);
		n = (n - 1) / 3;
	}
}
