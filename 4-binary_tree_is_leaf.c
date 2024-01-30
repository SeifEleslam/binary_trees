#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if leaf
 * @node: node to check
 * Return: true if leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->left && !node->right ? 1 : 0);
}
