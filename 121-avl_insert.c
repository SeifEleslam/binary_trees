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
	int right_bfactor, left_bfactor;

	right_bfactor = abs(binary_tree_balance(tree->right));
	left_bfactor = abs(binary_tree_balance(tree->left));
	if (tree->right &&
		right_bfactor >
			left_bfactor &&
		abs(binary_tree_balance(tree->right->right)) >
			abs(binary_tree_balance(tree->right->left)))
		binary_tree_rotate_left(tree);
	else if (tree->left &&
			 left_bfactor > right_bfactor &&
			 abs(binary_tree_balance(tree->left->left)) >
				 abs(binary_tree_balance(tree->left->right)))
		binary_tree_rotate_right(tree);
	else if (right_bfactor > left_bfactor)
		binary_tree_rotate_right(tree->right),
			binary_tree_rotate_left(tree);
	else
		binary_tree_rotate_left(tree->left),
			binary_tree_rotate_right(tree);
}

/**
 * balance_outer - check if leaf
 * @tree: tree to map
 * Return: int
 */
avl_t *balance_outer(avl_t *tree)
{
	avl_t *node;

	if (!tree)
		return (NULL);
	node = balance_outer(tree->left);
	if (node)
		return (node);
	node = balance_outer(tree->right);
	if (node)
		return (node);
	if (abs(binary_tree_balance(tree)) > 1)
		return (tree);
	return (NULL);
}

/**
 * avl_insert - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *outer;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node = avl_new(*tree, value);
	while ((*tree)->parent)
		*tree = (*tree)->parent;
	for (outer = balance_outer(*tree); outer; outer = balance_outer(*tree))
	{
		binary_tree_print(*tree);
		avl_rotate(outer);
		while ((*tree)->parent)
			*tree = (*tree)->parent;
	}
	return (node);
}
