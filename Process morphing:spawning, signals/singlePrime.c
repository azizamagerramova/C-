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

//takes command line argument, checks if there's a number, 
//and if yes, forks itself, and then parent process
// using Morph function, morphs itself into isPrime.c
int main(int argc, char *argv[]) {
    char userMax[80];
    int pid, rc;
    if (argv[1] == NULL) { //checks command line input
        printf("You should input a positive integer!");
            exit(0);
    }
    strcpy(userMax, argv[1]);
    pid = fork();
    if (pid==0) { //if it's child process
        Morph(userMax);
    } else if (pid > 0) { //if parent process
	    int status;
	    wait(&status); //let child process to finish executing
            if (WIFEXITED(status) != 0) { 
                if (WEXITSTATUS(status) == 1){  //chek the return of Morph
                    printf("%s is a prime number", argv[1]);
		}
                if (WEXITSTATUS(status) == 0){
                    printf("%s is not a prime number", argv[1]);
		}
            }
            
                }
    return 1;
    
}
