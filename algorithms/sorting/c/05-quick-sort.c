#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int* numbers, int left, int right) {
  int i = left, j = right;
  
  //select the pivot element value
  int pivot=numbers[(left+right)/2];
  
  //now divide the array into two lists
  while(i<=j) {
    
    //if the current value from the left list is smaller than the pivot
    // element then get the next element from the left list
    while(numbers[i]<pivot) {
      i++;
    }
    
    //if the current value from the right list is larger than the pivot
    // element then get the next element from the right list
    while(numbers[j]>pivot) {
      j--;
    }
    
    //if we find a value in the left list which is larger than
    // the pivot element and if we have found a value in the right list
    // which is smaller than the pivot element then we exchange the values
    // and increase counters
    if(i<=j) {
      // swap the numbers
      int temp = numbers[i];
      numbers[i]=numbers[j];
      numbers[j]=temp;
      
      i++;
      j--;
    }
  }  
  return i;
}

void quickSortEx(int* numbers, int length, int left, int right) {
  
  if(length > 1) {
    int index = partition(numbers, left, right);
    if(index-1 > left) {
      quickSortEx(numbers, length, left, index-1);
    }
    
    if(index < right) {
      quickSortEx(numbers, length, index, right);
    }
  }
}

void quickSort(int* numbers, int length) {
  if (length==0) {
    return;
  }
  quickSortEx(numbers, length, 0, length-1);
}

int main(void) {
  int in1[]=   {4,3,2,1};
  int length=4;
  
  //sort the array in ascending order
  quickSort(in1, length);
  for(int j=0;j<length;j++)
    printf("%d ",*(in1+j));
  
  return 0;
}
