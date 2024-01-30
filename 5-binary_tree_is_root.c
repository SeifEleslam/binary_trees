#include "binary_trees.h"

/**
 * binary_tree_is_root - check if leaf
 * @node: node to check
 * Return: true if leaf
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent ? 1 : 0);
}
