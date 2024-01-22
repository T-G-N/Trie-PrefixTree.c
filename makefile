CC = gcc
BINS = _test clean

trie:
	$(CC) -o build/trie.o -c src/trie.c

_test: trie
	$(CC) -o build/trie.exe test/unitTest.c build/trie.o

example: trie
	$(CC) -o build/example.exe test/example.c build/trie.o
	./build/example.exe

clean:
	rm -f build/*.o
