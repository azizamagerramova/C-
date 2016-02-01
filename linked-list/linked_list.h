
/* 
File name is linked_list.h

*/


#ifndef LINKED_LIST_2401
#define LINKED_LIST_2401 1

#define NAME_LENGTH 32

typedef struct personalInfo {
	struct personalInfo *next;
	unsigned int id;		
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
} PersonalInfo;

// Part I
PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName);
PersonalInfo *insertAfterToList(PersonalInfo *head, PersonalInfo *node, unsigned int id, char *firstName, char *familyName);
PersonalInfo *insertLastToList(PersonalInfo *head, unsigned int id, char *firstName, char *familyName);
PersonalInfo *searchNode(PersonalInfo *head, char *firstName);
int deleteNode(PersonalInfo **head, char *firstName);
void printNode(PersonalInfo *node);
void printList(PersonalInfo *head);
int countAllElements(PersonalInfo *head);
int countElements(PersonalInfo *head, char *firstName);
void deleteList(PersonalInfo **head);


// Part II

void mergeList(PersonalInfo *headList1, PersonalInfo *headList2, PersonalInfo **outHead);
void removeDuplicates(PersonalInfo *head);

#endif