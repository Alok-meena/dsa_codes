You are given an integer array with N elements. Your task is to build a max binary heap from the array.

A max-heap is a complete binary tree in which the value of each internal node is greater than or equal to the values of the children of that node.

Note :
You do not need to print anything, just return the vector representation of the heap such that the input array follows 0 - based indexing and :

The left child of the ith node is at (2 * i + 1)th index.

The right child of the ith node is at (2 * i + 2)th index.

Parent of the node present at ith index is at (i - 1) / 2 indexes.



#include <bits/stdc++.h> 

void heapify(vector<int> &arr,int n,int i){
	int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 
	for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
	return arr;
}



You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.

A min-Binary heap is a complete binary tree in which the value of each internal node is smaller than or equal to the values of the children of that node.

Note :
1. Input array follows 0 - based indexing. 

2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.

4. Note that you do not need to create a tree, just update the array.


#include <bits/stdc++.h> 
void heapify(vector<int>& arr,int n,int i){
	int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }

    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
