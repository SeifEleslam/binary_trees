#include "binary_trees.h"

/**
 * bst_search - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	return (tree->n > value
				? bst_search(tree->left, value)
				: bst_search(tree->right, value));
}
