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

// Seach for a node
CNode* CSplay::Search(CNode* root, int key)
// This function brings the key at  
// root if key is present in tree.  
// If key is not present, then it  
// brings the last accessed item at  
// root. This function modifies the  
// tree and returns the new root  
{  
    // Base cases: root is NULL or  
    // key is present at root  
    if (root == NULL || root->key == key)  
        return root;  
  
    // Key lies in left subtree  
    if (root->key > key)  
    {  
        // Key is not in tree, we are done  
        if (root->left == NULL) return root;  
  
        // Zig-Zig (Left Left)  
        if (root->left->key > key)  
        {  
            // First recursively bring the 
            // key as root of left-left  
            root->left->left = Search(root->left->left, key);  
  
            // Do first rotation for root,  
            // second rotation is done after else  
            root = RotateRight(root);  
        }  
        else if (root->left->key < key) // Zig-Zag (Left Right)  
        {  
            // First recursively bring  
            // the key as root of left-right  
            root->left->right = Search(root->left->right, key);  
  
            // Do first rotation for root->left  
            if (root->left->right != NULL)  
                root->left = RotateLeft(root->left);  
        }  
  
        // Do second rotation for root  
        return (root->left == NULL)? root: RotateRight(root);  
    }  
    else // Key lies in right subtree  
    {  
        // Key is not in tree, we are done  
        if (root->right == NULL) return root;  
  
        // Zig-Zag (Right Left)  
        if (root->right->key > key)  
        {  
            // Bring the key as root of right-left  
            root->right->left = Search(root->right->left, key);  
  
            // Do first rotation for root->right  
            if (root->right->left != NULL)  
                root->right = RotateRight(root->right);  
        }  
        else if (root->right->key < key)// Zag-Zag (Right Right)  
        {  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->right->right = Search(root->right->right, key);  
            root = RotateLeft(root);  
        }  
  
        // Do second rotation for root  
        return (root->right == NULL)? root: RotateLeft(root);  
    }  
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
