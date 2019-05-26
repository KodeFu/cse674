#include "stdafx.h"
#include "BST.h"


CBST::CBST()
{
	root = NULL;
}


CBST::~CBST()
{
}

CNode* CBST::getRoot()
{
	return root;
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

		if (root == NULL) {
			root = newNode;
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

