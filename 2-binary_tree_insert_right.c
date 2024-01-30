#include "binary_trees.h"

/**
 * binary_tree_insert_right - Create Node
 * @parent: Parent node of the new node
 * @value: Value to store in the new node
 * Return: New Node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (!parent)
		return (NULL);

	tmp = parent->right;
	parent->right = binary_tree_node(parent, value);
	if (tmp && parent->right)
		parent->right->right = tmp,
		tmp->parent = parent->right;

	return (parent->right);
}
