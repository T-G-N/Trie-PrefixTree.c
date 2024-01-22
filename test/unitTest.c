#include <stdio.h>
#include <assert.h>
#include "../src/trie.h"

int main(void){

    trie* new_trie = trie_create();
    trie_add(new_trie, "hello");
    trie_add(new_trie, "hi");
    
    size_t arrSize = 0;
    char** words = trie_get(new_trie,"h",&arrSize);
    
    assert(arrSize == 2);
    assert(words[0] == "ello");
    assert(words[1] == "i");

    return 0;
}