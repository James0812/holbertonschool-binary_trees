#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists
 *         or if node/parent is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	if (!grandparent)
		return (NULL);

	if (grandparent->left && grandparent->left != parent)
		return (grandparent->left);

	if (grandparent->right && grandparent->right != parent)
		return (grandparent->right);

	return (NULL);
}

