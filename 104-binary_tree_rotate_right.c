#include "binary_trees.h"

/**
 * binary_tree_rotate_right - check if leaf
 * @tree: tree to map
 * Return: int
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree || !tree->left)
		return (tree);
	node = tree->left;
	tree->left = node->right;
	node->right = tree;
	node->parent = NULL;
	tree->parent = node;
	return (node);
}
