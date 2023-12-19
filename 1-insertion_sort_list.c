#include <stdio.h>
#include "sort.h"

/**
 * lenght_list - calculate lenght of list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int lenght_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sort double linked list og integers
 * @list: double pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *tmp = NULL;
	listint_t *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;

	if (!list || !(*list) || lenght_list(*list) < 2)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			tmp = curr->prev->prev;
			tmp2 = curr->prev;
			tmp3 = curr;
			tmp4 = curr->next;

			tmp2->next = tmp4;
			if (tmp4)
				tmp4->prev = tmp2;
			tmp3->next = tmp2;
			tmp3->prev = tmp;
			if (tmp)
				tmp->next = tmp3;
			else
				*list = tmp3;
			tmp2->prev = tmp3;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
