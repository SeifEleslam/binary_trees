#include "binary_trees.h"

/**
 * binary_tree_depth - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((tree->parent ? 1 : 0) + binary_tree_depth(tree->parent));
}
