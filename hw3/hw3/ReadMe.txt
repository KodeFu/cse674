========================================================================
    CONSOLE APPLICATION : hw3 Project Overview

	This project performs several sorting methods on random ascending, 
	random	descending, and random data.
========================================================================

/////////////////////////////////////////////////////////////////////////////
SUPER SHORT HOW-TO

- Run by exectuing hw2.exe. No arguments needed. This will run all sorts
  for all iterations using data files mentioned below.
    hw2/Release/hw2.exe

- Data files used by hw2.exe are:
    hw2/Release/ascending.txt
	hw2/Release/descending.txt
	hw2/Release/random.txt

- Output of hw2.exe for Data Files listed above in:
    hw2/Release/output.txt

- Charts located in output.xlsx. Three tabs for Asceding, Descending and Random. Also
  an additional tabl for the Program Output (same as output.txt).
    hw2/Release/output.xlsx

- If you rebuild, build in Release mode since debug really slows down performance.

/////////////////////////////////////////////////////////////////////////////
Files in this application:

hw2.cpp
 This is the main application source file.

BubbleSort.h/.cpp
 BubbleSort definition and implementation.

BubbleSortWithFlag.h/.cpp
 BubbleSort w/Flag definition and implementation.

InsertionSort.h/.cpp
 InsertionSort definition and implementation.

SelectionSort.h/.cpp
 SelectionSort definition and implementation.

HeapSort.h/.cpp
 Heap Sort definition and implementation.

MergeSort.h/.cpp
 Merge Sort definition and implementation.

QuickSort.h/.cpp
 Quick Sort definition and implementation.

RadixSort.h/.cpp
 Radix Sort definition and implementation.

CountingSort.h/.cpp
 Counting Sort definition and implementation.

SmoothSort.h/.cpp
 Smooth Sort definition and implementation.

GenInput.h/cpp
 Input generation definition and implementation.

/////////////////////////////////////////////////////////////////////////////
EXECUTION

To run the application:
 1. cd Release
 2. hw2.exe

 This will run the hw2.exe program, running through all of the sorting methods.
 The data files which will be used are already in the executables directory. They
 are ascending.txt, descending.txt and random.txt.

 The output of the execution will be similar to the OUTPUT pasted below. There will
 be three sections Ascending, Descending and Random. Only Ascending is shown here. The
 format of each line is:

 <sort type> <step> <first run time> <second run time> <third run time> <average run time>

 For example using a line from BubbleSort we see:
 
  BubbleSort 32000 281 279 281 280

  This means:
   Sort type is BubbleSort.
   This is the 32000 step. 
   The first run time is 281.
   The second run time is 279.
   The third run time is 281.
   The average run time 280.

The output is in a file called OUTPUT.TXT. This is the output when running against the
current ascending.txt, descending.txt and random.txt files.

 ---------OUTPUT START---------
============================================
 Ascending
