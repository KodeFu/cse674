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
	int getBalance(CAVLNode *node);
	CAVLNode* insert(CAVLNode* node, int key);
	CAVLNode* remove(CAVLNode* node, int key);
	CAVLNode * minValueNode(CAVLNode* node);
	void inorder(CAVLNode *node);

	void removeAll(CAVLNode* node);
	CAVLNode* getRoot();
	void   setRoot(CAVLNode* node);

private:
	CAVLNode *_root;
};

