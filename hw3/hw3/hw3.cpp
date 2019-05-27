// hw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include "DSW.h"
#include "AVL.h"
#include "PrintTree.h"

int g_S1[100];	// Stores sequence S1: sequence of numbers from 1..100
int g_S2[100];  // Stores sequence S2: pseudo-random sequence of distinct numbers of length 100

//
// Generates sequence S1 and stores it in g_S1.
//
// This is a sequence of numbers from 1..100.
//
void generateS1()
{
	// zero the memory
	memset(g_S1, 0, sizeof(g_S1));

	// each element is 1 to 100
	for (int i=0; i < 100; i++)
	{
		g_S1[i] = i + 1;
	}
}

//
// Generates sequence S2 and stores it in g_S2.
//
// This is a sequence of distinct numbers from 1..100. This function will keep
// generating random number until all elments are filled.
//
void generateS2(unsigned int seed=0)
{
	// each element represents whether the value has been
	// stored in the g_S2 array
	bool isInTable[100];

	// initialize arrays
	memset(isInTable, false, sizeof(isInTable));
	memset(g_S2, 0, sizeof(g_S2));

	// generate seed
	(!seed) ? srand((unsigned)time(NULL)) : srand(seed);
	
	for (int i = 0; i < 100; i++)
	{
		// get distinct numbers
		while (true)
		{
			int randomNumber = rand() % 100;

			// only add the random number to g_S2 if it's not already added. 
			// if it was added already, generate another number.
			if (!isInTable[randomNumber])
			{
				isInTable[randomNumber] = true;
				g_S2[i] = randomNumber + 1;
				break;
			}
		}
	}
}

int main()
{
	std::cout << "hello hw3" << std::endl;

	generateS1();
	generateS2(55);
#if 0
	// Create tree
	//CBST* bst = new CBST();
	CDSW* bst = new CDSW();

	bst->insert(bst->getRoot(), 50);
	bst->insert(bst->getRoot(), 30);
	bst->insert(bst->getRoot(), 20);
	bst->insert(bst->getRoot(), 40);
	bst->insert(bst->getRoot(), 70);
	bst->insert(bst->getRoot(), 60);
	bst->insert(bst->getRoot(), 80);

	// Use random data
	for (int i = 0; i < 100; i++) {
		bst->insert(bst->getRoot(), g_S2[i]);
	}

	// Print tree
	bst->inorder(bst->getRoot());
	std::cout << std::endl;
	CPrintTree::printBT(bst->getRoot());
	std::cout << std::endl;

	bst->createPerfectTree();

	std::cout << std::endl;
	CPrintTree::printBT(bst->getRoot());
	std::cout << std::endl;

	std::cout << "height: " << bst->getHeight(bst->getRoot()) << std::endl;
	/*
	// Remove
	bst->remove(bst->getRoot(), 50);

	// Print tree
	bst->inorder(bst->getRoot());
	std::cout << std::endl;
	CPrintTree::printBT(bst->getRoot());
	std::cout << std::endl;
	*/
	bst->removeAll(bst->getRoot());
	delete bst;
#endif

	CAVL* avl = new CAVL();
	
	/* Constructing tree given in 
	the above figure */
	/*avl->setRoot(avl->insert(avl->getRoot(), 10)); 
	avl->setRoot(avl->insert(avl->getRoot(), 20)); 
	avl->setRoot(avl->insert(avl->getRoot(), 30)); 
	avl->setRoot(avl->insert(avl->getRoot(), 40)); 
	avl->setRoot(avl->insert(avl->getRoot(), 50)); 
	avl->setRoot(avl->insert(avl->getRoot(), 25)); */

	// Use random data
	for (int i = 0; i < 100; i++) {
		avl->setRoot(avl->insert(avl->getRoot(), g_S2[i])); 
	}
	
	/* The constructed AVL Tree would be 
				30 
			/ \ 
			20 40 
			/ \ \ 
		10 25 50 
	*/
	std::cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	avl->inorder(avl->getRoot()); 

	avl->deleteNode(avl->getRoot(), 50);

	avl->inorder(avl->getRoot()); 

    return 0;
}

