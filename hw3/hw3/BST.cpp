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

CNode* CBST::getRoot()
{
	return _root;
}

// Inorder traversal
void CBST::inorder(CNode* node) 
{ 
    if (node != NULL) 
    { 
        inorder(node->left); 
		std::cout << node->key << " ";
        inorder(node->right); 
    } 
} 
   
// Insert a new node
CNode* CBST::insert(CNode* node, int key) 
{ 
    // Create and return new node
	if (node == NULL) {
		CNode* newNode = new CNode();
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;

		if (_root == NULL) {
			_root = newNode;
		}
		return newNode;
	}
	
	if (key < node->key) {
		// Go down left tree
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		// Go down right tree
		node->right = insert(node->right, key);
	}
  
    return node; 
} 

// Get minimum value of a tree (subtree)
CNode *CBST::minValueNode(CNode* node)
{ 
    CNode* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

// Remove a node
CNode* CBST::remove(CNode* node, int key) 
{ 
    // base case 
	if (node == NULL) {
		return node;
	}
  
	if (key < node->key) {
		// Key in left subtree
		node->left = remove(node->left, key);
	}
	else if (key > node->key) {
		// Key in right subtree
		node->right = remove(node->right, key);
	}
    else  { 
		// Key is this node; Three cases.

        // Case 1: left child/subtree empty
        if (node->left == NULL) 
        { 
            CNode *temp = node->right; 
            free(node); 
            return temp; 
        } 
		// Case 2: right child/subtree empty
        else if (node->right == NULL) 
        { 
            CNode *temp = node->left; 
            free(node); 
            return temp; 
        } 
  
        // Case 3: both children/subtrees exist
        CNode* temp = minValueNode(node->right); 
  
        // Make smallest key into the root node's key
        node->key = temp->key; 
  
        // Delete the smallest key from the right subtree (since
		// we added that to the root node
        node->right = remove(node->right, temp->key); 
    } 

    return node; 
}

