**Disclaimer:
This code will only work with other input texts file that follow the same format as GraphColoring_data.txt provided**

What is the Graph coloring problem?  
Given a undirected graph, G = <N, E>, the graph coloring problem is to find the minumum number of colors to color all nodes in N, such that two adjacent nodes, ni, nj, can not be colored with the same color.  

Given File:  
GraphColoring.java - Method #1 Java implementation  
GraphColoring.cpp - Method #2 C++ implementation  
GraphColoring_data.txt - input data  

There are two greedy methods associated with the GraphColoring problem:  
1) The first greedy method implemented is "greedy" with trying to color as many nodes as possible with the current color that is being used.  
2) The second greedy method implemented has a list of used colors, which are previous colors used to "color" a node. This method tries to use previously used colors before using a new color in order to minimalize the amount of new colors used.  

GraphColoring Problem Algorithm Steps:  
Step 0: numNode <-- get from input file  
	dynamically allocate adjacencyMatrix  
	load adjacencyMatrix from the input pairs  
 	print adjacencyMatrix  
	constructNodeList  
	newColor <-- 0  
Step 1: newColor ++  
     currentNode <-- listHead's next  
Step 2: if currentNode.Color == 0 // if currentNode is an uncolor node checkAdjacent (currentNode.ID, newColor) == 0  
         then		
	     adjacentMatrix[currentNode][currentNode] <-- newColor  
          currentNode.Color <-- newColor  
		currentNode <-- currentNode's next  
Step 3: repeat step 2 until the end of the node list.  
Step 4: print adjacencyMatrix  
Step 5: repeat steps 1 to 3 until all nodes are colored.  
Step 6: print newcolor  
        print adjacencyMatrix  
Step 7: close all files  
