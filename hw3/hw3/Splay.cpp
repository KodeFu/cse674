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
	// Base cases: root is NULL or  
	// key is present at root  
	if (node == NULL || node->key == key)
	{
		return;
	}

	// Key lies in left subtree  
	if (node->key > key)
	{
		// Key is not in tree, we are done  
		if (node->left == NULL) return;

		// Zig-Zig (Left Left)  
		if (node->left->key > key)
		{
			// First recursively bring the 
			// key as root of left-left  
			Splay(node->left->left, key);

			// Do first rotation for root,  
			// second rotation is done after else  
			node = RotateRight(node);
		}
		else if (node->left->key < key) // Zig-Zag (Left Right)  
		{
			// First recursively bring  
			// the key as root of left-right  
			Splay(node->left->right, key);

			// Do first rotation for root->left  
			if (node->left->right != NULL)
				node->left = RotateLeft(node->left);
		}

		// Do second rotation for root  
		if (node->left == NULL)
		{
			return; //  node: 
		}
		else
		{
			node = RotateRight(node);
		}
	}
	else // Key lies in right subtree  
	{
		// Key is not in tree, we are done  
		if (node->right == NULL) return;

		// Zig-Zag (Right Left)  
		if (node->right->key > key)
		{
			// Bring the key as root of right-left  
			Splay(node->right->left, key);

			// Do first rotation for root->right  
			if (node->right->left != NULL)
				node->right = RotateRight(node->right);
		}
		else if (node->right->key < key)// Zag-Zag (Right Right)  
		{
			// Bring the key as root of  
			// right-right and do first rotation  
			Splay(node->right->right, key);
			node = RotateLeft(node);
		}

		// Do second rotation for root  
		if (node->right == NULL)
		{
			return; // node;
		}
		else
		{
			node = RotateLeft(node);
		}
	}
}

// Search for a node
CNode* CSplay::Search(CNode*& node, int key)
{
	// Splay it, which brings searched for node to the root
	Splay(node, key);

	// Return found (root) node
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
