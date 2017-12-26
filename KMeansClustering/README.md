**Disclaimer: 
This program will only work if you used the same format used in the KMeanData4Clusters.txt file.**

What is K Means Clustering?  
K Means Clustering is a greedy algorithm used to cluster analysis in data mining. In other terms, it is used to group together data points into clusters in which each cluster represents a certain feature or classification. This is useful for adding new data to a set of data points to see where the new data would be classified under.

Given Files:  
KMeansClustering.cpp - C++ implementation  
KMeanData4Clusters.txt - input file  

Kmeans Clustering Algorithm Steps:  
Step#0: Open the input file inFile  
Step#0.1: Create and initialize K,numRow,numCol,and numPts and methods for class Kmeans  
Step#0.2: Dynamically allocate imageArray as an int 2d array where size = numRow x numCol  
Step#0.3: Dynamically allocate the size of the array pointset using size numPts  
Step#0.4: Dynamically allocate the size of the struct array Kcentroids using size K  
Step#1: Call loadPointSet. Loads all points from inFile into pointSet  
Step#2: Call AssignLabel. Assigns each of the data points in the input a random label from 1 to K  
Step#3: Call mapPoint2Image. Maps the points label using its coordinates and storing it in imageArray  
Step#4: Call PrettyPrint. Prints each iteration of label changing output to outFile2  
Step#5.1: Initialize changeLabel = 0  
Step#5.2: Go through the entire pointset array and compute the centroids of each of the K clusters. Store the computed centroids in the Kcentroid array.  
Step#6.1: For each point p in pointset array, calculate the distance between point p and kcentroid[i] for i from 1 to K  
Step#6.2: Store the most minimal distance between point p and the kcentroinds and give its label to min_i  
Step#6.3: if min_i’s Label is not the same as p's Label change p's label to min_i’s label and increment changeLabel ++  
Step#7: Repeat Steps#6.1-6.3 until all points in pointset and the minimum distance label’s are processed  
Step#8: Repeat Steps#3-7 while chengeLabel > 0  
Step#9: Output the final labels from imageArray into Output outFile1 using PrettyPrint  
Step#10: Close all files  
