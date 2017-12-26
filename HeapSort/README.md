**Disclaimer:
This program will only work if you used the same format used in the Heap_Sort_Data.txt file.**

What is Heap Sort?  
It is an implementation of a 1-D Array of Partial Order Binary Trees/Priority Queues. It is a well known sorting algorithm in computer science that utilizes comparison between data in a Binary Heap.  
A Binary Heap is a Complete Binary Tree is a special ordered tree where the parent is smaller or greater than its children. The former is called a Min Heap, while the latter is called a Max Heap.  
A Complete Binary Tree is a binary tree where in all the levels of it, except the last level, is completely filled and all the nodes are as far left as possible.  

Given Files:  
HeapSort.cpp - C++ implementation  
Heap_Sort_Data.txt - input file  

Heap Sort Algorithm Steps:  

Step 0: Open the input file; read and count the number of date items in the input file and close the input file. Dynamically allocate heapAry[] of the size count+1 and initallize heapAry[0] to 0. Remember, heapAry[1] is the root of the tree and heapAry[0] is the last index used in heapAry.  
Step 1: call buildHeap (see method in code to figure out the algorithm)  
Step 2: call deleteHeap (see method in code to figure out the algorithm)  
Step 3: close all files  
