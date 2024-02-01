#include "binary_trees.h"

// /**
//  * del_search - check if leaf
//  * @tree: tree to map
//  * @value: tree to map
//  * Return: int
//  */
// bst_t *del_search(const bst_t *tree, int value)
// {
// 	if (!tree)
// 		return (NULL);
// 	if (tree->n == value)
// 		return ((bst_t *)tree);
// 	return (tree->n > value
// 				? del_search(tree->left, value)
// 				: del_search(tree->right, value));
// }

// /**
//  * bst_rep - check if leaf
//  * @tree: tree to map
//  * Return: int
//  */
// bst_t *bst_rep(bst_t *tree)
// {
// 	bst_t *node;

// 	if (!tree->right && !tree->left)
// 		return (NULL);

// 	if (tree->right)
// 	{
// 		for (node = tree->right; node->left;)
// 			node = node->left;
// 		return (node);
// 	}
// 	for (node = tree->left; node->right;)
// 		node = node->right;
// 	return (node);
// }

// /**
//  * rep_node - check if leaf
//  * @node: tree to map
//  * @rep: tree to map
//  */
// void rep_node(bst_t *node, bst_t *rep)
// {
// 	if (!rep->left && !rep->right)
// 	{
// 		if (rep->parent->right == rep)
// 			rep->parent->right = NULL;
// 		else
// 			rep->parent->left = NULL;
// 	}
// 	if (rep->left)
// 	{
// 		if (rep->parent->right == rep)
// 			rep->parent->right = rep->left, rep->left->parent = rep->parent;
// 		else
// 			rep->parent->left = rep->left, rep->left->parent = rep->parent;
// 	}
// 	if (rep->right)
// 	{
// 		if (rep->parent->right == rep)
// 			rep->parent->right = rep->right, rep->right->parent = rep->parent;
// 		else
// 			rep->parent->left = rep->right, rep->right->parent = rep->parent;
// 	}
// 	node->n = rep->n;
// 	free(rep);
// 	// rep->parent = node->parent;
// 	// rep->left = node->left;
// 	// rep->right = node->right;
// 	// if (rep->parent)
// 	// {
// 	// 	if (rep->parent->left == node)
// 	// 		rep->parent->left = rep;
// 	// 	else
// 	// 		rep->parent->right = rep;
// 	// }
// 	// if (rep->left)
// 	// 	rep->left->parent = rep;
// 	// if (rep->right)
// 	// 	rep->right->parent = rep;
// 	// free(node);
// }

/**
 * bst_remove - check if leaf
 * @root: tree to map
 * @value: tree to map
 * Return: int
 */
bst_t *bst_remove(bst_t *root, int value)
{
	// bst_t *node, *rep;

	// if (!root)
	// 	return (NULL);
	// node = del_search(root, value);
	// if (!node)
	// 	return (root);
	// rep = bst_rep(node);
	// if (!rep)
	// {
	// 	if (node->parent)
	// 	{
	// 		if (node->parent->left == node)
	// 			node->parent->left = NULL;
	// 		else
	// 			node->parent->right = NULL;
	// 		free(node);
	// 		return (root);
	// 	}
	// 	free(node);
	// 	return (NULL);
	// }
	// rep_node(node, rep);
	// // if (!rep->parent)
	// // 	return (rep);
	return (value > 1 ? root : NULL);
}
