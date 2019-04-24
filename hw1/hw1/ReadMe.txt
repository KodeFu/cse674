========================================================================
    CONSOLE APPLICATION : hw1 Project Overview
========================================================================

PROJECT FILES

This project consists of the following source code files:
    - main.cpp is the console application.
    - SingleList.h is the efinition and implementation of the Single Linked List.
    - SingleList.cpp is the mplementation of the Single Linked List.
    - DoubleList.h is the definition the Double Linked List.
    - DoubleList.cpp is the definition and implementation of the Double Linked List.

This project consists of the following exectuable files:
    - \Debug\hw1.exe is the executable which can be run.
    
This project consists of the following output files:	
    - Output.txt is the output as required by this lab.
    - OutputVerbose.txt is the required output but with additional node (pointer) information.

DATA STRUCTURES

Description of data structures:

(1) Single Linked List (class SingleList)
This list is a single linked list made of nodes. 

The node structure is defined as below which is a public member contained within the 
SingleList class.

    struct Node 
    {
        int value;
        Node *next;
    };

In this data structure, we store an int and a pointer to the next node. Please see the figure below.
The linked list contains a HEAD which points to the beginning of the list, a TAIL which points to the 
last node of the list and nodes which contain a the int value and a pointer to the next node.

HEAD-->[int]-->[int]-->[int]-->NULL
                        ^--TAIL

The class members are defined as below:

    SingleList();                 // Constructor
    ~SingleList();                // Destructor

    void AddAtHead(Node *node);   // Adds a node to the HEAD
    void AddAtTail(Node *node);   // Adds a node to the TAIL
    Node *GetAtHead();            // Get the node at HEAD
    Node *GetAtTail();            // Get the node at TAIL
    Node *GetAtIndex(int index);  // Get the node for a node value
    void RemoveAtHead();          // Remove node at HEAD
    void RemoveAtTail();          // Remove node at TAIL
    void RemoveAll();             // Remove (deallocate) all nodes
    void Swap(Node *left);        // Swap adjacent nodes
    void BubbleSort(              // Bubble sort algorithm, to sort at a starting index 
        int startIndex = 0,       // for a specfified range
        int rangeLength = 0);
    int  Size();                  // Get number of nodes in list

    void TeamOfFour();            // Perform TeamOfFour operation
    void Reverse();               // Perform Reverse operation
    void Shuffle();               // Perform Shuffle operation

    void PrintNode(Node *node);   // Print a node
    void PrintAll();              // Print all nodes
    void PrintResults();          // Print results per lab requirement

private:
    Node *head;                   // HEAD pointer
    Node *tail;                   // TAIL pointer
    int size;                     // List size

(2) Double Linked List (class DoubleList)
This list is a double linked list made of nodes. The node structure is defined as below.

    struct Node 
    {
        int value;
        Node *prev;
        Node *next;
    };

In this data structure, we store an int, a pointer to the next node and a pointer to the previous node. Please 
see the figure below. The linked list contains a HEAD which points to the beginning of the list, a TAIL which 
points to the last node of the list and nodes which contain a the int value, a pointer to the next node and a 
pointer to the previous node.

HEAD-->[int]-->[int]-->[int]-->NULL
    <--[   ]<--[   ]<--[   ]<--
                        ^--TAIL

	DoubleList();                 // Constructor
	~DoubleList();                // Destructor

    void AddAtHead(Node *node);   // Adds a node to the HEAD
    void AddAtTail(Node *node);   // Adds a node to the TAIL
    Node *GetAtHead();            // Get the node at HEAD
    Node *GetAtTail();            // Get the node at TAIL
    Node *GetAtIndex(int index);  // Get the node for a node value
    void RemoveAtHead();          // Remove node at HEAD
    void RemoveAtTail();          // Remove node at TAIL
    void RemoveAll();             // Remove (deallocate) all nodes
    void Swap(Node *left);        // Swap adjacent nodes
    void BubbleSort(              // Bubble sort algorithm, to sort at a starting index 
        int startIndex = 0,       // for a specfified range
        int rangeLength = 0);
    int  Size();                  // Get number of nodes in list

    void TeamOfFour();            // Perform TeamOfFour operation
    void Reverse();               // Perform Reverse operation
    void Shuffle();               // Perform Shuffle operation

    void PrintNode(Node *node);   // Print a node
    void PrintAll();              // Print all nodes
    void PrintResults();          // Print results per lab requirement

