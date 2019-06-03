/*

	File:
		AVL.cpp

	Purpose:
		Defines the functions which implement a AVL Tree.

	Author:
		mpvats@syr.edu

*/
#include "stdafx.h"
#include "AVL.h"


CAVL::CAVL()
{

}


CAVL::~CAVL()
{
}

// Get height of tree
int CAVL::Height(CNode *node)
{
	if (node == NULL) 
	{
		return 0;
	}

	return node->height;
}

// Get Balance factor of node N 
int CAVL::GetBalanceFactor(CNode *node)
{
	if (node == NULL) 
	{
		return 0;
	}

	return Height(node->right) - Height(node->left) ;
}

// Rebalance
void CAVL::Rebalance(CNode*& node, int key)
{
	// Bail out if node is null
	if (node == NULL)
	{
		return;
	}

	// Update node height
	node->height = std::max(Height(node->left), Height(node->right)) + 1;

	// Get the balance factor
	int balance = GetBalanceFactor(node);

	// Left subtree
	if (balance < -1)
	{	
		if (key < node->left->key)
		{
			// Left Left Case 
			node = RotateRight(node, true);
		}
		else
		{
			// Left Right Case
			node->left = RotateLeft(node->left, true);
			node = RotateRight(node, true);
		}
	}
	// Right subtree
	else if (balance > 1)
	{
		if (key > node->right->key)
		{
			// Right Right Case 
			node = RotateLeft(node, true);
		}
		else
		{
			// Right Left Case 
			node->right = RotateRight(node->right, true);
			node = RotateLeft(node, true);
		}
	}
}

// Insert a new node 
void CAVL::Insert(CNode*& node, int key)
{
	// Call the base class
	CBST::Insert(node, key);

	// Rebalance subtree
	Rebalance(node, key);
}

// Remove a node
void CAVL::Remove(CNode*& node, int key)
{
	// Call the base class
	CBST::Remove(node, key);

	// Rebalance subtree
	Rebalance(node, key);
}

