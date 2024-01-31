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
	node->parent = tree->parent;
	tree->parent = node;
	if (tree->left)
		tree->left->parent = tree;
	if (node->parent)
	{
		if (node->parent->left == tree)
			node->parent->left = node;
		else
			node->parent->right = node;
	}
	return (node);
}
