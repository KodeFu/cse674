/*

	File:
		Splay.cpp

	Purpose:
		Defines the functions which implement a Splay Tree.

	Author:
		mpvats@syr.edu

*/
#include "stdafx.h"
#include "Splay.h"


CSplay::CSplay()
{
	_root = NULL;
}


CSplay::~CSplay()
{
}

// Splay the tree
void CSplay::Splay(CNode*& node, int key)
{
	if (node == NULL)
	{
		// Bail out if node is NULL
		return;
	}

	// Left subtree
	if (key < node->key)
	{
		if (node->left == NULL)
		{
			// Bail out since key is not in tree
			return;
		}

		if (key < node->left->key)
		{
			// Splay to root
			Splay(node->left->left, key);

			// Zig rotation
			node = RotateRight(node);
		}
		else if (key > node->left->key)
		{
			// Splay to root
			Splay(node->left->right, key);

			if (node->left->right)
			{
				// Zag rotation
				node->left = RotateLeft(node->left);
			}
		}

		if (node->left)
		{
			// Zig rotation
			node = RotateRight(node);
		}
	}
	// Right subtree
	else if (key > node->key)
	{
		if (node->right == NULL)
		{
			// Bail out since key is not in tree
			return;
		}

		if (key < node->right->key)
		{
			// Splay to root 
			Splay(node->right->left, key);

			if (node->right->left)
			{
				// Zig rotation
				node->right = RotateRight(node->right);
			}
		}
		else if (key > node->right->key)
		{
			// Splay to root
			Splay(node->right->right, key);

			// Zag rotation
			node = RotateLeft(node);
		}

		if (node->right)
		{
			// Zag rotation
			node = RotateLeft(node);
		}
	}
	else
	{
		// This node is the key. Just return.
		return;
	}

}

// Search for a node
CNode* CSplay::Search(CNode*& node, int key)
{
	// Splay it, which brings searched for node to the root
	Splay(node, key);

	// Return found (root) node; it's also the passed in node,
	// but returned here as well for convenience.
	return node;
}

// Insert a node 
void CSplay::Insert(CNode*& node, int key)
{
	// Call the base class
	CBST::Insert(node, key);

	// Rebalance the tree
	Splay(node, key);
}

// Remove a node 
void CSplay::Remove(CNode*& node, int key)
{
	// Call the base class
	CBST::Remove(node, key);

	// Rebalance the tree
	Splay(node, key);
}
