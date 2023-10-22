#include "sort.h"

/**
 * insertion_sort_list - a function that make ascending sorting
 * of a doubly linked list
 * @list: pointer to pointer to the list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nextNode, *sorted;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (current = (*list)->next; current != NULL; current = nextNode)
	{
		nextNode = current->next;
		sorted = current;

		while (sorted->prev && sorted->n < sorted->prev->n)
		{
			if (sorted->next != NULL)
			{
				sorted->next->prev = sorted->prev;
				sorted->prev->next = sorted->next;
			}

			sorted->prev = sorted->prev->prev;
			sorted->next = sorted->prev ? sorted->prev->next : *list;
			if (sorted->next)
				sorted->next->prev = sorted;

			if (!sorted->prev)
				*list = sorted;

			if (sorted->prev)
				sorted->prev->next = sorted;
			else
				*list = sorted;

			print_list(*list);
		}
	}
}
