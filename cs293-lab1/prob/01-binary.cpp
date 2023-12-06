#include <iostream>

// Consider the binary search algorithm presented in class. We are interested
// in determining the average execution time of the binary search. To
// accomplish this, let's conduct an experiment.

// Suppose we have an array of size 1024, which contains distinct elements
// arranged in non-increasing order. We have already analyzed the running
// time when the element being searched for is not present in the array.
// Now, let's assume that we are only searching for elements that we know
// exist in the array.

// Our goal is to experimentally calculate the average number of
// iterations required to search for all 1024 elements in the array.

// In the following,
//   -- Implement BinarySearch that can handle non-increasing array
//   -- Harness BinarySearch such that we can compute avarage number
//      of iterations


int BinarySearch ( int * S , int n , int e ) {
  int iteration_count = 0;
  // Implement binary search here
  // instead of returning position return the number
  // of executed iterations of binary search.
  int first = 0;
  int last = n-1;

  while(first<last){
    iteration_count++;
    int mid = (first+last)/2;
    if(S[mid]==e){
      return iteration_count;
    }
    if(S[mid]>e){
      last = mid-1;
    }
    else{
      first = mid+1;
    }

  }
  return iteration_count;
}

int main() {
  unsigned size = 1024;
  int S[size];
  float average = 0;
  // Initialize array S with distinct elements
  for(int i = 0; i<size;i++){
    S[i] = size-i;
  }
  // search 1024 element stored in S and compute
  // the average number of iterations in binary search
  for(int i = 0;i<size;i++){
    average+= BinarySearch(S,size,i+1);
    std::cout<<i+1;
  }
  average = average/size;
  std::cout << "Average: " << average << "\n";
  return 0;
}
