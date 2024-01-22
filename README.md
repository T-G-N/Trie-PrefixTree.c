# autoComplete-in-c
Prefix Tree (Trie) Implementation in C

In computer science, a trie, also called digital tree or prefix tree, it is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key (to recover its value, change it, or remove it), the trie is traversed depth-first, following the links between nodes, which represent each character in the key.

![Trie_Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/b/be/Trie_example.svg/250px-Trie_example.svg.png)

---
## Example
```c
#include "trie.h"

int main(void){

    /* Creating New Trie Object */
    trie* newTrie = trie_create();

    /* Adding The Words */
    trie_add( newTrie,"manoj!" );
    trie_add( newTrie,"manojTGN" );
    trie_add( newTrie,"manoj-trie" );

    /* Getting The Words */
    size_t resultSize = 0;
    char** result = trie_get( newTrie, /*get autocomplete for this word*/ "mano", &resultSize);

    /* Printing The Result */
    for(int i = 0; i < resultSize; i++){
        printf("%s %s\n","mano",result[i]);
    }

    /* Free */
    trie_delete(newTrie);

    return 0;
}
```
### Output
```bash
mano j!
mano jTGN
mano j-trie
```
---
## Demo Video
![trie_autoComplete](https://github.com/T-G-N/autoComplete-in-c/assets/42494649/83ddc667-1741-4437-9d2e-7302a8b6ddeb)

