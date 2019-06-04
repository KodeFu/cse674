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
	// Bail out if node is NULL or this node has the key
	if (node == NULL)
	{
		return;
	}

	// Key lies in left subtree  
	if (key < node->key)
	{
		// Key is not in tree, we are done  
		if (node->left == NULL)
		{
			return;
		}

		// Zig-Zig (Left Left)  
		if (key < node->left->key)
		{
			// First recursively bring the 
			// key as root of left-left  
			Splay(node->left->left, key);

			// Do first rotation for root,  
			// second rotation is done after else  
			node = RotateRight(node);
		}
		else if (key > node->left->key) // Zig-Zag (Left Right)  
		{
			// First recursively bring  
			// the key as root of left-right  
			Splay(node->left->right, key);

			// Do first rotation for root->left  
			if (node->left->right != NULL)
			{
				node->left = RotateLeft(node->left);
			}
		}

		// Do second rotation for root  
		if (node->left != NULL)
		{
			node = RotateRight(node);
		}
	}
	else if (key > node->key) // Key lies in right subtree  
	{
		// Key is not in tree, we are done  
		if (node->right == NULL) return;

		// Zig-Zag (Right Left)  
		if (key < node->right->key)
		{
			// Bring the key as root of right-left  
			Splay(node->right->left, key);

			// Do first rotation for root->right  
			if (node->right->left != NULL)
			{
				node->right = RotateRight(node->right);
			}
		}
		else if (key > node->right->key)// Zag-Zag (Right Right)  
		{
			// Bring the key as root of  
			// right-right and do first rotation  
			Splay(node->right->right, key);
			node = RotateLeft(node);
		}

		// Do second rotation for root  
		if (node->right != NULL)
		{
			node = RotateLeft(node);
		}
	}
	else
	{
		// This node is the key! Just return
		return;
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
