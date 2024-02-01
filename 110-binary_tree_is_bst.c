#include "binary_trees.h"

/**
 * node_is_bst - check if leaf
 * @tree: tree to map
 * @val: tree to map
 * @is_left: tree to map
 * Return: int
 */
int node_is_bst(const binary_tree_t *tree, int val, int is_left)
{
	if (!tree)
		return (1);
	if (node_is_bst(tree->left, val, is_left) &&
		node_is_bst(tree->right, val, is_left) &&
		((is_left && tree->n < val) || (!is_left && tree->n > val)))
		return (1);
	return (0);
}

/**
 * binary_tree_is_bst - check if leaf
 * @tree: tree to map
 * Return: int
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = !tree->left || binary_tree_is_bst(tree->left) ? 1 : 0;
	right = !tree->right || binary_tree_is_bst(tree->right) ? 1 : 0;
	if (node_is_bst(tree->left, tree->n, 1) &&
		node_is_bst(tree->right, tree->n, 0) && left && right)
		return (1);
	return (0);
}
