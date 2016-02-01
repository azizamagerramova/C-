//
//  employee.c
//  as2
//
//  Created by Aziza Magerramova on 2015-02-18.
//  
//

#include "employee.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

//prints list of Employees
void printEmployee() {
    int i;
    int c=0;
    for (i=0;i<numberPersons;i++) {
        if (persons[i]->uval.flag==2) {
            c=1;
            printf("%10s %20s tel: %10s,  Age: %d, Level: %d, Salary: %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.employee.service, persons[i]->uval.employee.levelScale, persons[i]->uval.employee.salary);
        }
    }
    if (c==0)
        printf("No employee records found");
    
    menu();
}

//finds employee with given salary
void findSalary(float *salary) {
    int i;
    int c=0;
    for (i=0;i<numberPersons;i++) {
        if (persons[i]->uval.employee.salary==*salary) {
            c=1;
            printf("%10s %20s tel: %10s  Age: %d, Level: %d, Salary: %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.employee.service, persons[i]->uval.employee.levelScale, persons[i]->uval.employee.salary);
        }
    }
    if (c==0)
        printf("There is no  employee with this salary");
}

//finds employee with the given last name
void findName(char *lastname){
    int i;
    int c=0;
    for (i=0;i<numberPersons;i++) {
        if ((strcmp(lastname, persons[i]->lastName) ==0) && (persons[i]->uval.flag==2)) {
            c=1;
            printf("%10s %20s tel: %10s  Age: %d, Level: %d, Salary %.2f \n", persons[i]->firstName, persons[i]->lastName,persons[i]->phone, persons[i]->uval.employee.service, persons[i]->uval.employee.levelScale, persons[i]->uval.employee.salary);
        }
    }
    if (c==0)
        printf("There is no employee record with this last name");
}