#include "lists.h"

/**
 * is_palindrome - Check palindrome lists
 *
 * @head: head of the list
 *
 * Return:	palindome status
 */

int is_palindrome(listint_t **head)
{
	int beg, end;
	int arr[100000];
	listint_t *node;

	if (!head)
	{
		return (1);
	}

	node = *head;

	if (!node)
	{
		return (1);
	}

	beg = 0;

	for (end = 0; node; end++)
	{
		arr[end] = node->n;
		node = node->next;
	}

	end--;

	while (beg <= end)
	{
		if (arr[beg] != arr[end])
		{
			return (0);
		}
		beg++;
		end--;
	}
	return (1);
}
