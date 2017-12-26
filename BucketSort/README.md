**Disclaimer:
This code will only work with other input texts file that follow the same format as data1.txt provided**

What is Bucket Sort?
Bucket Sort is a well known sorting algorithm that uses "buckets" to sort data into each of these buckets.  
The data structure for Bucket Sort is a 1-D array of linked lists.  
In order to sort each data into its respective bucket, the identity function is used to hash these buckets. What this means is that the data itself is the index within the 1-D array, and then the data is sorted using insertion sort within the linked list of each index in the 1-D array.  

Given File:  
BucketSort.cpp - C++ implementation  
data1.txt - input data  

Bucket Sort Algorithm Steps:  
Step 0: maxSize <-- read the entire data to find the largest data.  
	Dynamically allocate bucketAry and initialize it to 0.  
Step 1: data <-- get nextData from input file  
Step 2: index <-- Hash(data)  
Step 3: bucketAry[index]++  
Step 4: repeat Steps 1 – 3 until no more data to read  
Step 5: index = 0  
Step 6.1: while(bucketAry[index] > 0) print index to outFile  
Step 6.2: bucketAry[index]--;  
Step 6.3: repeat Step 6.1 - 6.2 until bucketAry[index] == 0  
Step 7: index++  
Step 8: repeat Step 6 – 7 while index < maxSize  
