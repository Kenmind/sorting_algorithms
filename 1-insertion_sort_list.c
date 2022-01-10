#include "sort.h"

/**
 * sorted_insert - Inserts a new node in sorted way in
 * a sorted list
 * @head_ref: pointer to head node of doubly linked list
 * @newNode: Node to insert
 */

void sorted_insert(listint_t **head_ref, listint_t *newNode)
{
	listint_t *temp = NULL;

	temp = newNode->prev;
	if (newNode->next)
		newNode->next->prev = temp;
	if (temp->prev)
		temp->prev->next = newNode;
	else
		*head_ref = newNode;
	newNode->prev = newNode->prev->prev;
	temp->next = newNode->next;
	temp->prev = newNode;
	newNode->next = temp;
}

/**
 * insertion_sort_list - Sorts a list using insertion sorting algorithm
 *
 * @list: List to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *prev_tmp = NULL, *prev = NULL;

	if (!list)
		return;
	current = *list;
	while (current)
	{
		prev = current->prev;
		while (prev)
		{
			if (current->n >= prev->n)
				break;
			sorted_insert(list, current);
			prev_tmp = prev;
			prev = current;
			current = prev_tmp;
			print_list(*list);
			prev = prev->prev;
			current = current->prev;
		}
		current = current->next;
	}
}
