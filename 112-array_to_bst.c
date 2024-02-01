#include "binary_trees.h"

/**
 * array_to_bst - check if leaf
 * @array: tree to map
 * @size: tree to map
 * Return: int
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	for (i = 0; i < size; i++)
		if (!bst_insert(&root, array[i]))
			return (NULL);
	return (root);
}
