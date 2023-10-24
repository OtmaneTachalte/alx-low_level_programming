#include "lists.h"

/**
 * detect_loop - detects a loop in a linked list
 * @head: pointer to the start of the linked list
 *
 * Return: address of the node where the loop starts, or NULL if no loop
 */
listint_t *detect_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (slow);
	}

	return (NULL);
}

/**
 * free_listint_safe - safely frees a linked list that could contain loops
 * @h: double pointer to the start of the linked list
 *
 * Return: the number of nodes in the list that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes_freed = 0;
	listint_t *loop_node, *temp;

	if (!h || !*h)
		return (0);

	loop_node = detect_loop(*h);

	if (loop_node)
	{
		listint_t *start = *h;

		while (start != loop_node)
		{
			start = start->next;
			nodes_freed++;
		}
		/* break the loop */
		start->next = NULL;
	}

	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		nodes_freed++;
	}

	*h = NULL;

	return (nodes_freed);
}
