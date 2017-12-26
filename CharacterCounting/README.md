**Disclaimer
This program will only work if you used the same format used in the CharCount_Data.txt file.**

Character Counting Algorithm:
Compute the frequencies of characters in a given input file.(Ignoring all tabs, spaces and line returns)

Given Files:
CharacterCounting.java - Java Implementation
CharacterCounting.cpp - C++ Implementation
CharCount_data.txt - Given text file used for data

This algorithm is very straight forward in that it does not require any special data structures to implement.

The algorithm steps to solving this problem is as follows:
Step#0: Open input and output files using ifstream and ofstream. Initialize charCounts array to zero.
Step#1: Read in one character from inFile and store that value to charIn.
Step#2: Cast (int) on charIn and give index this value.
Step#3: Increment charCounts[index] to increase the count for that specific character.
Step#4: Repeat steps #1 to #3 while inFile is not empty.
Step#5: Call printAry() which will print the character and the number of times it appears in the input file.
Step#6: Close all files, both inFile and outFile.

**PrintAry is used here in order to write the counts and characters to a specified output file**
printAry Algorithm Steps:
Step#1: Initialize index to 0.
Step#2: If charCounts[index] > 0, cast (char) onto index and give this value to a new variable symbol. Print symbol “#” charCounts[index] to outFile.
Step#3: Do index++;
Step#4: Repeats steps#2 and #3 while index < 256.
