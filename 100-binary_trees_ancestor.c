#include "binary_trees.h"

/**
 * is_child - get ancestor
 * @parent: tree to map
 * @child: tree to map
 * Return: true if leaf
 */
int is_child(const binary_tree_t *parent, const binary_tree_t *child)
{
	if (!parent || !child)
		return (0);
	if (parent->right == child || parent->left == child)
		return (1);
	return (is_child(parent->left, child) ||
					is_child(parent->right, child)
				? 1
				: 0);
}

/**
 * binary_trees_ancestor - get ancestor
 * @first: tree to map
 * @second: tree to map
 * Return: true if leaf
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (!first || !second || !first->parent || !second->parent)
		return (NULL);
	return (is_child(first->parent, second)
				? first->parent
			: is_child(second->parent, first)
				? second->parent
				: binary_trees_ancestor(first->parent, second));
}
