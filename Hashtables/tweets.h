//
//  hashtable.h
//  LabHashTables
//
//  Created by Richard Hong on 1/22/15.
//  Copyright (c) 2015 Richard Hong. All rights reserved.
//

#ifndef __LabHashTables__hashtable__
#define __LabHashTables__hashtable__

#include <stdio.h>

// the initial capacity (number of buckets)
#define CAPACITY 100

typedef struct Node node;
struct Node {
    char* value;
    int occurences;
    node* next; // next node in the list
};

typedef struct Hashtable hashtable;
struct Hashtable {
    node* list[CAPACITY]; // "buckets" of linked lists
};

/* Function prototypes */
node* getNode(char* string, hashtable* h);
long unsigned hash(char*);
int put(char*, hashtable*);
int get(char*, hashtable*);

#endif /* defined(__LabHashTables__hashtable__) */
