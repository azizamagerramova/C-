//
//  
//  as2
//
//  Created by Aziza Magerramova on 2015-02-18.
//
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"
#include "data.h"
#include "menu.h"
//prints out lst of students
void printStudent() {
    int i;
    int c=0;
    for(i=0;i<numberPersons;i++){
        if (persons[i]->uval.flag ==1) {
            c=1;
            printf("%s %s tel: %10s  GPA: %2d, Courses: %2d, Tuition: %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.student.GPA, persons[i]->uval.student.courses, persons[i]->uval.student.fees);
        }
    }
    if (c==0)
        printf("No student records found");
    
    menu();
}

//finds student with the given GPA
void findGPA(int *gpa) {
    int i;
    int c =0;
    for (i=0;i<numberPersons;i++) {
        if (persons[i]->uval.student.GPA==*gpa){
            c=1;
            printf("%s %s tel: %10s  GPA: %2d, Courses: %2d, Tuition: %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.student.GPA, persons[i]->uval.student.courses, persons[i]->uval.student.fees);
        }
    }
    if (c==0)
        printf("There is no student with this GPA");
}

//finds student with the given lastName
void findLastName(char lastName[]) {
    int i;
    int c=0;
    for (i=0;i<numberPersons;i++) {
        if ((strcmp(persons[i]->lastName, lastName)==0) &&(persons[i]->uval.flag ==1)) {
            c=1;
            printf("%s %s tel: %10s  GPA: %2d, Courses: %2d, Tuition: %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.student.GPA, persons[i]->uval.student.courses, persons[i]->uval.student.fees);
        }
    }
    if (c==0)
        printf("There is no student with this last name");
}
