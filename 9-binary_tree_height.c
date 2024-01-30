#include "binary_trees.h"

/**
 * binary_tree_height - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}
