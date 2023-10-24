#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *temp, *ps, *nt;

	if (!list || !*list || !(*list)->next)
		return;

	temp = (*list)->next;
	ps = temp->prev;
	nt = temp->next;

	while (temp)
	{
		while (ps && temp->n < ps->n)
		{
			if (nt)
				nt->prev = ps;
			temp->next = ps;
			temp->prev = ps->prev;
			if (ps->prev)
				(ps->prev)->next = temp;
			ps->prev = temp;
			ps->next = nt;
			nt = ps;
			ps = temp->prev;
			if ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
		}
		temp = nt;
		if (temp)
		{
			nt = temp->next;
			ps = temp->prev;
		}
	}
}

/**
 * swap_list -  function that sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @ps: previous node
 * @temp: current or temp value
 * @nt: next node
 * @h: thr head of list
*/
void swap_list(listint_t *ps, listint_t *temp, listint_t *nt, listint_t **h)
{
	while (ps && temp && ps->n > temp->n)
	{
		if (nt)
			nt->prev = ps;
		temp->next = ps;
		temp->prev = ps->prev;
		if (ps->prev)
			(ps->prev)->next = temp;
		ps->prev = temp;
		ps->next = nt;
		nt = ps;
		ps = temp->prev;
		if ((*h)->prev)
			*h = (*h)->prev;
		print_list(*h);
	}
}
