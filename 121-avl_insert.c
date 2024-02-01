#include "binary_trees.h"

/**
 * avl_new - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
avl_t *avl_new(avl_t *tree, int value)
{
	if (tree->n == value)
		return (NULL);
	if (tree->n > value)
	{
		if (tree->left)
			return (avl_new(tree->left, value));
		tree->left = binary_tree_node(tree, value);
		return (tree->left);
	}
	if (tree->right)
		return (avl_new(tree->right, value));
	tree->right = binary_tree_node(tree, value);
	return (tree->right);
}

/**
 * avl_rotate - check if leaf
 * @tree: tree to map
 */
void avl_rotate(avl_t *tree)
{
	if (tree->right && tree->right->right)
		binary_tree_rotate_left(tree);
	else if (tree->left && tree->left->left)
		binary_tree_rotate_right(tree);
	else if (tree->right)
		binary_tree_rotate_right(tree->right),
			binary_tree_rotate_left(tree);
	else
		binary_tree_rotate_left(tree->left),
			binary_tree_rotate_right(tree);
}

/**
 * avl_insert - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node = avl_new(*tree, value);
	if (node->parent && abs(binary_tree_balance(node->parent)) > 0 &&
		node->parent->parent && abs(binary_tree_balance(node->parent->parent)) > 1)
		avl_rotate(node->parent->parent);
	return (node);
}
