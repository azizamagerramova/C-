//File name is linked_list.c


/********************************************************************************************/
// INCLUDE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/********************************************************************************************/
// Define



/*****************************************************************************************************/
/*
 Purpose: create a new node and insert it into the list as the first element
 input
 id - id of person
 firstName - first name of person
 familyName - family name of person
 
 input/output
 head - head of linked list
 
 return
 a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL
 
 */

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName) {
    PersonalInfo *newPerson;
    PersonalInfo *list;
    list = *head;
    newPerson = (PersonalInfo*)malloc(sizeof(PersonalInfo));
    newPerson->id = id;
    strcpy(newPerson->firstName, firstName);
    strcpy(newPerson->familyName, familyName);
    
    if (list->next== NULL)
        list->next = newPerson;
    else {
        newPerson->next = list->next;
        list->next = newPerson;
    }
    return newPerson;
    
}

/*****************************************************************************************************/
/*
 Purpose: create a new node and insert it into the list after the given record
 Input
 head - the head of the list
 node - the node after which the new node must be added to the list
 id - id of person
 firstName - first name of person
 familyName - family name of person
 
 
 return
 a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL
 
 */


PersonalInfo *insertAfterToList(PersonalInfo *head, PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
    PersonalInfo *newPerson;
    PersonalInfo *list;
    list = node;
    newPerson = (PersonalInfo*)malloc(sizeof(PersonalInfo));
    newPerson->id = id;
    newPerson->next=NULL;
    strcpy(newPerson->firstName, firstName);
    strcpy(newPerson->familyName, familyName);
    if (head==NULL)
        return  NULL;
    newPerson->next = node->next;
    node->next = newPerson;
    return newPerson;
}

/*****************************************************************************************************/
/*
 Purpose: create a new node and insert it into the end of the list
 Input
 head - the head of the list
 id - id of person
 firstName - first name of person
 familyName - family name of person
 
 
 return
 a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL
 
 */


PersonalInfo *insertLastToList(PersonalInfo *head, unsigned int id, char *firstName, char *familyName)
{
    PersonalInfo *temp;
    PersonalInfo *currNode;
    currNode = head;
    
    if (currNode==NULL) {
        currNode = (PersonalInfo*)malloc(sizeof(PersonalInfo));
        currNode->id = id;
        strcpy(currNode->firstName, firstName);
        strcpy(currNode->familyName, familyName);
        currNode->next = NULL;
        head = currNode;
        return currNode;
    }
    while (1) {
        if(currNode->next==NULL) {
            temp = (PersonalInfo*) malloc(sizeof(PersonalInfo));
            temp->id = id;
            strcpy(temp->familyName, familyName);
            strcpy(temp->firstName, firstName);
            temp->next =NULL;
            currNode->next = temp;
            return currNode->next;
        }
        currNode = currNode->next;
    }
    
}

/*****************************************************************************************************/
/*
 Purpose: search for the first node with the matching firstName
 Input
 head - the head of the list
 firstName - first name of person
 
 return
 a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL
 
 */


PersonalInfo *searchNode(PersonalInfo *head, char *firstName)
{
    PersonalInfo *currNode;
    currNode = head;
    
    while (1) {
        if (currNode !=NULL) {
            if (strcmp(currNode->firstName,firstName)==0)
                return currNode;
        }else {
            return currNode;
        }
        currNode = currNode->next;
    }
}

/*****************************************************************************************************/

/*
 Purpose: delete the first node with the matching firstName
 Input
 head - the head of the list
 firstName - first name of person
 
 input/output
 head - the head of the list
 
 return
 0 if no node was deleted
 1 if a node was deleted
 
 */


int deleteNode(PersonalInfo **head, char *firstName)
{
    PersonalInfo *currNode;
    PersonalInfo *nextNode;
    
    if (*head==NULL)
        return 0;
    currNode = *head;
    
    while (1) {
        if(strcmp(firstName, currNode->next->firstName)==0) {
            nextNode = currNode->next;
            
            if (nextNode->next == NULL)
                currNode->next = NULL;
            else {
                currNode->next = nextNode->next;
                free(nextNode);
                return 1; }
        }
        
        currNode = currNode->next;
        
        if (currNode == NULL)
            return 0;
    }
    return 1;
    
}

/*****************************************************************************************************/
/*
 Purpose: prints the fields of a node
 input:
 node - a pointer to a given node
 
 */


void printNode(PersonalInfo *node)
{
    printf("First name is %s   Second Name is %s   id is %d \n", node->firstName, node->familyName, node->id);
    
}

/*****************************************************************************************************/
/*
 Purpose: prints all the records in the list
 
 input
 head - the head of the list
 */


void printList(PersonalInfo *head)
{
    PersonalInfo *node;
    node = head->next;
    while (node != NULL) {
        printNode(node);
        node = node->next;
    }
}

/*****************************************************************************************************/
/*
 Purpose: counts the number of nodes in the list
 input
 head - the head of the list
 
 return
 the number of nodes in the list
 
 */


int countAllElements(PersonalInfo *head)
{
    PersonalInfo *node;
    node = head;
    int count = 0;
    while (node !=NULL) {
        count ++ ;
        node = node->next;
    }
    return count-1;
}

/*****************************************************************************************************/
/*
 Purpose: counts the number of nodes in the list with a matching firstName
 input
 head - the head of the list
 
 return
 the number of nodes in the list that match the firstName
 
 
 */


int countElements(PersonalInfo *head, char *firstName)
{
    PersonalInfo *node;
    node = head;
    int count= 0;
    while (node !=NULL) {
        if (strcmp(firstName, node->firstName)==0) {
            count ++;
        }
        node = node->next;
    }
    return count;
}

/*****************************************************************************************************/
/*
 Purpose: deletes all nodes from the list
 input/output
 head - the head of the list
 
 
 */


void deleteList(PersonalInfo **head)
{
    PersonalInfo *node;
    PersonalInfo *nextNode;
    node = *head;
    while (1) {
        if (node == NULL)
            return;
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
}

/*****************************************************************************************************/
/*
 Purpose: merges two lists into a single list in a sorted order
 
 input
 headList1 - the head of the first list.  All nodes in the list are arranged in increasing order of firstName
 headList2 - the head of the second list.  All nodes in the list are arranged in increasing order of firstName
 
 output
 outList - the output list which contains all the elements in headList1 and headList2 in increasing orer of firstName
 
 */






void mergeList(PersonalInfo *headList1, PersonalInfo *headList2, PersonalInfo **outHead)
{
}

/*****************************************************************************************************/
/*
 
 Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name
 
 input
 head - the head of the  list
 
 
 
 */




void removeDuplicates(PersonalInfo *head)
{
    PersonalInfo *headList = head;
    PersonalInfo *currNode = head->next;
    
    while(1) {
        if ((currNode!=NULL) && (currNode->next!=NULL)) {
            if (strcmp(currNode->firstName, currNode->next->firstName) == 0) {
                deleteNode(&headList, currNode->firstName);
                currNode=currNode->next;
            }
            
            else if (strcmp(currNode->firstName, currNode->next->firstName) != 0)
                currNode=currNode->next;
            
        }
        else
            break;
    }
    
}