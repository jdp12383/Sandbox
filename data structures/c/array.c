/**
 * Compile:
 * gcc -o array.o array.c
 *
 * Time complexity:
 * insert/delete -
 * 		at the beginning - O(n)
 * 		at the end - O(1)
 * 		at the index position - O(n)
 * read = O(1)
 * modify = O(1)
 * length = O(1)
 *
 */

#include <stdio.h>

#define SIZE	5
#define EMPTY	-1

#define SUCCESS			1
#define ERR_FULL 		-1
#define ERR_EMPTY		-2
#define ERR_INDEX_OUT_OF_BOUND	-3

int data[SIZE];
int end=EMPTY;	//end of the array

int prepend(int, int);
int delete(int);
int read(int);
int modify(int, int);
int length();
int isEmpty();
int isValid(int);
void print();

void main(int argc, char *argv[]){
	//initialize stack
	for(int idx=0;idx<SIZE;idx++){
		data[idx]=0;
	}

	prepend(0, 5);
	prepend(1, 3);
	print();
	printf("\ninserted 10 at the start", prepend(0, 10));
	print();
	printf("\ninserted 15 at index 3", prepend(3, 15));
	print();
	printf("\ndeleted from end: %d", delete(end));
	print();
	printf("\ndeleted from start: %d", delete(0));
	print();
	printf("\nread 1st: %d", read(0));
	printf("\nmodify 1st index to 22");
	modify(1, 22);
	print();
	printf("\nlength of array: %d", length());

}

int prepend(int index, int value){
	if(length()==SIZE){
		return ERR_FULL;
	}

	if(index <= end){
		// increment the length of array by 1
		end++;

		// shift all the elements to right from the index
		// where this element is added
		for(int idx=end;idx>index;idx--){
			data[idx]=data[idx-1];
		}
		data[index]=value;
	} else {
		data[++end]=value;
	}

	return SUCCESS;
}

int delete(int index){
	if(isEmpty()){
		return ERR_EMPTY;
	} else if(!isValid(index)){
		return ERR_INDEX_OUT_OF_BOUND;
	}
	int ret = data[index];

	// 1st shift all the elements from right of the delete index
	for(int idx=index;idx<=end;idx++){
		data[idx]=data[idx+1];
	}

	// 2nd decrement the length of array by 1
	end--;

	return ret;
}

int read(int index){
	if(end==EMPTY){
		return ERR_EMPTY;
	} else if(!isValid(index)){
		return ERR_INDEX_OUT_OF_BOUND;
	}

	return data[index];
}

int modify(int index, int newvalue){
	if(isEmpty()){
		return ERR_EMPTY;
	} else if(!isValid(index)){
		return ERR_INDEX_OUT_OF_BOUND;
	}
	data[index]=newvalue;

	return SUCCESS;
}

int length(){
	return end+1;
}

int isEmpty(){
	return end==-1;
}

int isValid(int index){
	return index >= 0 && index <= end;
}

void print(){
	if(isEmpty()){
		printf("\array is empty.");
		return;
	}

	printf("\n");
	for(int idx=0;idx<=end;idx++){
		printf("%d, ", data[idx]);
	}
}
