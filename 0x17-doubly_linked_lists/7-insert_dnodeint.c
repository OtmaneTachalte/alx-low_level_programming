#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the doubly linked list
 * @idx: index of the list where the new node should be added, starting at 0
 * @n: data for the new node
 *
 * Return: (dlistint_t *) address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0) /* Add at the beginning */
		return (add_dnodeint(h, n));

	temp = *h;
	for (i = 0; temp != NULL && i < idx; i++)
		temp = temp->next;

	if (temp == NULL && i == idx) /* Add at the end */
		return (add_dnodeint_end(h, n));
	else if (temp != NULL)
	{
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		new_node->prev = temp->prev;
		new_node->next = temp;
		if (temp->prev != NULL)
			temp->prev->next = new_node;
		temp->prev = new_node;

		return (new_node);
	}

	return (NULL); /* Index out of range */
}
