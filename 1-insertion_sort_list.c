#include "sort.h"
/**
 * insertion_sort_list - The algorithm for the insertion sort.
 * @list : Pointer to Pointer to head of doubly linked list.
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *tmp_next, *tmp_tmp, *tmp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while ((*tmp).next != NULL)
	{
		next = (*tmp).next;
		while ((*tmp).n > (*next).n)
		{
			tmp_next = (*next).next;
			tmp_tmp = (*tmp).prev;
			(*next).next = tmp;
			(*tmp).prev = next;
			(*tmp).next = tmp_next;
			if (tmp_next != NULL)
				(*tmp_next).prev = tmp;
			(*next).prev = tmp_tmp;
			tmp = next;
			if ((*tmp).prev == NULL)
				*list = tmp;
		}
		tmp = (*tmp).next;
	}
}
