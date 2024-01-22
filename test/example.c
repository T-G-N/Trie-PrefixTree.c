#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include "../src/trie.h"

void getWords(trie* newTrie, char word[64]){
    size_t arrSize = 0;
    
    char** words = trie_get(newTrie,word,&arrSize);
    for(int i = 0; i < arrSize; i++){
        printf("%s[%s]\n",word,words[i]);
    }

    if(arrSize == 0){
        printf("Found 0 AutoCompletion.\n");
    }
}

int main(void){
    trie* newTrie = trie_null;
    newTrie = trie_create();

    trie_add(newTrie,"whatTheFuck");
    trie_add(newTrie,"whatYouWant");
    trie_add(newTrie,"whaa!");
    trie_add(newTrie,"whooray");
    trie_add(newTrie,"whatYouNeed");
    trie_clear(newTrie);

    trie_add(newTrie,"helloWorld");
    trie_add(newTrie,"helloManoj");
    trie_add(newTrie,"helloTGN");
    trie_add(newTrie,"helo");

    trie_remove(newTrie,"helo");

    system("cls");
    printf("Start Typing...");
    
    char input = 0;
    char str[32*2] = "";

    uint8_t index = 0;
    while(1){
        if (kbhit()) {
            
            input = getch();
            if(input == '\b' && index == 0) continue;

            if(input == '\n' || input == 27){ //27 - ESC
                break;
            }

            
            if(input == 8 && index > 0){
                str[--index] = 0;
            }else if(input != '\b'){
                str[index] = input;
                str[index+1] = 0;
            }
            

            system("cls");
            printf("%s\n--------------------\n",str);
            getWords(newTrie,str);
            printf("--------------------\n");

            if(input != 8)
            index++;
        }
    }

    return 0;
}