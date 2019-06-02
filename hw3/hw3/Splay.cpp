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

/* Helper function that allocates
a new node with the given key and
	NULL left and right pointers. */
CNode* CSplay::newNode(int key)
{
	CNode* Node = new CNode();
	Node->key = key;
	Node->left = Node->right = NULL;
	return (Node);
}

// This function brings the key at  
// root if key is present in tree.  
// If key is not present, then it  
// brings the last accessed item at  
// root. This function modifies the  
// tree and returns the new root  
CNode *CSplay::Splay(CNode *node, int key)
{
	// Base cases: root is NULL or  
	// key is present at root  
	if (node == NULL || node->key == key)
		return node;

	// Key lies in left subtree  
	if (node->key > key)
	{
		// Key is not in tree, we are done  
		if (node->left == NULL) return node;

		// Zig-Zig (Left Left)  
		if (node->left->key > key)
		{
			// First recursively bring the 
			// key as root of left-left  
			node->left->left = Splay(node->left->left, key);

			// Do first rotation for root,  
			// second rotation is done after else  
			node = RotateRight(node);
		}
		else if (node->left->key < key) // Zig-Zag (Left Right)  
		{
			// First recursively bring  
			// the key as root of left-right  
			node->left->right = Splay(node->left->right, key);

			// Do first rotation for root->left  
			if (node->left->right != NULL)
				node->left = RotateLeft(node->left);
		}

		// Do second rotation for root  
		return (node->left == NULL) ? node : RotateRight(node);
	}
	else // Key lies in right subtree  
	{
		// Key is not in tree, we are done  
		if (node->right == NULL) return node;

		// Zig-Zag (Right Left)  
		if (node->right->key > key)
		{
			// Bring the key as root of right-left  
			node->right->left = Splay(node->right->left, key);

			// Do first rotation for root->right  
			if (node->right->left != NULL)
				node->right = RotateRight(node->right);
		}
		else if (node->right->key < key)// Zag-Zag (Right Right)  
		{
			// Bring the key as root of  
			// right-right and do first rotation  
			node->right->right = Splay(node->right->right, key);
			node = RotateLeft(node);
		}

		// Do second rotation for root  
		return (node->right == NULL) ? node : RotateLeft(node);
	}
}

// Function to insert a new key k  
// in splay tree with given root  
CNode *CSplay::Insert(CNode *node, int key)
{
	// Simple Case: If tree is empty  
	if (node == NULL) return newNode(key);

	// Bring the closest leaf node to root  
	node = Splay(node, key);

	// If key is already present, then return  
	if (node->key == key) return node;

	// Otherwise allocate memory for new node  
	CNode *newnode = newNode(key);

	// If root's key is greater, make  
	// root as right child of newnode  
	// and copy the left child of root to newnode  
	if (node->key > key)
	{
		newnode->right = node;
		newnode->left = node->left;
		node->left = NULL;
	}

	// If root's key is smaller, make  
	// root as left child of newnode  
	// and copy the right child of root to newnode  
	else
	{
		newnode->left = node;
		newnode->right = node->right;
		node->right = NULL;
	}

	return newnode; // newnode becomes new root  
}

// The delete function for Splay tree. Note that this function 
// returns the new root of Splay Tree after removing the key  
CNode* CSplay::Remove(CNode* root, int key)
{
	CNode *temp;
	if (!root)
		return NULL;

	// Splay the given key     
	root = Splay(root, key);

	// If key is not present, then 
	// return root 
	if (key != root->key)
		return root;

	// If key is present 
	// If left child of root does not exist 
	// make root->right as root    
	if (!root->left)
	{
		temp = root;
		root = root->right;
	}

	// Else if left child exits 
	else
	{
		temp = root;

		/*Note: Since key == root->key,
		so after Splay(key, root->lchild),
		the tree we get will have no right child tree
		and maximum node in left subtree will get splayed*/
		// New root 
		root = Splay(root->left, key);

		// Make right child of previous root  as 
		// new root's right child 
		root->right = temp->right;
	}

	// free the previous root node, that is, 
	// the node containing the key 
	free(temp);

	// return root of the new Splay Tree 
	return root;

}

// BST height
int CSplay::Height(CNode *node)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (node == NULL) {
		return 0;
	}

	leftHeight = Height(node->left);
	rightHeight = Height(node->right);

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
}