//
//  data.h
//  as2
//
//  Created by Aziza Magerramova on 2015-02-18.
//  
//

typedef struct{
    float salary;
    unsigned int service: 6;
    unsigned int levelScale: 4;
}employee;

typedef struct{
    unsigned int GPA: 5;
    float fees;
    unsigned int courses: 6;
    
}student;

typedef struct {
    struct {
        union {
        student student;
        employee employee;
        };
        unsigned int flag;
    }uval;
    char firstName[10];
    char lastName[20];
    char phone[10];
}person;

int numberPersons;
person *persons[20];