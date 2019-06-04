========================================================================
    CONSOLE APPLICATION : hw3 Project Overview

	This project performs several sorting methods on random ascending, 
	random	descending, and random data.
========================================================================

/////////////////////////////////////////////////////////////////////////////
SUPER SHORT HOW-TO

- Run by exectuing hw3.exe. No arguments needed. This will run all tasks.
    hw3/Release/hw3.exe

- Output of hw3.exe:
    hw3/Release/Output.txt

- If you rebuild, build in Release mode for the x86 CPU.

/////////////////////////////////////////////////////////////////////////////
FILES

hw3.cpp
 This is the main application source file.

BST.h/.cpp
 Binary Sort Tree definition and implementation.

AVL.h/.cpp
 AVL Tree definition and implementation.

DSW.h/.cpp
 DSW tree rebalanancing definition and implementation.

Node.h/.cpp
 Node class definition and implementation.

Splay.h/.cpp
 Splay Tree definition and implementation.

PrintTree.h/.cpp
 Tree visualization definition and implementation.

/////////////////////////////////////////////////////////////////////////////
EXECUTION

To run the application:
 1. cd Release
 2. hw3.exe

 This will run the hw3.exe program, running through all of the homework task.
 
 The data used as input for this assignment are defined in hw3.cpp. There are three
 data sets: g_S1, g_S2 and g_S3.

int g_S1[100];	// Stores sequence S1: sequence of numbers from 1..100
int g_S2[100];  // Stores sequence S2: pseudo-random sequence of distinct numbers of length 100
int g_S3[] = {  // Stores sequence S3: this is S1 arranged in Binary Search Fashion order
	50, 25, 12,  6,  3,  1,  2,  4,  5,  9,  7,  8, 10, 11, 18, 15, 13, 14, 16, 17,
	21, 19, 20, 23, 22, 24, 37, 31, 28, 26, 27, 29, 30, 34, 32, 33, 35, 36, 43, 40,
	38, 39, 41, 42, 46, 44, 45, 48, 47, 49, 75, 62, 56, 53, 51, 52, 54, 55, 59, 57,
	58, 60, 61, 68, 65, 63, 64, 66, 67, 71, 69, 70, 73, 72, 74, 87, 81, 78, 76, 77,
	79, 80, 84, 82, 83, 85, 86, 93, 90, 88, 89, 91, 92, 96, 94, 95, 98, 97, 99, 100
};

 g_S1 and g_S2 are sufficiently described. g_S3 are the number 1..100 ordered in Binary
 Search Fashion as described in class. I created a recursive function is printed out the
 number and then placed them here. The function is give at the bottom of this readme.

 The output of the execution will be similar to the OUTPUT pasted below. There will
 be four sections Task 1, Task 2, Task 3 and Task 3. Each section will be broken down
 into "sub-task 1", "sub-task 2", and "sub-task 3".

 A task looks like this:
=================================
========== Task 1: BST ==========
=================================
===== BST sub-task 1 =====
tree height: 10
                                    .--10
                                .--9
                            .--8
                        .--7
                    .--6
                .--5
            .--4
        .--3
    .--2
---1


1 2 3 4 5 6 7 8 9 10 

 A sub-task looks like this:
 ===== BST sub-task 2 =====
tree height: 6
        .--100
       |   |        .--87
       |   |    .--84
       |    `--60
    .--58
   |   |    .--49
   |    `--28
