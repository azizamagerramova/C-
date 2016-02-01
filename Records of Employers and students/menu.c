//
//  menu.c
//  as2
//
//  Created by Aziza Magerramova on 2015-02-18.
// 
//

#include "menu.h"
#include "data.h"
#include "student.h"
#include "employee.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//displays user oprions he has
int menu() {
    int choice = -1;
    char str[20];
    //check if choice is valid
    while (choice<0 || choice>9) {
        printf("\nYou may:\n");
        printf("1. Add a new Record\n");
        printf("2. Print Student list\n");
        printf("3. Print employee list\n");
        printf("4. Find student using GPA\n");
        printf("5. Find student using Family Name\n");
        printf("6. Find employees using salary\n");
        printf("7. Find employees using Family Name \n");
        printf("8. Summary of Data \n");
        printf("9. Find max GPA using pointers \n");
        printf("0. Quit\n");
        fgets(str, sizeof(str), stdin);
        sscanf(str,"%d", &choice);
        if (choice<0 || choice >9)
            printf("Invalid option\n");
        
        if (choice>=0 && choice<=9)
            break;
        
    }
    //respond to user choice
    switch (choice) {
        case 1:
            AddNewRecord();
        case 2:
            printStudent();
        case 3:
            printEmployee();
        case 4:
            RecordGPA();
        case 5:
            familyNameStu();
        case 6:
            recordSalary();
        case 7:
            familyNameEm();
        case 8:
            summary();
        case 0:
            userWantsQuit();
    }
    
    return choice;
    
}
//prints out summary
void summary() {
    float summaryGpa=0;
    int n=0;
    int i;
    float courses=0;
    float fee=0;
    int maxlevel=1;
    int minlevel=15;
    float age=0;
    float salary=0;
    
    printf("Total number of records are %d\n", numberPersons);
    printf("Student Stats:\n");
    for (i=0;i<numberPersons;i++) {
        if (persons[i]->uval.flag==1) {
            summaryGpa = summaryGpa+(persons[i]->uval.student.GPA);
            courses = courses+persons[i]->uval.student.courses;
            fee = fee +persons[i]->uval.student.fees;
            n++;
        }
    }
    printf("Total number of students are %d\n", n);
    printf("Average GPA: %.2f, Average Number of courses: %.2f, Average Tution Fee: %.2f\n", summaryGpa/n, courses/n, fee/n);
    printf("Employees Stats: \n");
    n=0;
    for (i=0;i<numberPersons;i++) {
        if (persons[i]->uval.flag==2) {
            n++;
            age = persons[i]->uval.employee.service + age;
            salary =persons[i]->uval.employee.salary + salary;
            if (persons[i]->uval.employee.levelScale > maxlevel)
                maxlevel = persons[i]->uval.employee.levelScale;
            if (persons[i]->uval.employee.levelScale < minlevel)
                minlevel = persons[i]->uval.employee.levelScale;
            
        }
    }
    printf("Number of Employees: %d\n", n);
    printf("Max Level: %d, Min Level: %d\n", maxlevel, minlevel);
    printf("Average Age: %.2f, Average Salary: %.2f\n", age/n, salary/n);
    menu();
    
    
}

//check if user wants to quit
void userWantsQuit() {
    char answer;
    fseek(stdin,0,SEEK_END);
    printf("Do you really want to exit? (y,n) \n");
    answer = getchar();
    if (answer == 'y' || answer == 'Y') {
        exit(0);
    }
    else
        menu();
}

//find employeer by last name
void familyNameEm() {
    int valid;
    char lastName[20];
    int i;
    
    fseek(stdin,0,SEEK_END);
    valid = 0;
    while (valid==0) {
        printf("Enter last name to find employee: \n");
        fgets(lastName, 20, stdin);
        for (i=0;i<(strlen(lastName)-1);i++) {
            valid = isLetter(&lastName[i]);
            if (valid==0) {
                printf("Your input is incorrect! It should consist only from English letters. Example: Brown \n");
                break;
            }
        }
    }
    findName(lastName);
    menu();
}

//find employee by salary
void recordSalary() {
    char str[20];
    float salary;
    int valid = 0;
    while (valid ==0) {
        fseek(stdin,0,SEEK_END);
        printf("Enter employee record. Enter salary");
        fgets(str, sizeof(str), stdin);
        sscanf(str,"%f", &salary);
        valid=isFloat(str);
        if (valid==1)
            sscanf(str,"%f", &salary);
        else {
            printf("Your input is incorrect! It should consist only from digits 0-9 and '.'. Example: 2000.6 \n");
            break;
        }
    }
    findSalary(&salary);
    menu();
}

