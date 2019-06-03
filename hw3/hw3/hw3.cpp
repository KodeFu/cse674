/*

	File:
		hw3.cpp

	Purpose:
		Defines the main entry point to the hw3 application.

	Author:
		mpvats@syr.edu

*/
#include "stdafx.h"
#include "BST.h"
#include "DSW.h"
#include "AVL.h"
#include "Splay.h"
#include "PrintTree.h"

int g_S1[100];	// Stores sequence S1: sequence of numbers from 1..100
int g_S2[100];  // Stores sequence S2: pseudo-random sequence of distinct numbers of length 100

void GenerateS1();                      // Generate S1 data set; ordered 1..100
void GenerateS2(unsigned int seed = 0);   // Generate S2 data set; random range 1..100

int main()
{
	// Generate S1 and S2 data sets
	GenerateS1();
	GenerateS2(55); // seeding 55 just for repeatability
//#if 0
	////////////////////////////////////////////////////////////
	// BST
	////////////////////////////////////////////////////////////
	std::cout << "===== BST =====" << std::endl;
	CBST* bst = new CBST();

	// Use random data
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);
	}

	// Print tree
	bst->Display(bst->_root);
	std::cout << std::endl;
	//CPrintTree::printBT(bst->GetRoot());
	//std::cout << std::endl;

	std::cout << "height: " << bst->Height(bst->_root) << std::endl;

	// Remove
	bst->Remove(bst->_root, 50);

	// Print tree
	bst->Display(bst->_root);
	std::cout << std::endl;
	//CPrintTree::printBT(bst->GetRoot());
	//std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	////////////////////////////////////////////////////////////
	// DSW
	////////////////////////////////////////////////////////////
	std::cout << "===== DSW =====" << std::endl;
	CDSW* dsw = new CDSW();

	// Use random data
	for (int i = 0; i < 100; i++) {
		dsw->Insert(dsw->_root, g_S2[i]);
	}

	// Print tree
	dsw->Display(dsw->GetRoot());
	std::cout << std::endl;
	//CPrintTree::printBT(dsw->GetRoot());
	//std::cout << std::endl;

	// Remove
	dsw->Remove(dsw->_root, 50);

	std::cout << "height: " << dsw->Height(dsw->_root) << std::endl;

	// Balance tree using DSW algorithm
	dsw->BalanceTree(dsw->_root);

	std::cout << "height: " << dsw->Height(dsw->_root) << std::endl;

	// Print Tree
	dsw->Display(dsw->_root);
	std::cout << std::endl;
	//CPrintTree::printBT(dsw->_root);
	//std::cout << std::endl;

	dsw->RemoveAll(dsw->_root);
	delete dsw;

	////////////////////////////////////////////////////////////
	// AVL
	////////////////////////////////////////////////////////////
	std::cout << "===== AVL =====" << std::endl;
	CAVL* avl = new CAVL();

	// Use random data
	for (int i = 0; i < 100; i++) {
		avl->Insert(avl->_root, g_S2[i]);
	}

	//CPrintTree::printBT(avl->_root);
	//std::cout << std::endl;
	avl->Display(avl->_root);
	std::cout << std::endl;

	avl->Remove(avl->_root, 50);

	std::cout << "height: " << avl->Height(avl->GetRoot()) << std::endl;

	//CPrintTree::printBT(avl->_root);
	//std::cout << std::endl;
	avl->Display(avl->_root);
	std::cout << std::endl;

	avl->RemoveAll(avl->_root);

	delete avl;
	
	////////////////////////////////////////////////////////////
	// Splay
	////////////////////////////////////////////////////////////
//#endif
	std::cout << "===== SPLAY =====" << std::endl;
	CSplay* splay = new CSplay();

	// Use random data
	for (int i = 0; i < 100; i++) {
		std::cout << "inserting: " << g_S2[i] << std::endl;
		splay->Insert(splay->_root, g_S2[i]);
		CPrintTree::printBT(splay->_root);
		std::cout << std::endl;
	}

	splay->Display(splay->GetRoot());
	std::cout << std::endl;

	//splay->Search(splay->_root, 28);
	splay->SetRoot(splay->SplaySearch(splay->_root, 50));
	splay->Remove(splay->_root, 50);

	std::cout << "height: " << splay->Height(splay->_root) << std::endl;

	splay->Display(splay->_root);
	std::cout << std::endl;

	splay->RemoveAll(splay->_root);
	delete splay;

	return 0;
}

//
// Generates sequence S1 and stores it in g_S1.
//
// This is a sequence of numbers from 1..100.
//
void GenerateS1()
{
	// zero the memory
	memset(g_S1, 0, sizeof(g_S1));

	// each element is 1 to 100
	for (int i = 0; i < 100; i++)
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
void GenerateS2(unsigned int seed)
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