#include "sort.h"
/**
 * insertion_sort_list - The algorithm for the insertion sort.
 * @list : Pointer to Pointer to head of doubly linked list.
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *tmp_next, *tmp_prev, *tmp, *prev_prev;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (tmp != NULL)
	{
		prev = (*tmp).prev;
		while (prev != NULL)
		{
			if ((*tmp).n < (*prev).n)
			{
				tmp_next = (*tmp).next;
				tmp_prev = (*tmp).prev;
				(*tmp).next = prev;
				prev_prev = (*prev).prev;
				if (prev_prev == NULL)
					*list = tmp;
				else
					(*prev_prev).next = tmp;
				(*tmp).prev = prev_prev;
				(*prev).prev = tmp;
				if (tmp_next != NULL)
					(*tmp_next).prev = tmp_prev;
				(*tmp_prev).next = tmp_next;
				print_list(*list);
			}
			prev = (*prev).prev;
		}
		tmp = (*tmp).next;
	}
}
