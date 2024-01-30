#include "binary_trees.h"

/**
 * binary_tree_sibling - check if leaf
 * @node: tree to map
 * Return: true if leaf
 */
int binary_tree_sibling(const binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (node->parent->left == node
				? node->parent->right
				: node->parent->left);
}
