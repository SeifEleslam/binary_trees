#include "binary_trees.h"

/**
 * array_to_heap - check if leaf
 * @array: tree to map
 * @size: tree to map
 * Return: int
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
