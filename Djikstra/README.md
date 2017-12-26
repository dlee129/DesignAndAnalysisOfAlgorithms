**Disclaimer:
This program will only work if you used the same format used in the SSS_Data.txt file.**  

Problem Statement: Given a directed graph, G = <N, E>, and the source node, S, in G, the task is find the shortest paths from S to every nodes in G, using the Dijkstra’s algorithm.  

What is Djikstra's Single Shortest Path Problem?    
It is a problem where Djikstra's Algorithm is used, which is to find the single shorted path to all nodes given. Each edge is given in an input file and with it, is a edge cost associated with it. The edge cost is what determines whether the edge between two nodes is the minimal to go from one starting node and all the way to one ending node.   

Given Files:  
Djikstra.cpp - C++ implementation  
Djikstra.java - Java implementation  
Heap_Sort_Data.txt - input file  

Dijkstra’s algorithm for the Single-Source-Shortest Paths problem:  
Step#0: Open the input file inFile and output files outFile1 and outFile2  
Step#0.1: numNodes <-- get from inFile  
Step#0.2: sourceNode <-- get from inFile  
Step#0.3: Dynamically allocate the size of all arrays in Dijkstra constructor class  
Step#1: Call loadMatrix from inFile  
Step#2: Call methods setBestCostAry(sourceNode), setFatherAry(sourceNode), setToDoAry(sourceNode)  
Step#3: Get minNode <-- from findMinNode()  
Step#3.1: Call markMinNode(minNode)  
Step#3.2: Call debugPrint to outFile2 to check for any errors  
Step#4: set currentNode = 1  
Step#5: Check to see if newCost is better than the old cost for all nodes, i, where toDoAry[i] = 1  
Step#5.1: if toDoAry[currentNode]  = 1, newCost  computeCost(minNode, currentNode)  
if newCost < bestCostAry [currentNode]  
changeCost (currentNode, newCost)  
changeFather (currentNode, minNode)  
   		call debugPrint  
Step#6: currentNode++  
Step#7: Repeat Steps#5-6 while currentNode <= numNodes  
Step#8: Repeat Steps#3-7 until all nodes, i, toDoAry[i] = 0  
Step#9: Set currentNode = 1  
Step#10: Call printShortestPath(currentNode) and output to outFile1  
Step#11: currentNode++  
Step#12: Repeat Step#10 and Step#11 while currentNode <= numNodes  
Step#13: Close inFile, outFile1, and outFile2  
