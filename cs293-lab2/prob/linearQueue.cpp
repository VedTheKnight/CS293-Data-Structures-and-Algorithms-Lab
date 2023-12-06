#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return head==tail;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  //return head == 0 && tail==N; // for the shifting method.
  return tail==N;
}

template <typename T> void DynamicQueue<T> :: grow() {
  int new_N = nextSize();
  T *new_A = new T[new_N]; //dynamically creates a new array of size nextSize()
  int i;
  for(i = 0;i<N;i++){
    if(head+i<N)
      new_A[i] = A[head+i];
    else
      break;
  }
  head = 0;
  tail = i;
  delete[] A;
  A = nullptr;
  A = new_A;
  N = new_N;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return tail-head;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()) grow();
  *(A + tail) = x;
  tail++;
  /*else if(head != 0 && tail == N){
    for(int i = 0;i<tail-head-1;i++){
      *(A+i)=A[head+i];
       A[head+i]=0;
    }
    head = 0;
    tail = tail-head;
  }
  else{
    *(A + tail) = x;
    tail++;
  }
  */ 
  // this makes the code very inefficient. Basically shifting the elements back to 0 whenever tail==N but array still has space.
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false;
  x = A+head;
  head = head+1;
  return true;
}
