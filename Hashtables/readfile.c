//
//  readfile.c
//  Hashtables
//
//  Created by Richard Hong on 1/28/15.
//  Copyright (c) 2015 Richard Hong. All rights reserved.
//

#include "readfile.h"


/*
 * Use this code to read a text file.
 *
 * To read from a file "input.txt", first call file_initialize("input.txt").
 * The function will return 1 if the file was opened successfully, and 0
 * if an error occurred.
 *
 * Once the file is open, call file_read_next() to read the next word. The
 * function returns a char* to the next word of the file, and returns NULL
 * when the end of the file is reached.
 *
 * Note that there is an assumption that each word in the file is less than
 * 256 characters long.
 *
 * Note that this implementation only allows you to read one file at a time.
 * To read another file, simply call file_initialize again (with the name
 * of the file to read). Or modify this code. =)
 */

#include <stdio.h>
#include <stdlib.h>

FILE *infile;

int file_initialize(char* name)
{
    if (name == NULL) {
        printf("Error! File name provided to file_initialize is null\n");
        return 0;
    }
    infile = fopen(name, "r");
    if (infile == NULL) {
        printf("Error! Could not open file \"%s\" for reading\n", name);
        return 0;
    }
    else return 1;
}

char file_word[500];

char* file_read_next()
{
    if(fscanf(infile,"%s",file_word) == EOF) return NULL;
    return file_word;
    //printf("word: %s\n", file_word);
}