============================================
BubbleSort 1000 0 0 0 0
BubbleSort 2000 1 1 1 1
BubbleSort 4000 4 4 4 4
BubbleSort 8000 17 17 17 17
BubbleSort 16000 69 69 70 69
BubbleSort 32000 281 279 281 280
BubbleSort 64000 1125 1121 1132 1126
BubbleSort 128000 4491 4530 4539 4520
BubbleSort 256000 18122 18089 18153 18121
BubbleSort 512000 72355 72302 72364 72340
BubbleSort 1000000 276569 276238 277836 276881
BubbleSort with Flag 1000 0 0 0 0
BubbleSort with Flag 2000 0 0 0 0
BubbleSort with Flag 4000 0 0 0 0
BubbleSort with Flag 8000 0 0 0 0
BubbleSort with Flag 16000 0 0 0 0
BubbleSort with Flag 32000 0 0 0 0
BubbleSort with Flag 64000 0 0 0 0
BubbleSort with Flag 128000 0 0 0 0
BubbleSort with Flag 256000 0 0 0 0
BubbleSort with Flag 512000 0 0 0 0
BubbleSort with Flag 1000000 0 0 0 0
Insertion Sort 1000 0 0 0 0
Insertion Sort 2000 0 0 0 0
Insertion Sort 4000 0 0 0 0
Insertion Sort 8000 0 0 0 0
Insertion Sort 16000 0 0 0 0
Insertion Sort 32000 0 0 0 0
Insertion Sort 64000 0 0 0 0
Insertion Sort 128000 0 0 0 0
Insertion Sort 256000 0 0 0 0
Insertion Sort 512000 0 0 0 0
Insertion Sort 1000000 0 0 0 0
Selection Sort 1000 0 0 0 0
Selection Sort 2000 0 0 0 0
Selection Sort 4000 3 4 3 3
Selection Sort 8000 14 15 16 15
Selection Sort 16000 69 60 60 63
Selection Sort 32000 240 239 242 240
Selection Sort 64000 961 960 970 963
Selection Sort 128000 3839 3849 3856 3848
Selection Sort 256000 15379 15366 15446 15397
Selection Sort 512000 61699 61618 61712 61676
Selection Sort 1000000 235874 235908 235901 235894
Heap Sort 1000 0 0 0 0
Heap Sort 2000 0 0 0 0
Heap Sort 4000 0 0 0 0
Heap Sort 8000 0 0 0 0
Heap Sort 16000 0 0 0 0
Heap Sort 32000 1 1 1 1
Heap Sort 64000 2 2 2 2
Heap Sort 128000 5 5 5 5
Heap Sort 256000 11 11 11 11
Heap Sort 512000 34 24 25 27
Heap Sort 1000000 55 53 53 53
Merge Sort 1000 0 0 0 0
Merge Sort 2000 0 0 0 0
Merge Sort 4000 1 1 1 1
Merge Sort 8000 2 2 2 2
Merge Sort 16000 5 5 5 5
Merge Sort 32000 11 10 10 10
Merge Sort 64000 22 21 21 21
Merge Sort 128000 44 43 43 43
Merge Sort 256000 91 88 88 89
Merge Sort 512000 180 178 179 179
Merge Sort 1000000 361 360 361 360
Quick Sort 1000 0 0 0 0
Quick Sort 2000 0 0 0 0
Quick Sort 4000 0 0 0 0
Quick Sort 8000 0 0 0 0
Quick Sort 16000 0 0 0 0
Quick Sort 32000 0 0 0 0
Quick Sort 64000 1 1 1 1
Quick Sort 128000 2 2 2 2
Quick Sort 256000 4 4 4 4
Quick Sort 512000 9 9 9 9
Quick Sort 1000000 18 18 18 18
Radix Sort 1000 0 0 0 0
Radix Sort 2000 0 0 0 0
Radix Sort 4000 0 0 0 0
Radix Sort 8000 1 1 1 1
Radix Sort 16000 2 2 2 2
Radix Sort 32000 5 5 5 5
Radix Sort 64000 10 10 10 10
Radix Sort 128000 21 21 21 21
Radix Sort 256000 45 45 45 45
Radix Sort 512000 91 91 91 91
Radix Sort 1000000 174 178 173 175
Counting Sort 1000 7 6 6 6
Counting Sort 2000 6 6 6 6
Counting Sort 4000 6 6 6 6
Counting Sort 8000 7 6 6 6
Counting Sort 16000 6 7 6 6
Counting Sort 32000 7 7 7 7
Counting Sort 64000 7 7 6 6
Counting Sort 128000 7 7 7 7
Counting Sort 256000 7 7 7 7
Counting Sort 512000 8 8 8 8
Counting Sort 1000000 10 10 10 10
Smooth Sort 1000 0 0 0 0
Smooth Sort 2000 0 0 0 0
Smooth Sort 4000 0 0 0 0
Smooth Sort 8000 0 0 0 0
Smooth Sort 16000 0 0 0 0
Smooth Sort 32000 0 0 0 0
Smooth Sort 64000 0 0 0 0
Smooth Sort 128000 1 1 1 1
Smooth Sort 256000 2 2 2 2
Smooth Sort 512000 5 5 5 5
Smooth Sort 1000000 10 10 10 10
---------OUTPUT END---------

/////////////////////////////////////////////////////////////////////////////
CHARTS

The output of each run Ascending, Descening and Random are manually entered
into an Excel spreadsheet.

There are three tabs: One for Asceding, one for Descending and one for Random.

Each tab contains the average time for each sort for each step and the line
chart showing their performance.

This file is called OUTPUT.XLSX.

There is also one additional tab for Program Output. This is the same as
output.txt which contains the program output, which is the times for each
sorting meting for a particular step.

/////////////////////////////////////////////////////////////////////////////
ALGORITHMS

Algorithms:
 BubbleSort
 BubbleSort w/Flag
 InsertionSort
 SelectionSort
 Heap Sort
 Merge Sort
 Quick Sort
 Radix Sort
 Counting Sort
 Smooth Sort

/////////////////////////////////////////////////////////////////////////////
DATA INPUT

The CGenInput() class is used to generate input. Random input is used for all
three data files. The input is pre-generated and in the executable's directory
for convenience.

If regeneration is desired, uncomment the lines below the comment in main.cpp.
// Uncomment to regenerate input file. Otherwise current input files ascending.txt, 
// descending.txt and random.txt will be reused.

ASCENDING.TXT
 This file contains a "-" delimited set of random integers whichs are in
 ascending order.

DESCENDING.TXT
 This file contains a "-" delimited set of random integers whichs are in
 descending order.

RANDOM.TXT
  This file contains a "-" delimited set of random integers whichs are in
  random order.

/////////////////////////////////////////////////////////////////////////////
ACKNOWLEDGE AND REFERENCE(S):

1. Class notes. Binary Trees Lecture 8 and 9. DSW Algorithm and Rotations.
   http://trifort.org/ads/index.html

2. Wikipedia. Various articles on BST and alogrithms.
   https://www.wikipedia.org/

3. Geek for Geeks website. Various articles BST and algorithms.
   http://geeksforgeeks.org/

4. Binary Trees in C, Alex Allain
   https://www.cprogramming.com/tutorial/c/lesson18.html

5. DSW Algorithm, Wikipedia
   https://en.wikipedia.org/wiki/Day%E2%80%93Stout%E2%80%93Warren_algorithm