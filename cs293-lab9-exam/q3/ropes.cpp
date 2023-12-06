#include <bits/stdc++.h>

using namespace std;

void merge_arrays(int len[], int l, int mid, int r, int n){

	int* temp = new int[n];
	int i = l;
	int j = mid+1;
	int x = l;

	while(i<=mid && j<=r){
		if(len[i]<=len[j]){
			temp[x] = len[i];
			x++;
			i++;
		}
		else if(len[j]<len[i]){
			temp[x] = len[j];
			x++;
			j++;
		}
	}

	if(i>mid){
		while(j<=r){
			temp[x] = len[j];
			x++;
			j++;
		}
	}

	if(j>r){
		while(i<=mid){
			temp[x] = len[i];
			x++;
			i++;
		}
	}

	for(int i = l;i<=r;i++){
		len[i] = temp[i];
	}
}

void mergesort(int len[],int l, int r, int n){

	if(l>=r){
		return;
	}
	
	int mid = (l+r)/2;

	mergesort(len,l,mid,n);
	mergesort(len,mid+1,r,n);

	merge_arrays(len,l,mid,r,n);
}

// The main function that returns
// the minimum cost to connect n
// ropes of lengths stored in len[0..n-1]
int minCost(int len[], int n)
{
	int cost = 0; // Initialize result

    // Write your code here
	for(int i=0; i<=n-2;i++){
		mergesort(len,i,n-1,n);
		cost += (len[i] + len[i+1]);
		len[i+1] = (len[i]+len[i+1]);
	}

	return cost;
}


