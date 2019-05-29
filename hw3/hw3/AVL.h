#pragma once
#include "AVLNode.h"

class CAVL
{
public:
	CAVL();
	~CAVL();

	int getHeight(CAVLNode *N);

	CAVLNode *rightRotate(CAVLNode *y);
	CAVLNode *leftRotate(CAVLNode *x);
	int getBalance(CAVLNode *N);
	CAVLNode* insert(CAVLNode* node, int key);
	CAVLNode* deleteNode(CAVLNode* root, int key);
	CAVLNode * minValueNode(CAVLNode* node);
	void inorder(CAVLNode *node);

	void removeAll(CAVLNode* node);
	CAVLNode* getRoot();
	void   setRoot(CAVLNode* node);

private:
	CAVLNode *_root;
};

