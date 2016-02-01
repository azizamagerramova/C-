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

int count=0;
//takes input as a set of numbers
//checks if there's at least of number there
//forks multiple processes, which morph theirselfs in isPrime, using morph program

int main(int argc, char *argv[]) {
    int i, d, pid, status;
    int check = 0;
    int pids[11];
    
    char input[40];
    if (11<argc) { //check how many numbers are in input
	printf("Warning: More than 10 numbers received! Program will execute only 10 numbers\n");
        argc=11;
	
}
        
    
    for (i=1;i<argc;i++){
        if (argv[i] != NULL) {
            check =1;
        }
    }
    
    if (check == 0) {
        printf("You should input a positive integer!");
        exit(0);
    }
    
    for (i=1;i<argc;i++) {
        pid = fork();
        if (pid == 0) {
            Morph(argv[i]);
            printf("It should not be printed");
        }
        else {
            waitpid(-1, &status, 0);
	    count++;
            pids[i] = WEXITSTATUS(status);
            
        }
    }
    
    if (waitpid(-1, &status, 0)==-1) {
        check =0;
        printf("Prime numbers are: ");
        for (i=1;i<argc;i++) {
            if (pids[i]==1) {
                check =1;
                printf("%s ", argv[i]);
            }
        }
        if (check ==0)
            printf("No prime numbers");
        exit(0);
    }
    
}
