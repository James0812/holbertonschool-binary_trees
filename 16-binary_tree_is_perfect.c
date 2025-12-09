#include "binary_trees.h"

/**
 * _binary_tree_height - Helper function to compute height of tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, 0 if NULL
 */
static size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = _binary_tree_height(tree->left);
	right = _binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * _binary_tree_size - Helper function to compute number of nodes
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
static size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (!tree)
		return (0);

	height = _binary_tree_height(tree);
	size = _binary_tree_size(tree);

	/* A perfect binary tree has size = 2^height - 1 */
	if (size == ((size_t)(1 << height) - 1))
		return (1);
	return (0);
}

