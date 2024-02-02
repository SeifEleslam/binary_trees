#include "binary_trees.h"

/**
 * heap_capacity - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t heap_capacity(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_capacity(tree->left) + heap_capacity(tree->right));
}

/**
 * heap_to_sorted_array - check if leaf
 * @heap: tree to map
 * @size: tree to map
 * Return: int
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr, size_tracker, i;

	*size = heap_capacity(heap);
	arr = malloc((*size) * sizeof(int));
	if (!arr)
		return (NULL);
	size_tracker = *size;
	for (i = 0; i < size_tracker; i++)
		arr[i] = heap_extract(&heap);
	return (arr);
}
