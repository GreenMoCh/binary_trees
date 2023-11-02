#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: ptr to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl, hr;

	if (tree == NULL)
		return (0);
	hl = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hr = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (hl > hr ? hl : hr);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: ptr to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int hl, hr;

	if (tree == NULL)
		return (0);
	hl = binary_tree_height(tree->left);
	hr = binary_tree_height(tree->right);

	return (hl - hr);
}
