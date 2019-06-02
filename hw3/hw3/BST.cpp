/*

	File:
		BST.cpp

	Purpose:
		Defines the functions which implement a BST.

	Author:
		mpvats@syr.edu

*/
#include "stdafx.h"
#include "BST.h"


CBST::CBST()
{
	_root = NULL;
}


CBST::~CBST()
{
}

CNode* CBST::GetRoot()
{
	return _root;
}

void CBST::SetRoot(CNode* node)
{
	_root = node;
}

// Display nodes via inorder traversal
void CBST::Display(CNode* node)
{
	if (node != NULL)
	{
		Display(node->left);
		std::cout << node->key << " ";
		Display(node->right);
	}
}

// Remove all nodes (postorder)
void CBST::RemoveAll(CNode* node)
{
	if (node != NULL)
	{
		RemoveAll(node->left);
		RemoveAll(node->right);
		free(node);
		node = NULL;
	}
}

// BST height
int CBST::Height(CNode *node)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (node == NULL) 
	{
		return 0;
	}

	leftHeight = Height(node->left);
	rightHeight = Height(node->right);

	if (leftHeight > rightHeight) 
	{
		return leftHeight + 1;
	}
	else 
	{
		return rightHeight + 1;
	}
}

// Insert a new node
void CBST::Insert(CNode*& node, int key)
{
	// Create and return new node
	if (node == NULL) 
	{
		CNode* newNode = new CNode();
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;

		// Set current node to new node
		node = newNode;

		// Assign root if root doesn't exist
		if (_root == NULL) 
		{
			_root = newNode;
		}
	}

	if (key < node->key) 
	{
		// Go down left tree
		Insert(node->left, key);
	}
	else if (key > node->key) 
	{
		// Go down right tree
		Insert(node->right, key);
	}
	else 
	{
		// Equal keys, don't insert
	}

}

// Get minimum value of a tree (subtree)
CNode *CBST::SmallestNode(CNode* node)
{
	CNode* current = node;

	// Get the leftest left node which is the smallest in a BST
	while (current && current->left != NULL) 
	{
		current = current->left;
	}

	return current;
}

// Remove a node
void CBST::Remove(CNode*& node, int key)
{
	// Bail out if node is NULL
	if (node == NULL) 
	{
		return;
	}

	if (key < node->key) 
	{
		// Key in left subtree
		Remove(node->left, key);
	}
	else if (key > node->key) 
	{
		// Key in right subtree
		Remove(node->right, key);
	}
	else {
		// Key is this node; Three cases.
		if (node->left == NULL)
		{
			// Case 1: left child/subtree empty
			CNode *temp = node->right;
			delete node;
			node = temp;
		}
		else if (node->right == NULL) 
		{
			// Case 2: right child/subtree empty
			CNode *temp = node->left;
			delete node;
			node = temp;
			return;
		}
		else 
		{
			// Case 3: both children/subtrees exist
			CNode* temp = SmallestNode(node->right);

			// Make smallest key into the root node's key
			node->key = temp->key;

			// Delete the smallest key from the right subtree (since
			// we added that to the root node
			Remove(node->right, temp->key);
		}
	}

}

