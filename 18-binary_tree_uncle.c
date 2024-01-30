#include "binary_trees.h"

/**
 * binary_tree_sibling - check if leaf
 * @node: tree to map
 * Return: true if leaf
 */
binary_tree_t *binary_tree_uncle(const binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	return (node->parent->parent->left == node->parent
				? node->parent->parent->right
				: node->parent->parent->left);
}
