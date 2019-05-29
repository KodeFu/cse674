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
	_root = NULL;
}


CAVL::~CAVL()
{
}

// Get root node
CAVLNode* CAVL::GetRoot()
{
	return _root;
}

// Set root node
void CAVL::SetRoot(CAVLNode* node)
{
	_root = node;
}


// Get height of tree
int CAVL::Height(CAVLNode *node) 
{ 
	if (node == NULL) {
		return 0;
	}

	return node->height; 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
CAVLNode *CAVL::RotateRight(CAVLNode *y) 
{ 
	CAVLNode *x = y->left; 
	CAVLNode *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = std::max(Height(y->left), Height(y->right)) + 1; 
	x->height = std::max(Height(x->left), Height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
CAVLNode *CAVL::RotateLeft(CAVLNode *x) 
{ 
	CAVLNode *y = x->right; 
	CAVLNode *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = std::max(Height(x->left), Height(x->right)) + 1; 
	y->height = std::max(Height(y->left), Height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int CAVL::getBalance(CAVLNode *node) 
{ 
	if (node == NULL) {
		return 0;
	}

	return Height(node->left) - Height(node->right); 
} 

// Insert a new node 
CAVLNode* CAVL::Insert(CAVLNode* node, int key) 
{ 
	// Create and return new node
	if (node == NULL) {
		CAVLNode *newNode = new CAVLNode();
		newNode->key = key; 
		newNode->left = NULL; 
		newNode->right = NULL; 
		newNode->height = 1;

		return(newNode);
	}

	if (key < node->key) {
		// Go down left tree
		node->left = Insert(node->left, key);
	}
	else if (key > node->key) {
		// Go down right tree
		node->right = Insert(node->right, key);
	}
	else {
		return node;
	}

	/* 2. Update height of this ancestor node */
	node->height = 1 + std::max(Height(node->left), Height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return RotateRight(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return RotateLeft(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = RotateLeft(node->left); 
		return RotateRight(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = RotateRight(node->right); 
		return RotateLeft(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Get minimum value of a tree (subtree)
CAVLNode *CAVL::SmallestNode(CAVLNode* node)
{ 
    CAVLNode* current = node; 
  
	while (current && current->left != NULL) {
		current = current->left;
	}
  
    return current; 
} 

// Remove a node
CAVLNode* CAVL::Remove(CAVLNode* node, int key)
{

	// base case
	if (node == NULL) {
		return node;
	}

	if (key < node->key) {
		// Key in left subtree
		node->left = Remove(node->left, key);
	} 
	else if (key > node->key) {
		// Key in right subtree
		node->right = Remove(node->right, key);
	}
    else
    {
		// Key is this node; Three cases.

        // Case 1: left child/subtree empty
        if (node->left == NULL) 
        { 
            CAVLNode *temp = node->right; 
            free(node); 
            return temp; 
        } 
		// Case 2: right child/subtree empty
        else if (node->right == NULL) 
        { 
            CAVLNode *temp = node->left; 
            free(node); 
            return temp; 
        } 
  
        // Case 3: both children/subtrees exist
        CAVLNode* temp = SmallestNode(node->right); 
  
        // Make smallest key into the root node's key
        node->key = temp->key; 
  
        // Delete the smallest key from the right subtree (since
		// we added that to the root node
        node->right = Remove(node->right, temp->key);  
    }  
  
    // If the tree had only one node 
    // then return  
    if (node == NULL)  
		return node;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    node->height = 1 + std::max(Height(node->left), Height(node->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(node->left) >= 0)  
        return RotateRight(node);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(node->left) < 0)  
    {  
        node->left = RotateLeft(node->left);  
        return RotateRight(node);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(node->right) <= 0)  
        return RotateLeft(node);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(node->right) > 0)  
    {  
        node->right = RotateRight(node->right);  
        return RotateLeft(node);  
    }  
  
    return node;  
}  

// Inorder traversal 
void CAVL::Display(CAVLNode *node)
{ 
	if(node != NULL) 
	{ 
		Display(node->left); 
		std::cout << node->key << " ";
		Display(node->right); 
	} 
} 

// Remove all nodes (postorder)
void CAVL::RemoveAll(CAVLNode* node)
{
	if (node != NULL) 
    { 
        RemoveAll(node->left); 
        RemoveAll(node->right); 
		free(node);
		node = NULL;
    }
}
