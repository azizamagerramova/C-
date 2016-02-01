

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"


int main(int argc, char* argv[])
{
    
    struct personalInfo *empHead = malloc(sizeof(PersonalInfo));
    //struct personalInfo *final = malloc(sizeof(PersonalInfo));
    insertToList(&empHead, 86700, "Antony", "dkle");
    PersonalInfo *bred = insertLastToList(empHead, 202020, "Bred", "Li");
    insertLastToList(empHead, 86700, "FRED", "Altor");
    insertLastToList(empHead, 86700, "FRED", "Altor");
    insertLastToList(empHead, 86700, "Tuj", "Altor");
    insertLastToList(empHead, 56788, "Red", "Green");
    insertLastToList(empHead, 56788, "Red", "Green");
    printf("Number of Freds in the list is %d\n", countElements(empHead, "FRED"));
    //printList(empHead);
    removeDuplicates(empHead);
    deleteNode(&empHead, "Tuj");
    insertAfterToList(empHead, bred, 67844, "Liam", "Lesli");
    printList(empHead);
    printf("Searching for the node: \n");
    printNode(searchNode(empHead, "Liam"));
    printf("Number of elements in the list: %d\n", countAllElements(empHead));
    deleteList(&empHead);
    return 0;
}


