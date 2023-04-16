# Hash Table Word Puzzle Solver

![word puzzle game](https://upload.wikimedia.org/wikipedia/commons/f/fa/Wordsearch.svg)

## Overview
This program implements a word puzzle solver using a hash table data structure in C++. The program reads two text files containing a list of words and a word puzzle grid, respectively.
It constructs a hash table to store the word dictionary. It iteratively runs through the grid in 8 directions,
extracts all strings longer than 2 characters, and checks if any of them are present in the hash table.

My implementation of the hash table is a vector of binary search trees. 

The runtime of the hash table search is O(1), with a good hash function found [online](https://stackoverflow.com/questions/8317508/hash-function-for-a-string). 

## Usage
The driver code processes the word grid in a specific format and suitable test files (both words and grid) are provided in the folder ```testdata```.

To compile and run:
```
make

./a.out testdata/words.txt testdata/3x3.grid.txt | sort
```

Output evvery matched word with its location on the grid:
```
N (2, 1):      nab
NE (2, 0):      jag
S (0, 1):      ban
W (1, 2):      nay
4 words found
```