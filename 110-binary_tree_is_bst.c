#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if leaf
 * @tree: tree to map
 * Return: int
 */
int node_is_bst(const binary_tree_t *tree, int val, int is_left)
{
	if (!tree)
		return (1);
	return (node_is_bst(tree->left, val, is_left) &&
					node_is_bst(tree->right, val, is_left) &&
					((is_left && tree->n < val) || !is_left && tree->n > val)
				? 1
				: 0);
}

/**
 * binary_tree_is_bst - check if leaf
 * @tree: tree to map
 * Return: int
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1, left, right;

	if (!tree)
		return (0);

	left = !tree->left || binary_tree_is_bst(tree->left) ? 1 : 0;
	right = !tree->right || binary_tree_is_bst(tree->right) ? 1 : 0;
	return (node_is_bst(tree->left, tree->n, 1) &&
					node_is_bst(tree->right, tree->n, 0) && left && right
				? 1
				: 0);
}
