#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t linked list
 * @head: double pointer to the head of the list
 * @index: index of the node to be deleted, starting from 0
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current_node = *head;
    dlistint_t *node_to_delete;

    if (head == NULL || *head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = current_node->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current_node);
        return (1);
    }

    for (unsigned int i = 0; i < index - 1; i++)
    {
        current_node = current_node->next;
        if (current_node == NULL)
            return (-1);
    }

    node_to_delete = current_node->next;
    if (node_to_delete == NULL)
        return (-1);

    current_node->next = node_to_delete->next;
    if (node_to_delete->next != NULL)
        node_to_delete->next->prev = current_node;

    free(node_to_delete);
    return (1);
}
