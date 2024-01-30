#include "binary_trees.h"

/**
 * subtree_height - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t subtree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = subtree_height(tree->left);
	right_height = subtree_height(tree->right);
	return (1 + MAX(left_height, right_height));
}

/**
 * binary_tree_balance - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	return (subtree_height(tree->left) - subtree_height(tree->right));
}
