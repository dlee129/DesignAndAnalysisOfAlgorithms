**Disclaimer:
This program will only work if you used the same format used in the MST_Data1.txt and MST_Data2.txt file.**  

Problem Statement: Given an undirected graph, G = <N, E>, the task is find a minimum spanning tree of G, using the Kruskal’s algorithm.  

What is Kruskal's Minimal Spanning Tree?  
Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two nodes in a graph.  

What is Prim's Minimal Spanning Tree?  
 Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.  

Given Files:  
Kruskal.cpp - C++ implementation  
Prim.java - Java implementation  
MST_Data1.txt - input file  
MST_Data2.txt - input file  

Kruskal’s algorithm for finding the Minimum Spanning Tree:  
Step 0: numNodes <-- get from input file; Allocate and initialize all the members in KruskalMST class, printSet(inWhichSet)  
Step 1: <Ni, Nj, edgeCost> <-- read from input file  
newEdge <-- create an undirectedEdge and fill with <Ni, Nj, cost>  
insertEdge(newEdge, edgeListHead)  
Step 2: printList (edgeListHead)  
Step 3: repeat step 1 to step 2 until the input file is empty  
Step 4: nextEdge <-- removedEdge (edgeListHead)  
if Ni and Nj are in the same set  
     then discard nextEdge  
Step 5: repeat step  4 until Ni and Nj are in different sets.  
Step 6 pushEdge(nextEdge, MSTofG)  
           totalMSTCost += the cost of nextEdge  
           merge2Sets (Ni, Nj)  
           numSets--  
           printSet(inWhichSet)  
Step 7: printList(MSTofG)  
Step 8: repeat step 4 – step 7 until numSets is equal to 1.  
Step 9: output the entire MSTofG and the totalCost to argv[2]  
Step 10: close all files.  


Prim’s algorithm for finding the Minimum Spanning Tree:  
Step 0:  numNodes <-- get from input file. Allocate and initialize all the members in PrimMST class accordingly  
Step 1: <Ni, Nj, edgeCost> <-- read from input file  
     newEdge <-- create an undirectedEdge and fill with <Ni, Nj, cost>   
     insertEdge ( newEdge, edgeListHead)  		  
Step 2: printList (edgeListHead)  
Step 3: repeat step 1 to step 2 until the input file is empty  
Step 4: nextEdge <-- removedEdge (edgeListHead)  
     If Ni and Nj are in the same set  
Step 5: repeat step 4 until Ni  and Nj are in different sets  
Step 6: pushEdge(nextEdge, MSTofG) // push nextEdge in the front of MSTofG  
     totalMSTCost += the cost of nextEdge  
     if Ni is in setA,  
          move2SetA(Nj, setA)  
     else  
          move2SetA(Ni, setA)  
          printSet(inWhichSet)  
Step 7: printList(MSTofG)  
Step 8: repeat step 4 – step 7 until setB is empty.  
Step 9: output the entire MSTofG and the totalCost to outfile1, argv[1], with proper heading,  one edge with cost per text line.  
Step 10: close all files.  
