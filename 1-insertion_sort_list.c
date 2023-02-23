#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_func - swaps two list elements
 * @a: left element
 * @b: right element
 * @list: all list elements
 * Return: pointer to the element that has been swaped
 * to the left most side
 */

listint_t *swap_func(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev)
		(a->prev)->next = b;
	else
		*list = b, b->prev = NULL;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	b->next = a;
	return (a);
}

/**
 * insertion_sort - sorts the given doubly linked list
 * @list: user input of a doubly linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;
	listint_t *left, *right;

	if (!list || !(*list) || !(*list)->next)
		return;

	ptr = (*list)->next;
	while (ptr)
	{
		left = ptr->prev;
		right = ptr;
		while (right->prev && right->n < left->n)
		{
			ptr = swap_func(left, right, list);
			print_list(*list);
			if (!right->prev)
				break;
			left = right->prev;
		}
		ptr = ptr->next;
	}
}
