#include "binary_trees.h"

/**
 * power - check if leaf
 * @base: base
 * @exponent: exponent
 * Return: power
 */
int power(int base, int exponent)
{
	int result = 1;

	for (int i = 0; i < exponent; i++)
		result *= base;
	return (result);
}

/**
 * tree_height - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return (1 + MAX(left_height, right_height));
}

/**
 * tree_leaves - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
int tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (tree_leaves(tree->left) + tree_leaves(tree->right));
}

/**
 * binary_tree_is_perfect - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((tree_leaves(tree) == power(2, tree_height(tree) - 1)) ? 1 : 0);
}
