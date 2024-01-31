#include "binary_trees.h"

/**
 * binary_tree_levelorder - check if leaf
 * @tree: tree to map
 * @func: func to run
 * @level: func to run
 * Return: num of nodes
 */
int binary_tree_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree || !func)
		return 0;
	if (level == 0)
	{
		func(tree->n);
		return (1);
	}
	return (binary_tree_level(tree->left, func, level - 1) +
			binary_tree_level(tree->right, func, level - 1));
}

/**
 * binary_tree_levelorder - check if leaf
 * @tree: tree to map
 * @func: func to run
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 0, not_done = 1;

	if (!tree || !func)
		return;
	while (not_done)
		not_done = binary_tree_level(tree, func, level),
		level++;
}
