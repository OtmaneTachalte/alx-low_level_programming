#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head of the list.
 * @index: the index of the node to retrieve.
 *
 * Return: node at index or NULL if node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int count = 0;

    while (head)
    {
        if (count == index)
            return (head);
        count++;
        head = head->next;
    }
    
    return (NULL);
}
