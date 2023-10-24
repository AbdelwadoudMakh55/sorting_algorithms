#include "sort.h"
/**
 * cocktail_sort_list - The algorithm for the cocktail sort.
 * @list : Pointer to head of doubly linked list.
 * Return: Void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *init, *tmp, *prev, *next, *next_next, *tmp_prev, *tmp_next,
	*prev_prev;

	if (list == NULL || *list == NULL)
		return;
	init = *list;
	while (init != NULL)
	{
		tmp = init;
		while ((*tmp).next != NULL)
		{
			next = (*tmp).next;
			if ((*tmp).n > (*next).n)
			{
				next_next = (*next).next;
				tmp_prev = (*tmp).prev;
				if (tmp_prev != NULL)
					(*tmp_prev).next = next;
				else
					*list = next;
				(*next).prev = tmp_prev;
				(*next).next = tmp;
				(*tmp).prev = next;
				(*tmp).next = next_next;
				if (next_next != NULL)
					(*next_next).prev = tmp;
				print_list(*list);
			}
			else
				tmp = (*tmp).next;
		}
		while ((*tmp).prev != NULL)
		{
			prev = (*tmp).prev;
			if ((*tmp).n < (*prev).n)
			{
				tmp_next = (*tmp).next;
				prev_prev = (*prev).prev;
				if (prev_prev != NULL)
					(*prev_prev).next = tmp;
				else
					*list = tmp;
				(*tmp).next = prev;
				(*tmp).prev = prev_prev;
				(*prev).prev = tmp;
				(*prev).next = tmp_next;
				if (tmp_next != NULL)
					(*tmp_next).prev = prev;
				print_list(*list);
			}
			else
				tmp = (*tmp).prev;
		}
		init = (*init).next;
	}
}
