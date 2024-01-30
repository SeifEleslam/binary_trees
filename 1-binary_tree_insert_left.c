#include "binary_trees.h"

/**
 * binary_tree_insert_left - Create Node
 * @parent: Parent node of the new node
 * @value: Value to store in the new node
 * Return: New Node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (!parent)
		return (NULL);

	tmp = parent->left;

	parent->left = binary_tree_node(parent, value);
	if (tmp)
		parent->left->left = tmp,
		tmp->parent = parent->left;

	return (parent->left);
}
