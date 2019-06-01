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
	if (node == NULL) {
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
	if (node == NULL) {
		return 0;
	}

	return Height(node->left) - Height(node->right); 
} 

// Insert a new node 
void CAVL::Insert(CNode*& node, int key) 
{ 
	// Call the base class
	CBST::Insert(node, key);

	/* 2. Update height of this ancestor node */
	node->height = 1 + std::max(Height(node->left), Height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = GetBalanceFactor(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		node = RotateRight(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		node = RotateLeft(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = RotateLeft(node->left); 
		node = RotateRight(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = RotateRight(node->right); 
		node = RotateLeft(node); 
	} 
} 

// Remove a node
void CAVL::Remove(CNode*& node, int key)
{
	// Call the base class
	CBST::Remove(node, key);
  
    // If the tree had only one node 
    // then return  
    if (node == NULL)  
		return;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    node->height = 1 + std::max(Height(node->left), Height(node->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = GetBalanceFactor(node);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
	if (balance > 1 &&
		GetBalanceFactor(node->left) >= 0) {
		RotateRight(node);
		return;
	}
  
    // Left Right Case  
    if (balance > 1 &&  
        GetBalanceFactor(node->left) < 0)  
    {  
        node->left = RotateLeft(node->left);  
        node = RotateRight(node); 
		return;
    }  
  
    // Right Right Case  
	if (balance < -1 &&
		GetBalanceFactor(node->right) <= 0) {
		node = RotateLeft(node);
		return;
	}
  
    // Right Left Case  
    if (balance < -1 &&  
        GetBalanceFactor(node->right) > 0)  
    {  
        node->right = RotateRight(node->right);  
        node = RotateLeft(node);  
		return;
    }  

}  

