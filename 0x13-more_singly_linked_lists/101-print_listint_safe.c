#include "lists.h"
#include <stdio.h>
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t node_count = 0;

	if (!head)
		exit(98);

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		node_count++;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) /* Loop detected */
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			return (node_count + 1);
		}
	}

	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		node_count++;
		slow = slow->next;
	}

	return (node_count);
}
