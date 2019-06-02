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

// Rotate Right
//  - This follows diagram give in ADs and https://en.wikipedia.org/wiki/Tree_rotation.
//  - In ASCII form below.
//
//     Q              P
//    / \            / \
//   P   C  ---->   A   Q
//  / \                / \
// A   B              B   C
//
CNode *CAVL::RotateRight(CNode *node)
{
	// Assign P, Q, B (left tree in diagram above)
	CNode* Q = node;
	CNode* P = node->left;
	CNode* B = P->right;

	// Rotate right
	P->right = Q;
	Q->left = B;

	// Update heights 
	Q->height = std::max(Height(Q->left), Height(Q->right)) + 1;
	P->height = std::max(Height(P->left), Height(P->right)) + 1;

	// Return new root 
	return P;
}

// Roatate Left
//  - This follows diagram give in ADs and https://en.wikipedia.org/wiki/Tree_rotation.
//  - In ASCII form below.
//
//     Q              P
//    / \            / \
//   P   C  <----   A   Q
//  / \                / \
// A   B              B   C
//
CNode *CAVL::RotateLeft(CNode *node)
{
	// Assign P, Q, B (right tree in diagram above)
	CNode* P = node;
	CNode* Q = P->right;
	CNode* B = Q->left;

	// Rotate left
	Q->left = P;
	P->right = B;

	// Update heights 
	P->height = std::max(Height(P->left), Height(P->right)) + 1;
	Q->height = std::max(Height(Q->left), Height(Q->right)) + 1;

	// Return new root
	return Q;
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

// Insert a new node 
void CAVL::Insert(CNode*& node, int key)
{
	// Call the base class
	CBST::Insert(node, key);

	// Update node height
	node->height = std::max(Height(node->left), Height(node->right)) + 1;

	// Get the balance factor
	int balance = GetBalanceFactor(node);

	//////////////////////////////
	// Rebalance
	//////////////////////////////

	// Left subtree
	if (balance < -1)
	{
		
		if (key < node->left->key)
		{
			// Left Left Case 
			node = RotateRight(node);
		}
		else
		{
			// Left Right Case
			node->left = RotateLeft(node->left);
			node = RotateRight(node);
		}
	}
	// Right subtree
	else if (balance > 1)
	{
		if (key > node->right->key)
		{
			// Right Right Case 
			node = RotateLeft(node);
		}
		else
		{
			// Right Left Case 
			node->right = RotateRight(node->right);
			node = RotateLeft(node);
		}
	}
}

// Remove a node
void CAVL::Remove(CNode*& node, int key)
{
	// Call the base class
	CBST::Remove(node, key);

	// Bail out if node is NULL
	if (node == NULL)
	{
		return;
	}

	// Update node height
	node->height = std::max(Height(node->left), Height(node->right)) + 1;

	// Get the balance factor
	int balance = GetBalanceFactor(node);

	//////////////////////////////
	// Rebalance
	//////////////////////////////

	// Left subtree
	if (balance < -1)
	{
		
		if (key < node->left->key)
		{
			// Left Left Case 
			node = RotateRight(node);
		}
		else
		{
			// Left Right Case
			node->left = RotateLeft(node->left);
			node = RotateRight(node);
		}
	} 
	// Right subtree
	else if (balance > 1)
	{
		
		if (key > node->right->key)
		{
			// Right Right Case 
			node = RotateLeft(node);
		}
		else
		{
			// Right Left Case 
			node->right = RotateRight(node->right);
			node = RotateLeft(node);
		}
	}

}

