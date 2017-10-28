Linked List Insertion Sort Algorithm:

Here I will describe a detailed procedure of how the Linked List Insertion Sort works as well as the algorithm it follows.

The problem is listed as:
Given a file contains a list of English words, your tasks is to construct a linked list (in ascending order) for the words.  Your linked list must have a dummy node that is pointed by the listHead.

Given files:
LinkedListInsertionSort.java - Java Implementation
LinkedListInsertionSort.cpp - Java Implementation
insertionSort_String_Data.txt - Given text file used to implement algorithm

There are a few important concepts to know before starting to solve this problem:
1) What is an algorithm? An algorithm can be described as a process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer.
2) What is a Linked List? A Linked List is a data structure of an ordered set of data elements, typically called Nodes, each containing a link to another node
3) Then what is a Node? Nodes are devices or data points on a larger network, typically a Linked List in this problem.
4) What is a dummy node? A dummy node is a node that is used to create a Linked List while not including data relevant to the given data.

Here are the Algorithm steps:
Step#1: Initialize all needed data types and open the given text files.
Step#2: Create new a Linked List with a node ListHead with the data “dummy”. Print the Linked List onto the output file.
Step#3: Retrieve data by reading a string from the input file, one String at a time.
Step#4: Insert each String data as a node into the Linked List.
Step#5: Print the Linked List after each data iterated through the input file.
Step#6: Repeat Steps#3,4, and 5 while there is still new data to be read from the input file.
Step#7: Close all opened files.
