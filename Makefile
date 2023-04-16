a.out: hashTable.o timer.o wordPuzzle.o BinarySearchTree.o BinaryNode.o
	clang++ -O2 hashTable.o timer.o wordPuzzle.o BinarySearchTree.o BinaryNode.o -o a.out

hashTable.o: hashTable.h hashTable.cpp
	clang++ -c -Wall -O2 hashTable.cpp

timer.o: timer.h timer.cpp
	clang++ -c -Wall -O2 timer.cpp

wordPuzzle.o: wordPuzzle.cpp
	clang++ -c -Wall -O2 wordPuzzle.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	clang++ -c -Wall -O2 BinarySearchTree.cpp

BinaryNode.o: BinaryNode.h BinaryNode.cpp
	clang++ -c -Wall -O2 BinaryNode.cpp

clean:
		/bin/rm *.o a.out