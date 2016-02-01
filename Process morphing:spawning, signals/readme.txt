****Written by Aziza Magerramova on April 1st 2015**
-Second part of this software takes a single positive integer as an input, and prints in console if it's prime or not. Program forks the child process, that morphs to the other program, that morphs to the program which returns if the number is prime or not.
-Third part of this software takes as input a set of positive numbers, spawns a child process for every number that morphs to the program, which returns if number is prime or nor. 
-Be aware that third part of the software takes as input up to 10 numbers, if there are more than 10, it will execute first 10. 

**Compile and running instructions**
---If you want to test task I compile Makefile, by inputting in terminal: make
and then run it as: ./morph number, where number is a positive integer.

---To test task II compile Makefile2 as: make -f Makefile2
-run: ./singlePrime number, where number is a positive integer

---To test task III compile Makefile3 as: make -f Makefil3
-run ./multiple numbers, where numbers is a set of positive integers. 

**Files**
--There are 3 makefiles: Makefile, Makefile2 and Makefile3, each for every part of the software. 
—-There are 3 .c files for the first part of the program: isPrime.c, morph.c and main_morph.c
—-There are 3 files for the second part of the program: isPrime.c, morph.c and singlePrime.c
—-There are 3 files for the third part of the program: isPrime.c, morph.c and multiple.c