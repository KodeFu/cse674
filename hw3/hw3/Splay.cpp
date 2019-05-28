#include "stdafx.h"
#include "Splay.h"


CSplay::CSplay()
{
	_root = NULL;
}


CSplay::~CSplay()
{
}

CNode* CSplay::getRoot()
{
	return _root;
}

void CSplay::setRoot(CNode* node)
{
	_root = node;
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
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
CNode *CSplay::rightRotate(CNode *x)  
{  
    CNode *y = x->left;  
    x->left = y->right;  
    y->right = x;  
    return y;  
}  
  
// A utility function to left 
// rotate subtree rooted with x  
// See the diagram given above.  
CNode *CSplay::leftRotate(CNode *x)  
{  
    CNode *y = x->right;  
    x->right = y->left;  
    y->left = x;  
    return y;  
}  
  
// This function brings the key at  
// root if key is present in tree.  
// If key is not present, then it  
// brings the last accessed item at  
// root. This function modifies the  
// tree and returns the new root  
CNode *CSplay::splay(CNode *root, int key)  
{  
    // Base cases: root is NULL or  
    // key is present at root  
    if (root == NULL || root->key == key)  
        return root;  
  
    // Key lies in left subtree  
    if (root->key > key)  
    {  
        // Key is not in tree, we are done  
        if (root->left == NULL) return root;  
  
        // Zig-Zig (Left Left)  
        if (root->left->key > key)  
        {  
            // First recursively bring the 
            // key as root of left-left  
            root->left->left = splay(root->left->left, key);  
  
            // Do first rotation for root,  
            // second rotation is done after else  
            root = rightRotate(root);  
        }  
        else if (root->left->key < key) // Zig-Zag (Left Right)  
        {  
            // First recursively bring  
            // the key as root of left-right  
            root->left->right = splay(root->left->right, key);  
  
            // Do first rotation for root->left  
            if (root->left->right != NULL)  
                root->left = leftRotate(root->left);  
        }  
  
        // Do second rotation for root  
        return (root->left == NULL)? root: rightRotate(root);  
    }  
    else // Key lies in right subtree  
    {  
        // Key is not in tree, we are done  
        if (root->right == NULL) return root;  
  
        // Zig-Zag (Right Left)  
        if (root->right->key > key)  
        {  
            // Bring the key as root of right-left  
            root->right->left = splay(root->right->left, key);  
  
            // Do first rotation for root->right  
            if (root->right->left != NULL)  
                root->right = rightRotate(root->right);  
        }  
        else if (root->right->key < key)// Zag-Zag (Right Right)  
        {  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->right->right = splay(root->right->right, key);  
            root = leftRotate(root);  
        }  
  
        // Do second rotation for root  
        return (root->right == NULL)? root: leftRotate(root);  
    }  
}  
  
// Function to insert a new key k  
// in splay tree with given root  
CNode *CSplay::insert(CNode *root, int k)  
{  
    // Simple Case: If tree is empty  
    if (root == NULL) return newNode(k);  
  
    // Bring the closest leaf node to root  
    root = splay(root, k);  
  
    // If key is already present, then return  
    if (root->key == k) return root;  
  
    // Otherwise allocate memory for new node  
    CNode *newnode = newNode(k);  
  
    // If root's key is greater, make  
    // root as right child of newnode  
    // and copy the left child of root to newnode  
    if (root->key > k)  
    {  
        newnode->right = root;  
        newnode->left = root->left;  
        root->left = NULL;  
    }  
  
    // If root's key is smaller, make  
    // root as left child of newnode  
    // and copy the right child of root to newnode  
    else
    {  
        newnode->left = root;  
        newnode->right = root->right;  
        root->right = NULL;  
    }  
  
    return newnode; // newnode becomes new root  
}  
  
// The delete function for Splay tree. Note that this function 
// returns the new root of Splay Tree after removing the key  
CNode* CSplay::delete_key(CNode* root, int key) 
{ 
    CNode *temp; 
    if (!root) 
        return NULL; 
      
    // Splay the given key     
    root = splay(root, key); 
      
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
        root = splay(root->left, key); 
          
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

// A utility function to print  
// preorder traversal of the tree.  
// The function also prints height of every node  
void CSplay::preOrder(CNode *root)  
{  
    if (root != NULL)  
    {  
		std::cout << root->key << " ";
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  