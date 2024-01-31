#include "binary_trees.h"

/**
 * binary_tree_rotate_left - check if leaf
 * @tree: tree to map
 * Return: int
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree || !tree->right)
		return (tree);
	node = tree->right;
	tree->right = node->left;
	node->left = tree;
	node->parent = tree->parent;
	tree->parent = node;
	return (node);
}