private:
    Node *head;                   // HEAD pointer
    Node *tail;                   // TAIL pointer
    int size;                     // List size


OPERATIONS

Description of operations:

(1) Team of Four

All operations are implemented as member function within the linked list class for single and double. The 
Team of Four mainly relies on the BubbleSort() function and Swap(). These were implemented in such a way that 
the start index and range is specfified for BubbleSort, so we can easy sort subsets of our array for a particular 
range. For Team of Four, we specify, for example, index 0 for the start index and range of 4. This sorts the 
first four nodes of the list. The Swap function is utilized within BubbleSort to swap nodes into the right order.

For the TeamOfFour() function is implemented as:

void SingleList::TeamOfFour() // same for DoubleList
{
	for (int i = 0; i < size; i+=4)
	{
		BubbleSort(i, 4);
	}
}

Here we can see that BubbleSort is called for each group of four nodes. The BubbleSort is implemented as below 
(trimmed down for clarity). It is implemented the same way for the single list and the double list.

void SingleList::BubbleSort(int startIndex, int rangeLength)
{
	bool swapped = true;
	Node *curr = NULL;
	Node *next = NULL;
	int range = 0;

	while (swapped) {
		swapped = false;
		(!startIndex) ? curr = head : curr = GetAtIndex(startIndex);
		(!rangeLength) ? range = size : range = startIndex + rangeLength;

		Node *next = curr->next;
		for (int i = startIndex; i < range - 1; i++)
		{
			if (curr->value > next->value) {
				Swap(curr);
				swapped = true;	// if we did swap, curr stays the same since it
			  	                // swapped with next
			} else {
				curr = next; // if we didn't swap, curr advances to next
			}

			if (curr->next != NULL)	{
				next = curr->next;
			} else {
				break;
			}
		}
	}
}

The swap function for the SingleList is shown below. left is the left node. We get the right node by accessing the
left->next node. We then swap node pointers and adjust the previous node's next pointer, head pointer and tail 
pointers as well. 

The double list implementation is similar except that it takes into account the previous pointer in each node. Also,
since it a double list, we can easily get the previous node without searching from the top of the linked list.

void SingleList::Swap(Node *left)
{
	Node *prev = NULL;

	// search for previous node
	Node *tmp = head;
	while (tmp && (tmp != left)) {
		prev = tmp;
		tmp = tmp->next;
	}

	Node *nodeA = left;
	Node *nodeB = left->next;

	if (nodeA && nodeB)	{
		if (prev) {
			prev->next = nodeB;
		} else {
			head = nodeB;
		}

		nodeA->next = nodeB->next;
		nodeB->next = nodeA;

		// adjust tail if node points to NULL
		if (nodeA->next == NULL) tail = nodeA;
		if (nodeB->next == NULL) tail = nodeB;
	}
}

(2) Reverse

Both implementations, for single list and double list, are shows for Reverse below. For single list, the next 
pointers are change to point to the previous node.

void SingleList::Reverse()
{
	Node *prev;
	Node *curr;
	Node *next;

	// don't do anything if there are no nodes
	if (!size) return;

	// make head node the last node
	prev = NULL;
	curr = head;
	next = curr->next;

	curr->next = NULL;
	tail = curr;

	// reverse next pointer for every node thereafter
	while (next != NULL) {
		prev = curr;
		curr = next;
		next = curr->next;

		curr->next = prev;
	}

	// point the head to the current front node
	head = curr;
}

For double list, the next pointers are change to point to the previous node. Also, because this is a double list,
the previous pointers are changed to the next pointers.

