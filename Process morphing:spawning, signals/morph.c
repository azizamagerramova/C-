//
//  morph.c
//  as4
//
//  Created by Aziza on 2015-03-29.
//  Copyright (c) 2015 Aziza. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

//if you want to test it, use Makefile or
//alternatively compile it as: gcc main_morph.c morph.c -o morph
//then run: ./morph 
  	
void Morph(char*);

//function that morphes itself into isPrime programm
void Morph(char *number) {
    char *args[80];
    args[1] = number;
    args[2] = NULL;
    int rc = execv("./isPrime", args);
    printf("rs=%d", rc);
}