---19
   |    .--11
    `--1


1 11 19 28 49 58 60 84 87 100 
----
Note, the tree height is indicated by "tree height:". Below that, we should the Tree Visualization.

PLEASE NOTE: Set your fonts small and your application wide to view the visualization. They can 
extend quite a bit horizontally.

Following the tree structure, the series of number are the inorder traversal of the elements in
the tree.

You may also see "deleting 50" and "searching 50" for some of the tree operations. The mean
deleting node with key 50 (used by Tasks 1-3) and searching for node with key 50 (used by 
Task 4).


/////////////////////////////////////////////////////////////////////////////
PROGRAM STRUCTURE

The programs is structed in an object oriented manner. CBST is the base class
for all tree algorithms - CDSW, CAVL and CSplay.

CBST ---> CDSW
     |--> CAVL
	 |--> CSplay

CBST
  - Binary Search Tree operations.
    - Height()        Get the height of the tree.
	- Insert()        Insert a key.
	- Remove()        Remove a node.
	- SmallestNode()  Get the smallest node in the tree.
	- RotateRight()   Rotate right operation.
	- RotateLeft()    Rotate left operation.
	- _root           Root node pointer.
  - Base class for all BST operations.

CDSW
  - DSW algorithm operations.
    - BalanceTree()   Perform balancing operation using DSW.
	- TreeToVine()    Transform BST to a Vine (backbone).
	- VineToTree()    Transform Vine to BST.
	- Compress()      Perform roations used by VineToTree().
  - Derives from CBST.

CAVL
  - AVL tree operations.
    - Height()        Get tree height as stored in the node.
	- Insert()        Insert by calling base class and Rebalance().
	- Remove()        Remove by calling base class and Rebalance().
	- GetBalanceFactor()
	                  Get balance factor between right/left subtrees.
	- Rebalance()     Peform AVL algorithm to balance tree using balance factors.
  - Derives from CBST.

CSPLAY
  - Splay tree operations.
    - Search()        Search for key; call Splay() and return node.
	- Insert()        Insert by calling base class and Splay().
	- Remove()        Remove by calling base class and Splay().
	- Splay()         Perform Splay algorith to Zig/Zag to balance tree.
  - Derives from CBST.

  All of these classes use the CNode class which defines the binary tree node.

  CNode
    - Defines node structure used by algorithms.
	  - int key      Defines an integer key.
	  - CNode left   Defines a pointer to the left subtree.
	  - CNode right  Defines a pointer to the right subtree.
	  - int height   Defines the height of the tree. This is only used for AVL trees.

/////////////////////////////////////////////////////////////////////////////
REFERENCE CODE (created by me)

I created the function below (in another project) to output the numbers for 
g_S3 which is the number 1..100 in Binary Search Fashion. This function mostly
executed fine, but only outputted 99 numbers since once it got to "1" and the 
size was one, it simply returned. For this case, I manually added the number "1" 
into the list to create the full 100 element g_S3 array.

int bst(std::vector<int> v)
{
	if (v.size() <= 1)
	{
		return 0;
	}
	
	std::cout << v[(v.size() / 2)-1] << ", ";
	std::vector<int> left(v.size()/2);
	std::vector<int>::const_iterator first = v.begin();
	std::vector<int>::const_iterator last = v.begin() + (v.size()/2);
	std::copy(first, last, left.begin());

	std::vector<int> right(v.size() - v.size() / 2);
	first = v.begin() + (v.size() / 2);
	last = v.begin() + (v.size());
	std::copy(first, last, right.begin());

	bst(left);
	bst(right);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
ACKNOWLEDGE AND REFERENCE(S)

1. Class notes. Binary Trees Lecture 8 and 9. DSW Algorithm and Rotations.
   http://trifort.org/ads/index.html

2. Wikipedia. Various articles on BST and alogrithms.
   https://www.wikipedia.org/

3. Binary Trees in C, Alex Allain.
   https://www.cprogramming.com/tutorial/c/lesson18.html

4. DSW Algorithm, Wikipedia.
   https://en.wikipedia.org/wiki/Day%E2%80%93Stout%E2%80%93Warren_algorithm

5. DSW Algorithm, DSW
   http://web.eecs.umich.edu/~qstout/pap/CACM86.pdf

6. Geek for Geeks, Algorithms. Various articles.
   https://www.geeksforgeeks.org

7. Splay Trees
   https://algorithmtutor.com/Data-Structures/Tree/Splay-Trees/

8. Wikipedia. Tree Rotation
   https://en.wikipedia.org/wiki/Tree_rotation