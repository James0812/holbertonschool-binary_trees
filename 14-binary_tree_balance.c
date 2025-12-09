#include "binary_trees.h"

/* helper height function */
static size_t _height(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	size_t left = _height(tree->left);
	size_t right = _height(tree->right);

	return (left > right ? left + 1 : right + 1);
}

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	return (int)(_height(tree->left) - _height(tree->right));
}

