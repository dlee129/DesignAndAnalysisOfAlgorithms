**Disclaimer
This program will only work if you used the same format used in the HuffManCoding_Data.txt file.**

There are 4 parts to the Huffman Coding Problem:  
1) Character Counting  
2) Construct Huffman ordered linked list using insertion sort  
3) Construct Huffman binary tree  
4) Create Huffman coding scheme  


Given Files:  
HuffmanCoding.java - Java Implementation  
HuffmanCoding.cpp - C++ Implementation  
HuffmanCoding_Data.txt - Given text file used for data  

This problem is a bit more complex as it requires several concepts to solve.  

Some concepts to understand before diving into this problem:  
1) What is Huffman Coding? Huffman Coding is an algorithm used for text compression. In other words, this coding algorithm will break down string/texts into characters and these characters are further broken down into strings of binary integers (0s and 1s).  
2) Why use this? Using this coding will guarantee that all of your data will stored into a binary tree and a coding table can be derived from the tree to assign a corresponding length of 0s and 1s.  

Listed below will be the complete Algorithm Steps for solving the Huffman Coding Algorithm:  

Construct Huffman ordered linked list using insertion sort Algorithm Steps:  
Step#0: Open inFile and all outfiles  
Step#1: Create a dummy listBinTreeNode and have it point to listHead  
Step#2: Get the values of chStr and prob from the inFile.  
Step#3: Implement findSpot(prob) to find the position to insert newNode  
Step#4: Create a newNode and give it the values of chStr and prob from inFile  
Step#5: Implement listInsert(spot, newNode), which will insert newNode between spot and spot.next  
Step#6: Repeat steps#2-5 while inFile is not empty  
Step#7: Close inFile.  

Construct Huffman Binary Tree Algorithm Steps:  
Step#0: Create a dummy listBinTreeNode and let OldListHead point to it. Also let OldListHead.next point to ListHead.next in order to save the original linkedlist.  
Step#1: Create a listBinTreeNode newNode  
Step#2: newNode prob = first node prob and second node prob from the list  
Step#3: newNode chStr = first node chStr and second node chStr from the list  
Step#4: newNode left = the first node in the list  
Step#5: newNode right = the second node in the list  
Step#6: Advance listHead until it points to the third node in the list  
Step#7: PrintNode(newNode) to outFile 5 for debugging purposes.  
Step#8: Implement findSpot(newNode prob) to find the position to insert newNode  
Step#9: Implement listInsert(spot, newNode), which will insert newNode between spot and spot.next  
Step#10: PrintList to outFile 5 for debugging purposes.  
Step#11: Repeat Steps#1-10 until there is only one node left which is the newNode  
Step#12: root = newNode  

Construct Huffman Char Code Pairs Recursion Algorithm Steps:  
Step#0: If T is null, print “this is an empty tree” to console and exit the program!  
Step#1: Check if T is a leaf.  
Step#2: If T is a leaf, output T’s chStr and code to outFile1 and set T’s code = code.  
Step#3: If T is not a leaf, use recursion for constructCharCode with parameters (T->left, code + “0”) and use recursion for constructCharCode with parameters (T->right, code + “1”)  
Step#4: Repeat Steps#0-3 until T is null, meaning there are no more nodes to read.  
Step#5: Close outFile1.  

**Included will be Algorithms and Codes that cover the PreOrder, InOrder, and PostOrder Traversals for the Huffman Binary Tree**  

PreOrder Traversal Print Algorithm Steps:  
Step#1: Check if T is null, if it is do nothing.  
Step#2: If T is not null, output T to outFile2.  
Step#3: Recursively call preOrder(pw, T.left) until there is T.left is null  
Step#4: Recursively call preOrder(pw, T.right) until there is T.right is null  
Step#5: Repeat Steps#1-4 until there are no more T.left and T.right to go to.  
Step#6: Close outFile2.  

InOrder Traversal Print Algorithm Steps:  
Step#1: Check if T is null, if it is do nothing.  
Step#2: Recursively call InOrder(pw, T.left) until there is T.left is null  
Step#3: If T is not null, output T to outFile3.  
Step#4: Recursively call InOrder(pw, T.right) until there is T.right is null  
Step#5: Repeat Steps#1-4 until there are no more T.left and T.right to go to.  
Step#6: Close outFile3.  

PostOrder Traversal Print Algorithm Steps:  
Step#1: Check if T is null, if it is do nothing.  
Step#2: Recursively call PostOrder(pw, T.left) until there is T.left is null  
Step#3: Recursively call PostOrder(pw, T.right) until there is T.right is null  
Step#4: If T is not null, output T to outFile4.  
Step#5: Repeat Steps#1-4 until there are no more T.left and T.right to go to.  
Step#6: Close outFile4.  
