#include "binary_trees.h"

/**
 * binary_tree_height - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	size_t add = tree->left || tree->right ? 1 : 0;

	return (add + (left_height > right_height ? left_height : right_height));
}
