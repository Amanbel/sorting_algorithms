#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b)'
void max_heapify(int *array, size_t size, size_t base, size_t root);

/**
 * swap - swap two elements
 * @a: element one
 * @b: element two
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = temp;
}

/**
 * max_heapify - binary tree to binary heap
 * @array: given array
 * @size: length of the array
 * @base: index of base tree
 * @root: root node of binary tree
 * Return: Nothing
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 1;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - sorting algorithm that uses a binary tree
 * @array: given array
 * @size: length of the array
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
