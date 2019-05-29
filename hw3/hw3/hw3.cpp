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

void GenerateS1();                    // Generate S1 data set; ordered 1..100
void GenerateS2(unsigned int seed);   // Generate S2 data set; random range 1..100

int main()
{
	// Generate S1 and S2 data sets
	GenerateS1();
	GenerateS2(55); // seeding 55 just for repeatability

	////////////////////////////////////////////////////////////
	// BST
	////////////////////////////////////////////////////////////
	std::cout << "===== BST =====" << std::endl;
	CBST* bst = new CBST();

	// Use random data
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->GetRoot(), g_S2[i]);
	}

	// Print tree
	bst->Display(bst->GetRoot());
	std::cout << std::endl;
	//CPrintTree::printBT(bst->GetRoot());
	//std::cout << std::endl;

	std::cout << "height: " << bst->Height(bst->GetRoot()) << std::endl;
	
	// Remove
	bst->Remove(bst->GetRoot(), 50);

	// Print tree
	bst->Display(bst->GetRoot());
	std::cout << std::endl;
	//CPrintTree::printBT(bst->GetRoot());
	//std::cout << std::endl;

	bst->RemoveAll(bst->GetRoot());
	delete bst;

	////////////////////////////////////////////////////////////
	// DSW
	////////////////////////////////////////////////////////////
	std::cout << "===== DSW =====" << std::endl;
	CDSW* dsw = new CDSW();

	// Use random data
	for (int i = 0; i < 100; i++) {
		dsw->Insert(dsw->GetRoot(), g_S2[i]);
	}

	// Print tree
	dsw->Display(dsw->GetRoot());
	std::cout << std::endl;
	//CPrintTree::printBT(dsw->GetRoot());
	//std::cout << std::endl;

	// Remove
	dsw->Remove(dsw->GetRoot(), 50);

	std::cout << "height: " << dsw->Height(dsw->GetRoot()) << std::endl;

	// Create the tree
	dsw->CreatePerfectTree();

	// Print Tree
	dsw->Display(dsw->GetRoot());
	std::cout << std::endl;
	//CPrintTree::printBT(dsw->GetRoot());
	//std::cout << std::endl;

	dsw->RemoveAll(dsw->GetRoot());
	delete dsw;

	////////////////////////////////////////////////////////////
	// AVL
	////////////////////////////////////////////////////////////
	std::cout << "===== AVL =====" << std::endl;
	CAVL* avl = new CAVL();

	// Use random data
	for (int i = 0; i < 100; i++) {
		avl->SetRoot(avl->Insert(avl->GetRoot(), g_S2[i])); 
	}

	//CPrintTree::printAVL(avl->getRoot());
	//std::cout << std::endl;
	avl->Display(avl->GetRoot()); 
	std::cout << std::endl;

	avl->Remove(avl->GetRoot(), 50);

	std::cout << "height: " << avl->Height(avl->GetRoot()) << std::endl;

	//CPrintTree::printAVL(avl->getRoot());
	//std::cout << std::endl;
	avl->Display(avl->GetRoot()); 
	std::cout << std::endl;

	avl->RemoveAll(avl->GetRoot());

	delete avl;

	////////////////////////////////////////////////////////////
	// Splay
	////////////////////////////////////////////////////////////
	std::cout << "===== SPLAY =====" << std::endl;
	CSplay* splay = new CSplay();

	// Use random data
	for (int i = 0; i < 100; i++) {
		splay->SetRoot(splay->Insert(splay->GetRoot(), g_S2[i])); 
	}

    splay->Display(splay->GetRoot());
	std::cout << std::endl;

	splay->SetRoot(splay->Remove(splay->GetRoot(), 50));

	std::cout << "height: " << splay->Height(splay->GetRoot()) << std::endl;

	splay->Display(splay->GetRoot());
	std::cout << std::endl;

	splay->RemoveAll(splay->GetRoot());
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
void GenerateS2(unsigned int seed=0)
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