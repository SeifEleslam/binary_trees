#include "binary_trees.h"

/**
 * bst_new - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
bst_t *bst_new(bst_t *tree, int value)
{
	binary_tree_t *node;

	if (tree->n > value)
	{
		if (tree->left)
			return (bst_new(tree->left, value));
		tree->left = binary_tree_node(tree, value);
		return (tree->left);
	}
	if (tree->right)
		return (bst_new(tree->right, value));
	tree->right = binary_tree_node(tree, value);
	return (tree->right);
}

/**
 * bst_insert - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (bst_new(*tree, value));
}
