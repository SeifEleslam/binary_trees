#include "binary_trees.h"

/**
 * avl_height - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t avl_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	left_height = avl_height(tree->left);
	right_height = avl_height(tree->right);
	return (1 + MAX(left_height, right_height));
}

/**
 * is_bst - check if leaf
 * @tree: tree to map
 * @val: tree to map
 * @is_left: tree to map
 * Return: int
 */
int is_bst(const binary_tree_t *tree, int val, int is_left)
{
	if (!tree)
		return (1);
	if (is_bst(tree->left, val, is_left) &&
		is_bst(tree->right, val, is_left) &&
		((is_left && tree->n < val) || (!is_left && tree->n > val)))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - check if leaf
 * @tree: tree to map
 * Return: int
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree->left, tree->n, 1) &&
					is_bst(tree->right, tree->n, 0) &&
					abs((int)avl_height(tree->left) - (int)avl_height(tree->right)) < 2 &&
					(!tree->left || binary_tree_is_avl(tree->left)) &&
					(!tree->right || binary_tree_is_avl(tree->right))
				? 1
				: 0);
}
