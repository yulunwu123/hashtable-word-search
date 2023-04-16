#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "BinarySearchTree.h"

using namespace std;

class hashTable
{
public:
	hashTable(int n);
	~hashTable();
	int hashFunction(string key);
	void insertKey(string key);
	bool findKey(string key);
	void rehash();

private:
	int hashSize;
	vector<BinarySearchTree> myHash;
	bool checkprime(unsigned int p);
	int getNextPrime(unsigned int n);
};

#endif
