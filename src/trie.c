#include "trie.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h> //remove on release

#define MAX_CHILD 64
#define MAX_OUTPUT_WORDS 64
#define MAX_TMP_LETTER 64 

typedef struct Node {
    char letter;
    uint8_t useCount;

    struct Node* nodes[MAX_CHILD];
    size_t nodeSize;
} node;

struct Trie {
    node* root;
};

node* create_node();
trie* trie_create(){
    trie* newTrie = (trie*) calloc(sizeof(trie), 1);
    newTrie->root = create_node();
    newTrie->root->letter = '*';
    return newTrie;
}

node* create_node(){
    node* newNode = (node*) calloc(sizeof(node), 1);
    return newNode;
}

bool append_node(node* src, node* dest){
    
    if(dest->nodeSize == MAX_CHILD) return false;
    dest->nodes[dest->nodeSize++] = src;

    return true;
}

void trie_add(trie* trie, char* word){
    node* tmp = trie->root;

    bool isNodeAdded = false;
    while(*word != '\0'){
        isNodeAdded = false;
        for(uint8_t i = 0; i < tmp->nodeSize; i++){
            if( tmp->nodes[i]->letter == *word ){
                tmp->nodes[i]->useCount++;
                tmp = tmp->nodes[i];
                isNodeAdded = true;
                break;
            }
        }
        if(isNodeAdded){ word++; continue; }

        node* newNode = create_node();
        newNode->letter = *word;
        newNode->useCount = 1;

        if( append_node(newNode, tmp) ){
            tmp = tmp->nodes[tmp->nodeSize - 1];
        }

        word++;
    }

}

void _trie_get_rec( char** words, size_t* stringSize, char* output, node* node, uint8_t depth){

    if(depth == 0){
        output = (char*) calloc(sizeof(char),MAX_TMP_LETTER);
    }

    // if(depth == 0 && node->nodeSize == 0) return;

    if(node->nodeSize == 0){
        output[depth] = node->letter;
        char* tmpOutput = (char*) calloc(sizeof(char),depth+1);
        strcpy(tmpOutput,output);
        tmpOutput[depth] = '\0';
        words[(*stringSize)++] = tmpOutput;
        return;
    }

    for(uint8_t i = 0; i < node->nodeSize; i++){
        output[depth] = node->nodes[i]->letter;
        _trie_get_rec(words, stringSize, output, node->nodes[i],depth+1);

        char* tmpOutput = (char*) calloc(sizeof(char), depth);
        strcpy(tmpOutput,output);

        // free(output);
        output = (char*) calloc(sizeof(char),MAX_TMP_LETTER);
        strcpy(output,tmpOutput);
    }

}

char** trie_get(trie* trie, char* _word, size_t* stringSize){

    *stringSize = 0;
    char** words = (char**) malloc(sizeof(char*)*MAX_OUTPUT_WORDS); // change MAX_OUTPUT_WORDS here

    bool isWordFound;
    node* tmp = trie->root;
    while(*_word != '\0'){

        isWordFound = false;
        for(uint8_t i = 0; i < tmp->nodeSize; i++){
            if(tmp->nodes[i]->letter == *_word){
                tmp = tmp->nodes[i];
                isWordFound = true;
                _word++;
                break;
            }
        }
        
        if(!isWordFound){
            break;
        }
    }

    if(tmp == trie->root || !isWordFound || tmp->nodeSize == 0){
        *stringSize = 0;
        return NULL;
    }

    _trie_get_rec(words,stringSize,NULL, tmp,0);

    return words;

}
