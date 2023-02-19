#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - function that sorts array with bubble sort algorithm
 * @array: array input from the user
 * @size: the given arrays size
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	int val;
	int m;
	unsigned int k;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= size - 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				val = array[j];
				array[j] = array[j + 1];
				array[j + 1] = val;
				m = 1;
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k != size - 1)
					{
						printf(", ");
					}
				}
				putchar('\n');
			}
		}
		if (m == 0)
		{
			break;
		}
		m = 0;
	}
}
