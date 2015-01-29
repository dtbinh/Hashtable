//
//  main.c
//  Hashtables
//
//  Created by Richard Hong on 1/26/15.
//  Copyright (c) 2015 Richard Hong. All rights reserved.
//

#include <stdio.h>
#include "tweets.h"
#include "readfile.h"
#include <stdlib.h>
#include <string.h>

void exit();
int strncmp(const char *, const char *, unsigned long a);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    if(file_initialize("tweets.txt") == 1){
        
    }else{
        exit(1);
    }
    char *word;
    hashtable *h1 = (hashtable*) malloc(sizeof(hashtable));
    do{
        word = file_read_next();
        if(word == NULL) break;
        if(strncmp("#", word, strlen("#")) == 0){
            put(word, h1);
        }
    }while(word != NULL);
    
    node *result[CAPACITY];
    int i;
    node *maxNode;
    for(i = 0; i < (sizeof(h1->list) / sizeof(h1->list[0])); i++){
        node *n = h1->list[i];
        maxNode = n;
        while(n != NULL){
            //printf("%s %d \n", n->value, n->occurences);
            if(maxNode->occurences < n->occurences){
                maxNode = n;
            }
            n = n->next;
        }
        result[i] = maxNode;
    }
    node *tempNode;
    for(i = 0; i < (sizeof(result) / sizeof(result[0])); i++){
        for(int x = i; x < (sizeof(result) / sizeof(result[0])); x++){
            if(result[i]->occurences < result[x]->occurences){
                tempNode = result[i];
                result[i] = result[x];
                result[x] = tempNode;
            }
        }
    }
    
    for(i = 0;i < 10; i++){
        printf("%s: %d \n", result[i]->value, result[i]->occurences);
    }
    
    return 0;
}
