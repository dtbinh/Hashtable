//
//  hashtable.c
//  LabHashTables
//
//  Created by Richard Hong on 1/22/15.
//  Copyright (c) 2015 Richard Hong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tweets.h"

/*
 * For the given string refered to by the pointer "string",
 * calculate the hashcode and update the variable pointed to by "value".
 *
 * Return 1 if successful, and 0 if an error occurred
 * (e.g. if the string is null).
 */
long unsigned hash(char* string)
{
    if(string == NULL) return -1;
    int i;
    long unsigned sum = 0;
    for(int i = 0; string[i]; i++){
        string[i] = tolower(string[i]);
    }
    for(i = 0; i < strlen(string); i++){
        sum += string[i];
    }
    return sum;
}


/*
 * Add the string to the hashtable in the appropriate "bucket".
 *
 * Return 1 if successful, and 0 if an error occurred
 * (e.g. if the string is null, if memory could not be allocated,
 * or if the string is already in the hashtable).
 */
int put(char* string, hashtable* h)
{
    long unsigned hashcode = hash(string);
    int bucket_num = hashcode % CAPACITY;
    node* head = h->list[bucket_num];
    //printf("%d %s \n", hashcode, string);
    //check if it exists
    node *existingNode = getNode(string, h);
    if(existingNode != NULL){
        existingNode->occurences++;
    }else{
        node *new = (node*) malloc(sizeof(node)); //allocating space
        if(new == NULL) return 0;
        new->value = malloc(strlen(string) + 1);
        if(new->value == NULL) return 0;
        strcpy(new->value, string);
        new->occurences = 1;
        new->next = head;
        h->list[bucket_num] = new; //head = new doesn’t work because it’s a stack, you need to change the global variable
    }
    
    return 1;
}


/*
 * Determine whether the specified string is in the hashtable.
 * Return 1 if it is found, 0 if it is not (or if it is null).
 */

node* getNode(char* string, hashtable* h){
    // 1. get the hash code
    unsigned long hashcode = hash(string);
    // 2. determine the bucket number
    int index = hashcode % CAPACITY;
    // 3. look through the linked list     // starting with the head
    node *n = h->list[index];

    while (n != NULL) {
        //if(n->value == NULL) return NULL;
        
        if (strcmp(n->value, string) == 0) {
            return n;
            break;
        } else{
            n = n->next;
        }
    }
    return NULL;
}

int get(char* string, hashtable* h)
{
    // 1. get the hash code
    unsigned long hashcode = hash(string);
    // 2. determine the bucket number
    int index = hashcode % CAPACITY;
    // 3. look through the linked list     // starting with the head
    node *n = h->list[index];

    while (n != NULL) {
        if (strcmp(n->value, string) == 0) {
            return 1;
        } else{
            n = n->next;
        }
        // if we made it here, we didn’t find it
        return 0;
    }
    return 0;
}



