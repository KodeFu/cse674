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
int CAVL::getBalance(CAVLNode *N) 
{ 
	if (N == NULL) 
		return 0; 
	return getHeight(N->left) - getHeight(N->right); 
} 

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
CAVLNode* CAVL::insert(CAVLNode* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
	{
		CAVLNode *temp = new CAVLNode();
		temp->key = key; 
		temp->left = NULL; 
		temp->right = NULL; 
		temp->height = 1;
		return(temp);
	}

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + std::max(getHeight(node->left), 
						getHeight(node->right)); 

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
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

// Recursive function to delete a node  
// with given key from subtree with  
// given root. It returns root of the  
// modified subtree.  
CAVLNode* CAVL::deleteNode(CAVLNode* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            CAVLNode *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            CAVLNode* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + std::max(getHeight(root->left),  
                           getHeight(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
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