void DoubleList::Reverse()
{
	Node *curr;
	Node *next;

	// start from the tail
	curr = tail;

	// get next node; work with this after curr
	next = curr->prev;

	// adjust the node's pointers
	curr->prev = NULL; // head
	curr->next = next;

	while (next != NULL)
	{
		curr = next;

		next = curr->prev;
		curr->prev = curr->next;
		curr->next = next;
	}

	// swap head and tail
	Node *tmp = head;
	head = tail;
	tail = tmp;
}

(3) Shuffle

The Shuffle operation is the same for both single and double list. The basic idea is that we have two sets of
pointers for right and left. The right points to the "right half" of the elements which are going to be inserted
into the "left half" of the elements. The algorithm iterates through each node of the right side and inserts that
into nodes on the left side.

void DoubleList::Shuffle()
{
	int halfDeck = size / 2;

	Node *leftCurr = head;
	Node *leftNext = NULL;

	Node *rightCurr = GetAtIndex(halfDeck);
	Node *rightNext = NULL;

	for (int i = 0; i < halfDeck; i++) {
		leftNext = leftCurr->next;
		leftCurr->next = rightCurr;

		rightNext = rightCurr->next;
		if (rightNext == NULL) {
			// end of right half of deck
			break;
		}

		rightCurr->next = leftNext;

		leftCurr = leftNext;
		rightCurr = rightNext;
		rightNext = rightCurr->next;
	}
}

EVIDENCE
"Evidence that your code implements the required operations by modifying the pointers."

** All code shown above and in this project show that pointers of nodes are being manipulated and values are NOT 
being simply copied. All list manipulations occur on existing lists by moving pointers around to achieve the desired 
results. **

As evidence, included is the OutputVerbose.txt, which includes output with pointer information. 

For example:

For Single List (copy/pasting a small chunk below), we see the Before the Team of Four operation and right after that,
we see the pointers. We can see the size of the list, the head, and the tail. Below that, we can also see two address
and a value which can be described as:

<node's address>  <next pointer address> <value>

We can follow the linked list address by looking at the HEAD, which points to 0x00216648 which is the first node (100). We
can then see that the first node's "next" pointer address points to 0x00216300 which points to the next node (8.)

***** Before the Team of Four operation *****
100, 8, 56, 55, 
...

size: 100
head: 00216648
tail: 002197D8
  -> 0x00216648  0x00216300  100
  -> 0x00216300  0x00216958  8
  -> 0x00216958  0x002164F8  56
  -> 0x002164F8  0x00216338  55

The output below shows similar output, but this is for the AFTER the Team of Four operation. Using a similar technique 
described above, we can follow the now sorted for elements. HEAD points to 0x216300. This node (8), points to the next 
node 0x002164F8 (55).

***** After the Team of Four operation *****
8, 55, 56, 100, 

size: 100
head: 00216300
tail: 00219768
  -> 0x00216300  0x002164F8  8
  -> 0x002164F8  0x00216958  55
  -> 0x00216958  0x00216648  56
  -> 0x00216648  0x002163E0  100

OutputVerbose.txt contains all of the operation results with head, tail and node information. Please note, that 
the double list version contains the node's previous address as well, so that node's info would look like this:

<node's address> <previous pointer address> <next pointer address> <value>

As mentioned, only pointers were manipulated and pointer values can be viewed, for reference, by looking at the
OutputVerbose.txt file.

Additionally, if desired, the code can be compiled to print this verbose pointer information by uncommenting the
VERBOSE define in SingleList.cpp and DoubleList.cpp. This will print the output for each of the operations with
the pointer informatin as well.

ACKNOWLEDGE AND REFERENCE(S):

1. CLRS - Introduction to Algorithms. While I didn't use any code, I have been reading this book about algorithms in 
   this class so some ideas were likely influenced by this book.

2. BubbleSort https://en.wikipedia.org/wiki/Bubble_sort. I needed to understand this again and used the Pseudocode of 
   "procedure bubblesort" as a reference for the BubbleSort implementation.