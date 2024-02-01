#include "binary_trees.h"

/**
 * del_search2 - check if leaf
 * @tree: tree to map
 * @value: tree to map
 * Return: int
 */
bst_t *del_search2(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	return (tree->n > value
				? del_search2(tree->left, value)
				: del_search2(tree->right, value));
}

/**
 * rep_node2 - check if leaf
 * @node: tree to map
 * @rep: tree to map
 */
void rep_node2(bst_t *node, bst_t *rep)
{
	if (!rep->left && !rep->right)
	{
		if (rep->parent->right == rep)
			rep->parent->right = NULL;
		else
			rep->parent->left = NULL;
	}
	if (rep->left)
	{
		if (rep->parent->right == rep)
			rep->parent->right = rep->left, rep->left->parent = rep->parent;
		else
			rep->parent->left = rep->left, rep->left->parent = rep->parent;
	}
	if (rep->right)
	{
		if (rep->parent->right == rep)
			rep->parent->right = rep->right, rep->right->parent = rep->parent;
		else
			rep->parent->left = rep->right, rep->right->parent = rep->parent;
	}
	node->n = rep->n;
	free(rep);
}

/**
 * avl_rotate2 - check if leaf
 * @tree: tree to map
 */
void avl_rotate2(avl_t *tree)
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
 * balance_outer2 - check if leaf
 * @tree: tree to map
 * Return: int
 */
avl_t *balance_outer2(avl_t *tree)
{
	avl_t *node;

	if (!tree)
		return (NULL);
	node = balance_outer2(tree->left);
	if (node)
		return (node);
	node = balance_outer2(tree->right);
	if (node)
		return (node);
	if (abs(binary_tree_balance(tree)) > 1)
		return (tree);
	return (NULL);
}

/**
 * bst_remove - check if leaf
 * @root: tree to map
 * @value: tree to map
 * Return: int
 */
avl_t *avl_remove(bst_t *root, int value)
{
	avl_t *node, *rep, *outer;

	if (!root)
		return (NULL);
	node = del_search2(root, value);
	if (!node)
		return (root);

	if (!node->right && !node->left)
		rep = (NULL);
	else if (node->right)
		for (rep = node->right; rep->left;)
			rep = rep->left;
	else
		for (rep = node->left; rep->right;)
			rep = rep->right;

	if (!rep)
	{
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		free(node);
		return (NULL);
	}
	rep_node2(node, rep);
	while ((root)->parent)
		root = (root)->parent;
	for (outer = balance_outer2(root); outer; outer = balance_outer2(root))
	{
		avl_rotate2(outer);
		while ((root)->parent)
			root = (root)->parent;
	}
	return (root);
}
