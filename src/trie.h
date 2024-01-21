
#ifndef _TRIE_H_
#define _TRIE_H_

typedef struct Trie trie;

#define trie_null ((trie){ 0 })

void trie_add(trie* trie, char* word);
void trie_remove(trie* trie, char* word);

void trie_clear(trie* trie);
char** trie_get(trie* trie, char* word);

void trie_delete(trie* trie);

#endif /* _TRIE_H_ */
