#include "binary_trees.h"

/**
 * binary_tree_height - Mesures the height of a binary tree
 *
 * @tree: ptr to the root node of the tree to mesure the height
 *
 * Return: The height of the tree starting at @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t height_l, height_r;

        if (tree == NULL)
                return (0);
        height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: ptr to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: ptr to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	return (size == (1ULL << (height + 1)) - 1);
}
