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
	unsigned int i, j, n;
	int val;

	if (array == NULL || size < 2)
		return;
	n = 1;

	while (n < size / 3)
	{
		n = n * 3 + 1;
	}

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			val = array[i];
			j = i;
			while (j >= n && array[j - n] > val)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = val;
		}
		print_array(array, size);
		n /= 3;
	}
}
