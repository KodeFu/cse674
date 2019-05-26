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

/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
CNode *CBST::minValueNode(CNode* node)
{ 
    CNode* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
CNode* CBST::remove(CNode* node, int key) 
{ 
    // base case 
	if (node == NULL) {
		return node;
	}
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
	if (key < node->key) {
		node->left = remove(node->left, key);
	}
	else if (key > node->key) {
		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		node->right = remove(node->right, key);
	}
    else  { 
		// if key is same as root's key, then This is the node 
		// to be deleted 

        // node with only one child or no child 
        if (node->left == NULL) 
        { 
            CNode *temp = node->right; 
            free(node); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            CNode *temp = node->left; 
            free(node); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        CNode* temp = minValueNode(node->right); 
  
        // Copy the inorder successor's content to this node 
        node->key = temp->key; 
  
        // Delete the inorder successor 
        node->right = remove(node->right, temp->key); 
    } 

    return node; 
}

