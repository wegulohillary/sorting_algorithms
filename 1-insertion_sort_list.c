#include "sort.h"
/**
* insertion_sort_list -  sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
* @list: list to be sorted
* Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL; /* traverses list */

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			/* link next and previous nodes together */
			if (current->next != NULL)
				current->next->prev = current->prev;
			/* move to previous node, insert temp node before it */
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			/* if node is new head of list, set it to *list */
			if (!current->prev)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
