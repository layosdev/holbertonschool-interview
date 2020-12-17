#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer
 *
 * @number: number
 *
 * Return: node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux, *node;

	if (head == NULL)
	{
		return (NULL);
	}
	aux = *head;
	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->n = number;
	node->next = NULL;
	if (aux == NULL || aux->n > number)
	{
		node->next = *head;
		*head = node;
		return (node);
	}
	while (aux)
	{
		if (aux->next != NULL)
		{
			if (aux->next->n > number)
			{
				node->next = aux->next;
				aux->next = node;
				return (node);
			}
			aux = aux->next;
		} else
		{
			node->next = NULL;
			aux->next = node;
			return (node);
		}
	}
	return (node);
}
