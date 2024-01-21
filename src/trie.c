#include "trie.h"
#include <stdlib.h>
#include <stdint.h>

#define MAX_CHILD 64


typedef struct Node {
    char letter;
    uint8_t useCount;

    node* nodes[MAX_CHILD];
    size_t nodeSize;
} node;

typedef struct Trie {

    node* root;

} trie;

node* create_node(){
    node* newNode = (node*) calloc(sizeof(node), 1);
    return newNode;
}

void append_node(node* src, node* dest){
    
}

void trie_add(trie* trie, char* word){
    node* tmp = trie->root;
    if(tmp == NULL){
        trie->root = create_node();
        trie->root->letter = '*';
    }

    while(*word != '\0'){

        node* newNode = create_node();
        newNode->letter = *word;
        newNode->useCount = 1;

        word++;
    }

}
