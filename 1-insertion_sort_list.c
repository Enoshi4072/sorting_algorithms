#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion Sort algorithm
 *
 * @list: The pointer to the head of the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
listint_t *present, *node_b_present;
if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;
present = (*list)->next;
while (present)
{
node_b_present = present->prev;
while (node_b_present && node_b_present->n > present->n)
{
if (node_b_present->prev)
	node_b_present->prev->next = present;
else
	*list = present;

present->prev = node_b_present->prev;
node_b_present->prev = present;
node_b_present->next = present->next;
if (present->next)
	present->next->prev = node_b_present;
present->next = node_b_present;

node_b_present = present->prev;
print_list(*list);
}
present = present->next;
}
}
