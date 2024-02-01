#include "binary_trees.h"

/**
 * array_to_avl - check if leaf
 * @array: tree to map
 * @size: tree to map
 * Return: int
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
