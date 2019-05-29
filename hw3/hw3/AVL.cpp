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
CAVLNode* CAVL::getRoot()
{
	return _root;
}

// Set root node
void CAVL::setRoot(CAVLNode* node)
{
	_root = node;
}


// Get height of tree
int CAVL::getHeight(CAVLNode *node) 
{ 
	if (node == NULL) {
		return 0;
	}

	return node->height; 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
CAVLNode *CAVL::rightRotate(CAVLNode *y) 
{ 
	CAVLNode *x = y->left; 
	CAVLNode *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = std::max(getHeight(y->left), 
					getHeight(y->right)) + 1; 
	x->height = std::max(getHeight(x->left), 
					getHeight(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
CAVLNode *CAVL::leftRotate(CAVLNode *x) 
{ 
	CAVLNode *y = x->right; 
	CAVLNode *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = std::max(getHeight(x->left),	 
					getHeight(x->right)) + 1; 
	y->height = std::max(getHeight(y->left), 
					getHeight(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int CAVL::getBalance(CAVLNode *node) 
{ 
	if (node == NULL) {
		return 0;
	}

	return getHeight(node->left) - getHeight(node->right); 
} 

// Insert a new node 
CAVLNode* CAVL::insert(CAVLNode* node, int key) 
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
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		// Go down right tree
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	/* 2. Update height of this ancestor node */
	node->height = 1 + std::max(getHeight(node->left), getHeight(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Get minimum value of a tree (subtree)
CAVLNode *CAVL::minValueNode(CAVLNode* node)
{ 
    CAVLNode* current = node; 
  
	while (current && current->left != NULL) {
		current = current->left;
	}
  
    return current; 
} 

// Remove a node
CAVLNode* CAVL::remove(CAVLNode* node, int key)
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
        CAVLNode* temp = minValueNode(node->right); 
  
        // Make smallest key into the root node's key
        node->key = temp->key; 
  
        // Delete the smallest key from the right subtree (since
		// we added that to the root node
        node->right = remove(node->right, temp->key);  
    }  
  
    // If the tree had only one node 
    // then return  
    if (node == NULL)  
		return node;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    node->height = 1 + std::max(getHeight(node->left),  
                           getHeight(node->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(node->left) >= 0)  
        return rightRotate(node);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(node->left) < 0)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(node->right) <= 0)  
        return leftRotate(node);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(node->right) > 0)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  

// Inorder traversal 
void CAVL::inorder(CAVLNode *node)
{ 
	if(node != NULL) 
	{ 
		inorder(node->left); 
		std::cout << node->key << " ";
		inorder(node->right); 
	} 
} 

// Remove all nodes (postorder)
void CAVL::removeAll(CAVLNode* node)
{
	if (node != NULL) 
    { 
        removeAll(node->left); 
        removeAll(node->right); 
		free(node);
		node = NULL;
    }
}