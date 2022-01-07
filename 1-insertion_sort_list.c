#include "sort.h"

/**
 * sorted_insert - Inserts a new node in sorted way in
 *			a sorted list
 * @head_ref: pointer to head node of doubly linked list
 * @newNode: Node to insert
 */

void sorted_insert(listint_t **head_ref, listint_t *newNode)
{
	listint_t *current;

	if (*head_ref == NULL)
		*head_ref = newNode;
	else if ((*head_ref)->n >= newNode->n)
	{
	newNode->next = *head_ref;
	newNode->next->prev = newNode;
	*head_ref = newNode;
	}
	else
	{
		current = *head_ref;

		while (current->next != NULL &&
				current->next->n < newNode->n)
			current = current->next;
		newNode->next = current->next;
		if (current->next != NULL)
			newNode->next->prev = newNode;
		current->next = newNode;
		newNode->prev = current;
	}
}

/**
 * insertion_sort_list - Sorts a list using insertion sorting algorithm
 *
 * @list: List to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *current = *list, *next = malloc(sizeof(listint_t));

	while (current != NULL)
	{
		next = current->next;
		current->prev = current->next = NULL;
		sorted_insert(&sorted, current);
		current = next;
	}
	*list = sorted;
}
