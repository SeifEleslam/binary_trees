#include "binary_trees.h"

/**
 * is_prefect - check if perfect
 * @tree: tree to map
 * Return: true if leaf
 */
int is_prefect(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	left = is_prefect(tree->left);
	right = is_prefect(tree->right);
	return (left > 0 && right > 0 && left == right ? left + right : 0);
}

/**
 * binary_tree_is_perfect - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (is_prefect(tree) > 0 ? 1 : 0);
}
