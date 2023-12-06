#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  return (i-1)/2; 
}

int Heap::left(int i) {
  return 2*i+1; 
}

int Heap::right(int i) {
  return 2*i+2; 
}

int Heap::max() {
  return store[0];
}

void Heap::swap(int i, int j) {
  int temp;
  temp = store[i];
  store[i] = store[j];
  store[j] = temp;
}

void Heap::insert(int v) {
  int i = sz;
  append(v);

  while(i>0 && store[parent(i)]<store[i]){
    swap(i,parent(i));
    i = parent(i);
  }
}

void Heap::heapify(int i) {
  int c = 0; //to store the max index between both children and the supplied node
  if(left(i)>=int(sz)&&right(i)>=int(sz)){
    return;
  }
  else if(left(i)>=(int)sz){
    if(store[right(i)]>=store[i])
      c = right(i);
    else
      return;
  }
  else if(right(i)>=(int)sz){
    if(store[left(i)]>=store[i])
      c = left(i);
    else
      return;
  }
  else{ //if both the children exist
    if(store[i]>=store[left(i)] && store[i]>=store[right(i)]){
      return; //this means store[i] is greater than both its children hence it is a valid heap
    }
    else if(store[i] <= store[left(i)] && store[right(i)] <= store[left(i)]){
      c = left(i);
    }
    else if(store[i] <= store[right(i)] && store[right(i)] >= store[left(i)]){
      c = right(i);
    }
  }
  swap(i,c);
  swap_count++;
  heapify(c);
}


void Heap::deleteMax() {
  swap_count = 0;
  swap(0,sz-1);
  swap_count++;
  sz = sz-1; //isn't physically deleting the element!
  heapify(0);
}

void Heap::buildHeap() {
  for(int i = sz-1; i>=0; i--){
    heapify(i);
  }
}

void Heap::heapSort() {
  buildHeap(); //assuming the original vector is just a random sequence of numbers
  while(sz>0){
    deleteMax();
  }
}


