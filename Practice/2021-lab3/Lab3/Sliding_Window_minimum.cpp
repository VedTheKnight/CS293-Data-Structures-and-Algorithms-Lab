/*
Fun problem 7

You are given an array arr[] of integers containing n elements, for a given k, we want to output n-k+1 integers 
a_i s.t. a_0 is minimum in arr[0 to k-1], a_1 is minimum in arr[1 to k] and so on a_{n-k} is minimum in 
arr[n-k to n-1]

Design an efficient algorithm to find these a_i
*/

#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n = 13;
    int arr[n] = {2,5,1,4,7,3,9,8,6,2,10,11,1};
    int k=4;
    deque<int> min_window;

    for(int i = 0;i<k;i++){
        while(!min_window.empty() && arr[min_window.back()]>=arr[i]){
            min_window.pop_back();
        }
        min_window.push_back(i); //note that we are storing indices of the minimas
    }
    //now we print out the first window corresponding to last element k-1
    cout<<arr[min_window.front()]<<" ";

    for(int i = k;i<n; i++){
        //this is the instant it goes out of the sliding window
        if(i - min_window.front() == k){
            min_window.pop_front();
        }
        //this deletes the elements between the min and the next subsequent min on adding arr[i] to the window
        while(!min_window.empty() && arr[min_window.back()]>=arr[i]){
            min_window.pop_back();
        }
        min_window.push_back(i); //pushes the index of the new next min appropriately to the back of the queue
        
        //now we just print the value at the front of the queue at that instant.
        cout<<arr[min_window.front()]<<" ";
    }
    return 0;
}