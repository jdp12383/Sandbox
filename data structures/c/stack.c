/**
 * Compile:
 * gcc -o stack.o stack.c
 *
 * Time complexity:
 * push - O(1)
 * pop = O(1)
 *
 */

#include <stdio.h>

#define SIZE 			5
#define EMPTY			-1

#define SUCCESS		1
#define ERR_FULL 	-1
#define ERR_EMPTY	-2

int stack[SIZE];
int sp=EMPTY;	//stack pointer OR top of the stack

int push(int);
int delete_last();
int top();
int isEmpty();
void print();

void main(int argc, char *argv[]){
	//initialize stack
	for(int idx=0;idx<SIZE;idx++){
		stack[idx]=0;
	}

	push(5);
	push(3);
	push(10);
	print();
	printf("\ntop of the stack: %d", top());
	printf("\npop of the stack: %d", delete_last());
	print();
	printf("\ntop of the stack: %d", top());
	printf("\npop of the stack: %d", delete_last());
	print();
	printf("\ntop of the stack: %d", top());
	printf("\npop of the stack: %d", delete_last());
	print();
	printf("\ntop of the stack: %d", top());
	printf("\npop of the stack: %d", delete_last());
	push(13);
	print();
	printf("\ntop of the stack: %d", top());
}

int push(int data){
	if(sp==SIZE-1){
		return ERR_FULL;
	}

	stack[++sp]=data;
	return SUCCESS;
}

int delete_last(){
	if(sp==EMPTY){
		return ERR_EMPTY;
	}
	int ret = stack[sp];
	stack[sp--]=0;
	return ret;
}

int top(){
	if(sp==EMPTY){
		return ERR_EMPTY;
	}
	return stack[sp];
}

int isEmpty(){
	return sp==-1;
}

void print(){
	if(isEmpty()){
		printf("\nstack is empty.");
		return;
	}

	printf("\n");
	for(int idx=0;idx<=sp;idx++){
		printf("%d, ", stack[idx]);
	}
}