//find student by last name
void familyNameStu(){
    int valid;
    char lastName[20];
    int i;
    
    fseek(stdin,0,SEEK_END);
    valid = 0;
    while (valid==0) {
        printf("Enter last name to find student: \n");
        fgets(lastName, 20, stdin);
        for (i=0;i<(strlen(lastName)-1);i++) {
            valid = isLetter(&lastName[i]);
            if (valid==0) {
                printf("Your input is incorrect! It should consist only from English letters. Example: Brown \n");
                break;
            }
        }
    }
    findLastName(lastName);
    menu();
}

//find student by GPA
void RecordGPA(){
    int valid=0;
    int GPA;
    char str[5];
    int i;
    
    while (valid ==0) {
        fseek(stdin,0,SEEK_END);
        printf("Enter GPA to find studetn\n");
        fgets(str, sizeof(str), stdin);
        for (i=0; i<(strlen(str)-1);i++) {
            valid = isInt(&str[i]);
            if (valid==1) {
                sscanf(str,"%d", &GPA);
                if (GPA <=10)
                    valid = 1;
                else {
                    valid=0;
                    printf("Your input is incorrect! It should only be a digit 0-10. Example: 9 \n");
                }
            }
            else {
                printf("Your input is incorrect! It should only be a digit 0-10. Example: 9 \n");
                break;
            }
        }
    }
    
    findGPA(&GPA);
    menu();
}

