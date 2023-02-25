#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - retrives the maximum integer from an array
 * @array: given array
 * @size: the length of the array
 * Return: Nothing
 */

int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array using the counting sort algorithm
 * @array: given array
 * @size: lenght of the given array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *arr, *sorted, k, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
		return;

	k = get_max(array, size);
	arr = malloc(sizeof(int) * (k + 1));
	if (arr == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (k + 1); i++)
		arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		arr[array[i]] += 1;

	for (i = 0; i < (k + 1); i++)
		arr[i + 1] = arr[i] + arr[i + 1];
	print_array(arr, k + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[arr[array[i]] - 1] = array[i];
		arr[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(arr);
}
