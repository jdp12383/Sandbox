/*
 * Compile:
 * gcc -o linked-list.o linked-list.c
 *
 * Time complexity:
 * insert:
 * 		at the start - O(1)
 * 		at the end - O(n)
 * 		in between - O(n)
 * delete: O(n)
 * read: O(n)
 * length: O(n)
 * modify: O(n)
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS				1
#define ERR_EMPTY			-1
#define ERR_INVALID_INDEX	-2

struct node {
	int data;
	struct node* next;
};
typedef struct node node_t;

int prepend(node_t**, int);
int append(node_t*, int);
int insertat(node_t**, int, int);
int delete_last(node_t*);
int delete_first(node_t**);
int deleteat(node_t**, int);
int length(node_t*);
void print(node_t*);

void main(int argc, char *argv[]){
	node_t* head=NULL;

	prepend(&head, 2);
	print(head);
	prepend(&head, 3);
	print(head);
	prepend(&head, 5);
	print(head);
	append(head, 6);
	print(head);
	append(head, 7);
	print(head);
	//remove_last(head);
	deleteat(&head, length(head)-1);
	print(head);
	//remove_first(&head);
	deleteat(&head, 0);
	print(head);
	deleteat(&head, 0);
	print(head);
	deleteat(&head, 0);
	print(head);
	deleteat(&head, 0);
	print(head);
	insertat(&head, 8, 0);
	print(head);
	insertat(&head, 9, length(head));
	print(head);
	deleteat(&head, length(head)-1);
	print(head);
	deleteat(&head, length(head)-1);
	print(head);
}

/**
 * insert node at the start of the list
 */
int prepend(node_t** head, int value){

	//create a new node and assign value
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = value;
	newNode->next = NULL;

	//link this new node with the head node
	if(*head != NULL){
		newNode->next = *head;
	}

	//make this new node the new head node
	*head = newNode;

	return SUCCESS;
}

/**
 * insert node at the end of the list
 */
int append(node_t* head, int value){

	//iterate through the list to find the last node
	node_t* current=head;
	while(current->next != NULL){
		current=current->next;
	}

	//create a new node and link it with the end node
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data=value;
	newNode->next=NULL;
	current->next=newNode;

	return SUCCESS;
}

/**
 * insert node at the specified index
 */
int insertat(node_t** head, int value, int index){
	node_t* newNode=(node_t*)malloc(sizeof(node_t));
	newNode->data=value;
	newNode->next=NULL;

	// this handles both the cases when list is empty
	// and when there is only head node
	if(index <= 0){
		newNode->next=(*head);
		*head=newNode;
		return SUCCESS;
	}

	// traverse through the list to find the node
	// before the index location
	node_t* current=*head;
	for(int idx=0;idx < index-1;idx++){
		if(current->next == NULL){
			return ERR_INVALID_INDEX;
		}
		current=current->next;
	}

	// now current points to the node after which the new node to be inserted
	// so assign the current node's link to the new node and
	// change current node's link to the new node
	newNode->next=current->next;
	current->next=newNode;

	return SUCCESS;
}

/**
 * remove the node from the end of the list
 */
int delete_last(node_t* head){
	if(head == NULL){
		return ERR_EMPTY;
	}

	int ret = head->data;

	// if there is only one item in the list
	if(head->next == NULL){
		free(head);
		return ret;
	}

	// traverse till the 2nd from last node
	node_t* current=head;
	while(current->next->next != NULL){
		current=current->next;
	}

	// current is now pointing to 2nd last node
	ret=current->next->data;
	free(current->next);
	current->next=NULL;

	return ret;
}

/**
 * remove the node from the start of the list
 */
int delete_first(node_t** head){
	if(*head == NULL){
		return ERR_EMPTY;
	}

	int ret = (*head)->data;
	node_t* nextNode=(*head)->next;
	free(*head);

	*head=nextNode;

	return ret;
}

int deleteat(node_t** head, int index){
	int ret;
	if(*head==NULL){
		return ERR_EMPTY;
	}

	//if the index to be deleted is the 1st node
	if(index <= 0){
		ret = (*head)->data;
		node_t* nextNode=(*head)->next;
		free(*head);

		*head=nextNode;

		return ret;
	}

	// traverse through the list to find the node
	// before the index location
	node_t* current=*head;
	for(int idx=0;idx < index-1;idx++){
		if(current->next == NULL){
			return ERR_INVALID_INDEX;
		}
		current=current->next;
	}

	// now current points to the node before the one to be deleted
	// so save the next element link and assign it to previous node
	// which is current's next
	node_t* tobedeleted=current->next;
	ret =tobedeleted->data;
	current->next=tobedeleted->next;
	free(tobedeleted->next);

	return ret;
}

int length(node_t* head){
	int count = 0;
	while(head != NULL){
		count++;
		head=head->next;
	}
	return count;
}

void print(node_t* head){
	if(head==NULL){
		printf("\nlist is empty");
		return;
	}
	printf("\n");
	while(head != NULL){
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("end");
}
