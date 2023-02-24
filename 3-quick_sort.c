#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void quick_recur(int *arr, int l, int r, size_t n);
void swap(int *a, int *b);
int partition(int *arr, int l, int r);

/**
 * quick_sort - algorithm that uses recursion to sort integers
 * @array: user given array
 * @size: size of the given array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	quick_recur(array, 0, size - 1, size);
}

/**
 * quick_recur - recursive part of the recursion
 * @arr: array input
 * @l: left most part of the array
 * @r: right most part of the array
 * Return: Nothing
 */

void quick_recur(int *arr, int l, int r, size_t n)
{
	int p;

	if (l < r)
	{
		p = partition(arr, l, r);
		print_array(arr, n);
		quick_recur(arr, l, p - 1, n);
		quick_recur(arr, p + 1, r, n);
	}
}

/**
 * swap - swaps two elements
 * @a: element one
 * @b: element two
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function that partitoins a given array
 * @l: left most side of the array
 * @r: right most side of the array
 * @arr: the whole array
 * Return: the index of the pivot
 */

int partition(int *arr, int l, int r)
{
	int pivot = arr[r];
	int i = l;
	int j;

	for (j = l; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return (i);
}
