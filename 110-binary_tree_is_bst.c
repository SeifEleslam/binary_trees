#include "binary_trees.h"

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
	if (tree->left)
		is_bst = is_bst && tree->n >= tree->left->n ? 1 : 0;
	if (tree->right)
		is_bst = is_bst && tree->n <= tree->right->n ? 1 : 0;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			is_bst = is_bst &&
							 (!tree->left || tree->parent->n > tree->left->n) &&
							 (!tree->right || tree->parent->n > tree->right->n)
						 ? 1
						 : 0;
		else
			is_bst = is_bst &&
							 (!tree->left || tree->parent->n < tree->left->n) &&
							 (!tree->right || tree->parent->n < tree->right->n)
						 ? 1
						 : 0;
	}
	return (left && right && is_bst ? 1 : 0);
}
