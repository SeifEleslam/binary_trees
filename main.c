#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binary_trees.h"
/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
    size_t height_l;
    size_t height_r;

    height_l = tree->left ? 1 + _height(tree->left) : 0;
    height_r = tree->right ? 1 + _height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree)
        return;
    height = _height(tree);
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;
    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255);
        if (!s[i])
            return;
        memset(s[i], 32, 255);
    }
    print_t(tree, 0, 0, s);
    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (s[i][j] != ' ')
                break;
            s[i][j] = '\0';
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}
/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 10);
    return (root);
}
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    avl_t *root;
    avl_t *node;

    root = NULL;
    node = avl_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 1150);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 1250);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 1350);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 1450);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 1);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 2);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 3);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 4);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 5000);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 6000);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 7000);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 8888);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 9999);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 234);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 567);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 8910);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 11);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    return (0);
}
