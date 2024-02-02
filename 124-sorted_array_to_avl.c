#include "binary_trees.h"

/**
 * insert - check if leaf
 * @tree: tree to map
 * @array: tree to map
 * @size: tree to map
 * @is_left: tree to map
 * Return: int
 */
void insert(avl_t *tree, int *array, size_t size, int is_left)
{
	size_t nested_size;
	avl_t *root;

	if (size <= 0)
		return (NULL);
	nested_size = size / 2 + (size % 2 == 0 ? -1 : 0);
	if (is_left)
		tree->left = binary_tree_node(tree, array[nested_size]),
		root = tree->left;
	else
		tree->right = binary_tree_node(tree, array[nested_size]),
		root = tree->right;
	insert(root, array, nested_size, 1);
	insert(root, array + nested_size + 1, size - nested_size - 1, 0);
}

/**
 * sorted_array_to_avl - check if leaf
 * @array: tree to map
 * @size: tree to map
 * Return: int
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t nested_size;

	nested_size = size / 2 + (size % 2 == 0 ? -1 : 0);
	root = binary_tree_node(NULL, array[nested_size]);
	insert(root, array, nested_size, 1);
	insert(root, array + nested_size + 1, size - nested_size - 1, 0);
	return (root);
}
