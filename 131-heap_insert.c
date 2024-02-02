#include "binary_trees.h"

/**
 * tree_size - check if leaf
 * @tree: tree to map
 * Return: true if leaf
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * power - check if leaf
 * @base: tree to map
 * @exponent: tree to map
 * Return: true if leaf
 */
int power(int base, int exponent)
{
	int result = 1, i;

	for (i = 0; i < exponent; i++)
		result *= base;
	return result;
}

/**
 * complete_insert - check if leaf
 * @tree: tree to map
 * @order: tree to map
 * @size: tree to map
 * Return: int
 */
heap_t *complete_insert(heap_t *tree, int order, int size)
{
	heap_t *dir;
	if (size <= 2)
	{
		if (order >= 2)
		{
			tree->right = binary_tree_node(tree, 1);
			return (tree->right);
		}
		else
		{
			tree->left = binary_tree_node(tree, 1);
			return (tree->left);
		}
	}
	if (order <= size / 2)
		dir = tree->left, size = size / 2;
	else
		dir = tree->right, order = order - size / 2, size = size / 2;
	return complete_insert(dir, order, size);
}

/**
 * swt - check if leaf
 * @node: tree to map
 * @parent: tree to map
 * Return: int
 */
heap_t *swt(heap_t *node, heap_t *parent)
{
	int i;

	i = node->n;
	node->n = parent->n;
	parent->n = i;
	return (parent);
}

/**
 * heap_insert - check if leaf
 * @tree: tree to map
 * Return: int
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int level = 0, order = 0;
	heap_t *node;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	order = tree_size(*root);
	for (level = 0; order >= power(2, level); level++)
		order -= power(2, level);
	order++;
	node = complete_insert(*root, order, power(2, level));
	node->n = value;
	while (node->parent && node->n > node->parent->n)
		node = swt(node, node->parent);
	return (node);
}
