#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count =0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	char* string = (char*)calloc(length(head),sizeof(char));
	while(head!=NULL){
		strcat(string,&head->letter);
		head = head->next;
	}
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = *pHead;
	node* newNode = calloc(1,sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	if(*pHead==NULL){
		*pHead=newNode;
	}else{
		temp = *pHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	}
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	int count = length(*pHead);
	node* temp = *pHead;
	for(int i = 0;i<count;i++){
		*pHead = (*pHead)->next;
		free(temp);
		temp = *pHead;
	}

}

int main(void)
{
	int a = 5;
	int b = a++;
	int c = ++a;
	printf("%d,%d,%d",a,b,c);
}