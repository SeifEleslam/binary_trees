#include "binary_trees.h"

/**
 * tree_complete - check if leaf
 * @tree: tree to map
 * @level: tree to map
 * @min: func to run
 * @max: func to run
 * Return: num of nodes
 */
int tree_complete(const binary_tree_t *tree, int level, int *min, int *max)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
	{
		if (*max == -1 || *min == -1)
		{
			*max = level, *min = level - 1;
			return (1);
		}
		else if (level < *min || level > *max)
			return (0);
		*max = level;
		return (1);
	}
	if (!tree->left)
		return (0);
	left = tree_complete(tree->left, level + 1, min, max);
	right = tree_complete(tree->right, level + 1, min, max);
	if (!tree->right)
	{
		if (level >= *min && level <= *max)
		{
			*max = level;
			return ((!tree->left ? right : left));
		}
		return (0);
	}
	return (left && right ? 1 : 0);
}

/**
 * heap_complete - check if leaf
 * @tree: tree to map
 * Return: int
 */
int heap_complete(const binary_tree_t *tree)
{
	int min_level = -1, max_level = -1;

	if (!tree)
		return (0);
	return (tree_complete(tree, 0, &min_level, &max_level));
}

/**
 * heap_is_sorted - check if leaf
 * @tree: tree to map
 * Return: int
 */
int heap_is_sorted(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	return ((!tree->left || tree->n > tree->left->n) &&
					(!tree->right || tree->n > tree->right->n) &&
					heap_is_sorted(tree->left) &&
					heap_is_sorted(tree->right)
				? 1
				: 0);
}

/**
 * binary_tree_is_heap - check if leaf
 * @tree: tree to map
 * Return: int
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	return (heap_complete(tree) && heap_is_sorted(tree));
}
