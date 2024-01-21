CC = gcc
BINS = test

test:
	$(CC) -o build/trie.exe test/unitTest.c src/trie.c

