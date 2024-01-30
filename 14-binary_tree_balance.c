#include "binary_trees.h"

/**
 * binary_tree_balance - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int addition = 0;

	if (!tree)
		return (0);
	addition += tree->left ? 1 : 0;
	addition -= tree->right ? 1 : 0;

	return (addition +
			binary_tree_balance(tree->left) - binary_tree_balance(tree->right));
}
