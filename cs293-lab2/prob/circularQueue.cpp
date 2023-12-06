#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return size()==0; 
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return size()==N-1;
}

template <typename T> void DynamicQueue<T> :: grow() {
  int new_N = nextSize();
  T *new_A = new T[new_N];
  for(int i = 0;i<N-1;i++){
    new_A[i] = A[(head+i)%N];
  }
  head = 0;
  tail = N-1;

  delete[] A;
  A = nullptr;
  
  A = new_A;
  N = new_N;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (N + tail - head)%N;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()){
    grow();
    A[tail] = x;
    tail = (tail+1)%N;
  } 
  else{
    A[tail] = x;
    tail = (tail+1)%N;
  }
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false;
  *x = A[head];
  head = (head+1)%N;
  return true;
}


