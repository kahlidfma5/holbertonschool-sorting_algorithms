#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;
		tmp = current->next;

		while (insert && insert->n > current->n)
		{
			/* Swap nodes */
			if (insert->prev)
				insert->prev->next = current;
			else
				*list = current;

			if (current->next)
				current->next->prev = insert;

			insert->next = current->next;
			current->prev = insert->prev;

			current->next = insert;
			insert->prev = current;

			insert = current->prev;
			print_list(*list);
		}

		current = tmp;
	}
}