//add new record
void AddNewRecord() {
    student newStudent;
    employee newEmployee;
    person newPerson;
    char str[20];
    char firstName[10];
    char lastName[20];
    char phone[10];
    int valid = 0;
    char answer;
    unsigned int GPA = 0;
    unsigned int courses = 0;
    int i;
    float fees = 0.0;
    float salary = 0.0;
    unsigned int service = 0;
    unsigned int levelScale =0;
    
    
    while (valid==0) {
        printf("Enter first name: \n");
        fgets(firstName, sizeof(firstName), stdin);
        for (i=0;i<(strlen(firstName)-1);i++) {
            valid = isLetter(&firstName[i]);
            if (valid==0) {
                printf("Your input is incorrect! It should consist only from English letters. Example: Dan \n");
                break;
            }
        }
    }
    fseek(stdin,0,SEEK_END);
    valid = 0;
    while (valid==0) {
        printf("Enter last name: \n");
        fgets(lastName, 20, stdin);
        for (i=0;i<(strlen(lastName)-1);i++) {
            valid = isLetter(&lastName[i]);
            if (valid==0) {
                printf("Your input is incorrect! It should consist only from English letters. Example: Brown \n");
                break;
            }
        }
    }
    fseek(stdin,0,SEEK_END);
    valid = 0;
    while (valid == 0) {
        printf("Enter a phone number: \n");
        fgets(phone, 10, stdin);
        if ((phone[0] == 0) || (phone[0]==1)) {
            valid = 0;
            printf("Your input is incorrect! It should consist only from digits 0-9. Example: 6132653563 \n");
            break;
        }
        else {
            for (i=0; i<(strlen(phone)-1);i++) {
                valid = isInt(&phone[i]);
                
                if (valid==0) {
                    printf("Your input is incorrect! It should consist only from digits 0-9. Example: 6132653563 \n");
                    break;
                }
            }
        }
        
    }
    fseek(stdin,0,SEEK_END);
    printf("Do you want to enter a student record?(y/n)");
    answer = getchar();
    valid = 0;
    if ((answer == 'y') ||(answer == 'Y'))  {
        while (valid ==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter GPA\n");
            fgets(str, sizeof(str), stdin);
            for (i=0; i<(strlen(str)-1);i++) {
                valid = isInt(&str[i]);
                if (valid==1) {
                    sscanf(str,"%d", &GPA);
                    if (GPA <=10)
                        valid = 1;
                    else {
                        valid=0;
                        printf("Your input is incorrect! It should only be a digit 0-10. Example: 9 \n");
                    }
                }
                else {
                    printf("Your input is incorrect! It should only be a digit 0-10. Example: 9 \n");
                    break;
                }
            }
        }
        valid=0;
        while (valid ==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter tution Fees\n");
            fgets(str, sizeof(str), stdin);
            sscanf(str,"%f", &fees);
            valid=isFloat(str);
            if (valid==1)
                sscanf(str,"%f", &fees);
            else {
                printf("Your input is incorrect! It should consist only from digits 0-9 and '.'. Example: 2000.6 \n");
                break;
            }
        }
        valid=0;
        
        while(valid==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter number of courses\n");
            fgets(str, sizeof(str), stdin);
            for (i=0; i<(strlen(str)-1);i++) {
                valid = isInt(&str[i]);
                if (valid ==1) {
                    sscanf(str,"%d", &courses);
                    if (courses<=40)
                        valid=1;
                    else {
                        valid=0;
                        printf("Your input is incorrect! It should consist only from digits 0-9 and '.'. Example: 3 \n");
                    }
                }
                
                else {
                    printf("Your input is incorrect! It should consist only from digits 0-9 and '.'. Example: 3 \n");
                    break;
                }
                
            }
        }
        newStudent.GPA = GPA;
        newStudent.courses = courses;
        newStudent.fees = fees;
        newPerson.uval.flag = 1;
        newPerson.uval.student = newStudent;
        strcpy(newPerson.firstName, firstName);
        strcpy(newPerson.lastName, lastName);
        strcpy(newPerson.phone, phone);
        
    }
    else if ((answer == 'n') ||(answer == 'N')) {
        valid = 0;
        while (valid ==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter employee record. Enter salary");
            fgets(str, sizeof(str), stdin);
            sscanf(str,"%f", &salary);
            valid=isFloat(str);
            if (valid==1)
                sscanf(str,"%f", &salary);
            else {
                printf("Your input is incorrect! It should consist only from digits 0-9 and '.'. Example: 2000.6 \n");
                break;
            }
        }
        valid =0;
        while (valid ==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter years of service\n");
            fgets(str, sizeof(str), stdin);
            for (i=0; i<(strlen(str)-1);i++) {
                valid = isInt(&str[i]);
                if (valid==1) {
                    sscanf(str,"%d", &service);
                    if (service <=63)
                        valid = 1;
                    else {
                        valid=0;
                        printf("Your input is incorrect! It should only be a digit 0-63. Example: 9 \n");
                    }
                }
                else {
                    printf("Your input is incorrect! It should only be a digit 0-63. Example: 9 \n");
                    break;
                }
            }
        }
        valid =0;
        while (valid ==0) {
            fseek(stdin,0,SEEK_END);
            printf("Enter salary level scale range \n");
            fgets(str, sizeof(str), stdin);
            for (i=0; i<(strlen(str)-1);i++) {
                valid = isInt(&str[i]);
                if (valid==1) {
                    sscanf(str,"%d", &levelScale);
                    if (1<=levelScale <=15)
                        valid = 1;
                    else {
                        valid=0;
                        printf("Your input is incorrect! It should only be a digit 1-15. Example: 9 \n");
                    }
                }
                else {
                    printf("Your input is incorrect! It should only be a digit 1-15. Example: 9 \n");
                    break;
                }
            }
        }
        newEmployee.service = service;
        newEmployee.salary = salary;
        newEmployee.levelScale = levelScale;
        newPerson.uval.employee = newEmployee;
        newPerson.uval.flag = 2;
        strcpy(newPerson.firstName, firstName);
        strcpy(newPerson.lastName, lastName);
        strcpy(newPerson.phone, phone);
        
        
    }
    
    if (persons[0] == NULL) {
        persons[0] = &newPerson;
        numberPersons++;
    }
    else {
        *(persons+numberPersons) = &newPerson;
        numberPersons++;
    }
    
    menu();
}

//checks if char is int
int isInt(char *s){
    int check = 0;
    if ((*s == '0') || (*s=='1') || (*s=='2') || (*s=='3') || (*s=='4') || (*s=='5') || (*s=='6') || (*s=='7') || (*s=='8') || (*s=='9')) {
        check =1;
    }
    
    return check;
}

//checks if char is letter
int isLetter(char *s) {
    int check=0;
    if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) {
        check = 1;
    }
    return check;
}

//check if char is float
int isFloat(char *s) {
    int check =0;
    if ((*s == '0') || (*s=='1') || (*s=='2') || (*s=='3') || (*s=='4') || (*s=='5') || (*s=='6') || (*s=='7') || (*s=='8') || (*s=='9') || (*s=='.')) {
        check=1;
    }
    return check;
}


