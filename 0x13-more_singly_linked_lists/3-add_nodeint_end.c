#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: double pointer to the start of the list.
 * @n: integer to be included in the new node.
 *
 * Return: address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL) /* if the list is empty, make new node the head */
	{
		*head = new_node;
		return (new_node);
	}

	/* traverse to the last node of the list */
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	return (new_node);
}
