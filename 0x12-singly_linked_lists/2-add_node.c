#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be inserted.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len = 0;

	/* Calculate the length of the string */
	while (str[len])
		len++;

	/* Allocate memory for new node */
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	new_node->len = len;
	new_node->next = (*head);

	/* Set head to the new node */
	(*head) = new_node;

	return (new_node);
}
