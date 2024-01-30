#include "binary_trees.h"

/**
 * binary_tree_node - Create Node
 * @parent: Parent node of the new node
 * @value: Value to store in the new node
 * Return: New Node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	return (new);
}
