
#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdlib.h>

typedef struct Trie trie;

#define trie_null ((trie*){ 0 })

trie* trie_create();

void trie_add(trie* trie, char* word);
void trie_remove(trie* trie, char* word);

void trie_clear(trie* trie);
char** trie_get(trie* trie, char* word, size_t* stringSize);

void trie_delete(trie* trie);

#endif /* _TRIE_H_ */
