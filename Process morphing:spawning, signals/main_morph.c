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
#include <signal.h>

//program to test morph.c, takes input and passes it in morph program
int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
	printf("You shoulf input positive integer!");
        exit(0);
	}
	
    Morph(argv);
    
}
