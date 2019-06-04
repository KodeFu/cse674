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
int g_S3[] = {  // Stores sequence S3: this is S1 arranged in Binary Search Fashion order
	50, 25, 12,  6,  3,  1,  2,  4,  5,  9,  7,  8, 10, 11, 18, 15, 13, 14, 16, 17,
	21, 19, 20, 23, 22, 24, 37, 31, 28, 26, 27, 29, 30, 34, 32, 33, 35, 36, 43, 40,
	38, 39, 41, 42, 46, 44, 45, 48, 47, 49, 75, 62, 56, 53, 51, 52, 54, 55, 59, 57,
	58, 60, 61, 68, 65, 63, 64, 66, 67, 71, 69, 70, 73, 72, 74, 87, 81, 78, 76, 77,
	79, 80, 84, 82, 83, 85, 86, 93, 90, 88, 89, 91, 92, 96, 94, 95, 98, 97, 99, 100
};

void GenerateS1();                       // Generate S1 data set; ordered 1..100
void GenerateS2(unsigned int seed = 0);  // Generate S2 data set; random range 1..100

void Task1()
{
	std::cout << "=================================" << std::endl;
	std::cout << "========== Task 1: BST ==========" << std::endl;
	std::cout << "=================================" << std::endl;

	std::cout << "===== BST sub-task 1 =====" << std::endl;
	CBST* bst = new CBST();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S1[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;\
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== BST sub-task 2 =====" << std::endl;
	bst = new CBST();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;\
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== BST sub-task 3 =====" << std::endl;
	bst = new CBST();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S3[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i + 1) % 10 == 0)
		{
			std::cout << "tree height: " << bst->Height(bst->_root) << std::endl; \
				CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;
}

void Task2()
{
	std::cout << "=================================" << std::endl;
	std::cout << "========== Task 2: DSW ==========" << std::endl;
	std::cout << "=================================" << std::endl;

	std::cout << "===== DSW sub-task 1 =====" << std::endl;
	CDSW* bst = new CDSW();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S1[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;

			bst->BalanceTree(bst->_root);

			std::cout << "tree height (after): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== DSW sub-task 2 =====" << std::endl;
	bst = new CDSW();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;

			bst->BalanceTree(bst->_root);

			std::cout << "tree height (after): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== DSW sub-task 3 =====" << std::endl;
	bst = new CDSW();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S3[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i + 1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;

			bst->BalanceTree(bst->_root);

			std::cout << "tree height (after): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;
}

void Task3()
{
	std::cout << "=================================" << std::endl;
	std::cout << "========== Task 3: AVL ==========" << std::endl;
	std::cout << "=================================" << std::endl;

	std::cout << "===== AVL sub-task 1 =====" << std::endl;
	CAVL* bst = new CAVL();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S1[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== AVL sub-task 2 =====" << std::endl;
	bst = new CAVL();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== AVL sub-task 3 =====" << std::endl;
	bst = new CAVL();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i + 1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Delete the 50 from tree and print the height of the tree and the tree structure.
	std::cout << "deleting 50" << std::endl;
	bst->Remove(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;
}

void Task4()
{
	std::cout << "===================================" << std::endl;
	std::cout << "========== Task 4: SPLAY ==========" << std::endl;
	std::cout << "===================================" << std::endl;

	std::cout << "===== Splay sub-task 1 =====" << std::endl;
	CSplay* bst = new CSplay();

	// Insert every element of S1 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S1[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Search 50 in tree and print the height of the tree and the tree structure.
	std::cout << "searching 50" << std::endl;
	bst->Search(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== Splay sub-task 2 =====" << std::endl;
	bst = new CSplay();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S2[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i+1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Search 50 in tree and print the height of the tree and the tree structure.
	std::cout << "searching 50" << std::endl;
	bst->Search(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;

	std::cout << "===== Splay sub-task 3 =====" << std::endl;
	bst = new CSplay();
	// Insert every element of S2 into the BST. 
	for (int i = 0; i < 100; i++) {
		bst->Insert(bst->_root, g_S3[i]);

		// Print the height of the tree and the tree structure after every 10 insertions.
		if ((i + 1) % 10 == 0)
		{
			std::cout << "tree height (before): " << bst->Height(bst->_root) << std::endl;
			CPrintTree::printBT(bst->_root);
			std::cout << std::endl;
			bst->Display(bst->_root);
			std::cout << std::endl;
		}
	}

	// Search 50 in tree and print the height of the tree and the tree structure.
	std::cout << "searching 50" << std::endl;
	bst->Search(bst->_root, 50);
	std::cout << "tree height: " << bst->Height(bst->_root) << std::endl;
	CPrintTree::printBT(bst->_root);
	std::cout << std::endl;
	bst->Display(bst->_root);
	std::cout << std::endl;

	bst->RemoveAll(bst->_root);
	delete bst;
}

int main()
{
	// Generate S1 and S2 data sets
	GenerateS1();
	GenerateS2(55); // seeding 55 just for repeatability

	////////////////////////////////////////////////////////////
	// BST
	////////////////////////////////////////////////////////////
	Task1();

	////////////////////////////////////////////////////////////
	// DSW
	////////////////////////////////////////////////////////////
	Task2();

	////////////////////////////////////////////////////////////
	// AVL
	////////////////////////////////////////////////////////////
	Task3();

	////////////////////////////////////////////////////////////
	// Splay
	////////////////////////////////////////////////////////////
	Task4();

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