#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = _height(tree->left);
	right = _height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((int)(_height(tree->left) - _height(tree->right)));
}

