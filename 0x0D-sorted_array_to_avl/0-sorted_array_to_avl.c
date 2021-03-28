#include "binary_trees.h"

/**
 * nodes_binary - create binary tree
 * @arr: pointer to the first element of the array to be converted
 * @init_pos: position
 * @final_pos: position
 * @tnode: node
 * Return: node
 */
avl_t *nodes_binary(int *arr, int init_pos, int final_pos, avl_t **tnode)
{
	avl_t *node = NULL;
	avl_t *prev = NULL;
	avl_t *next = NULL;
	int aux = 0;

	if (init_pos > final_pos)
	{
		return (NULL);
	}

	aux = (init_pos + final_pos) / 2;

	nodes_binary(arr, init_pos, aux - 1, &prev);
	nodes_binary(arr, aux + 1, final_pos, &next);

	node = malloc(sizeof(avl_t));
	if (!node)
	{
		return (NULL);
	}

	node->n = arr[aux];
	node->left = prev;
	node->right = next;

	if (prev)
	{
		prev->parent = node;
	}

	if (next)
	{
		next->parent = node;
	}

	*tnode = node;
	return (node);
}

/**
 * sorted_array_to_avl - create binary tree
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node = NULL;

	if (!array)
	{
		return (NULL);
	}

	size = (int)size;
	if (!nodes_binary(array, 0, size - 1, &node))
	{
		return (NULL);
	}
	return (node);
}
