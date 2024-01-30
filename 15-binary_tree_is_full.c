#include "binary_trees.h"

/**
 * binary_tree_is_full - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */

int binary_tree_is_full(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	return (binary_tree_is_full(tree->left) &&
					binary_tree_is_full(tree->right)
				? 1
				: 0);
}
