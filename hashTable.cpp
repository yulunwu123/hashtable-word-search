#include <iostream>
#include <string>
#include "hashTable.h"
using namespace std;

hashTable::hashTable(int n)
{
	myHash = vector<BinarySearchTree>(n);
	hashSize = n;

	BinarySearchTree *bst;
	for (int i = 0; i < hashSize; i++)
	{
		bst = new BinarySearchTree();
		myHash.push_back(*bst);
	}
}

hashTable::~hashTable()
{
	myHash.clear();
}

// This hash function was found online at:
// https://stackoverflow.com/questions/8317508/hash-function-for-a-string
int hashTable::hashFunction(string key)
{
	int seed = 131;
	unsigned long hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash * seed) + key[i];
	}
	return hash % hashSize;
}

void hashTable::insertKey(string key)
{
	int value = hashFunction(key);
	BinarySearchTree &b = myHash[value];
	b.insert(key);
}

bool hashTable::findKey(string key)
{
	int value = hashFunction(key);
	BinarySearchTree &b = myHash[value];
	if (b.find(key))
	{
		return true;
	}
	return false;
}

void rehash()
{
}

bool hashTable::checkprime(unsigned int p)
{
	if (p <= 1) // 0 and 1 are not primes; the are both special cases
		return false;
	if (p == 2) // 2 is prime
		return true;
	if (p % 2 == 0) // even numbers other than 2 are not prime
		return false;
	for (int i = 3; i * i <= p; i += 2) // only go up to the sqrt of p
		if (p % i == 0)
			return false;
	return true;
}

int hashTable::getNextPrime(unsigned int n)
{
	while (!checkprime(++n))
		;
	return n;
}
