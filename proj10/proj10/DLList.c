/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   DAVID TYLER
   Source file for 10th programming assignment
   Contains function definitions

    ********************************************** 
	STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
    EACH FUNCTION DEFINITION BELOW, BUT SHOULD NOT
	MODIFY THE RETURN TYPE, NAME, OR ARGUMENTS OF
	ANY FUNCTION
	**********************************************

**************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

// Find node containing word
// Return pointer to node, or NULL if nothing found
DLNode *findNode(DLList *list, char *str) {

	DLNode *tmp;

    tmp=list->firstNode;
    while((tmp->next) != NULL && 0!=strcmp(tmp->word,str))
        {
            tmp=tmp->next;
        }
    if(0==strcmp(tmp->word,str))
        return tmp;
	return NULL;
}

// Add new node to list containing str
void addNode(DLList *list, char *str) {
    DLNode *newnode;
    DLNode *tmp;

    newnode=(DLNode *)malloc(sizeof(DLNode));
    tmp=(DLNode *)malloc(sizeof(DLNode));
    newnode->word=str;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(!list->firstNode)
    {
        list->firstNode=newnode;
    }
    else if(!list->lastNode)
    {
        newnode->prev=list->firstNode;
        list->firstNode->next=newnode;
        list->lastNode=newnode;
    }
    else
    {
        tmp=list->firstNode;
        while((tmp->next) != NULL && 0>strcmp(tmp->word,newnode->word))
        {
            tmp=tmp->next;
        }
        if(tmp->next != NULL)
            tmp->next->prev=newnode;
        newnode->next=tmp->next;
        tmp->next=newnode;
        newnode->prev=tmp;
    }
    printf("%s",list->firstNode->word);
    return;

}

// Delete node containing word from list if it is present
void delNode(DLList *list, char *str) {
	DLNode *tmp;
    tmp = findNode(list,str);
    if(tmp==NULL)
        return;
    if(tmp == list->firstNode)
    {
        if(tmp->next==NULL)
        {
            free(tmp);
            list->firstNode=NULL;
        }
        else
        {
            list->firstNode=tmp->next;
            list->firstNode->prev=NULL;
            free(tmp);
        }
    }
    else if(tmp==list->lastNode)
    {
        tmp->prev->next=NULL;
        if(tmp->prev!=list->firstNode)
            list->lastNode=tmp->prev;
        free(tmp);
    }
    else
    {
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        free(tmp);
    }
    return;     
}

// Print contents of list, or message
void printList(DLList *list) {
    DLNode *cur;

    if(list->firstNode==NULL)
    {
        printf("List is empty");
        return;
    }
    
    cur=list->firstNode;
    printf("%c\n",*list->firstNode->word);
    while(cur->next != NULL)
    {
        cur=cur->next;
        printf("%s\n",cur->word);
    }

    return;

}
