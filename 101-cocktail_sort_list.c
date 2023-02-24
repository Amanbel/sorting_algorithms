#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps 2 nodes
 * @a: node one
 * @b: node two
 * Return: Nothing
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * reverse_sort - function to sort the list in the reverse order
 * @head: head of list
 * @tail: tail of the list
 * @list: original head of the list
 * Return: new head
 */
listint_t *reverse_sort(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 * cocktail_sort_list - sorting algorithm similar to bubble sort
 * @list: doubly linked list
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail, *len;
	int i = 0, j = 0, swaped = 1;

	if (!list || !*list)
		return;

	len = *list;
	for (i = 0; len; i++)
		len = len->next;

	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		swaped = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap(head, head->next);
				swaped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = reverse_sort(head, tail, *list);
		*list = head;
		j++;
	}
}
