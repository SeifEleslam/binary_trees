#include "binary_trees.h"

/**
 * nested_ext - check if leaf
 * @root: tree to map
 * Return: int
 */
int nested_ext(heap_t *root)
{
	heap_t *node;
	int i;

	if (!root->left && !root->right)
	{
		if (root->parent)
		{
			if (root->parent->left == root)
				root->parent->left = NULL;
			else
				root->parent->right = NULL;
		}
		free(root);
		return (1);
	}
	if (root->left && root->right)
		node = root->left->n > root->right->n
				   ? root->left
				   : root->right;

	else if (root->left)
		node = root->left;
	else
		node = root->right;
	i = root->n;
	root->n = node->n;
	nested_ext(node);
	return (i);
}
/**
 * heap_extract - check if leaf
 * @root: tree to map
 * Return: int
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);
	return (nested_ext(*root));
}
