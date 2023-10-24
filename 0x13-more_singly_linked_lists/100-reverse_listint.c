#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *curr = *head;
	listint_t *next = NULL;

	while (curr)
	{
		next = curr->next;  /* Store next node before changing curr's next */
		curr->next = prev;  /* Reverse current node's next pointer */
		prev = curr;        /* Move prev to current node for next iteration */
		curr = next;        /* Move to next node */
	}

	*head = prev;
	return (*head);
}
