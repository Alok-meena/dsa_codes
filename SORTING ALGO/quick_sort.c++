#include <bits/stdc++.h> 


int partition(int low,int high,vector<int>&arr){
    int pivot=low;
    int i=low+1;
    int j=high;

    while(i<=j){
        while(i<=high and arr[i]<=arr[pivot]) i++;
        while(j>=low and arr[j]>arr[pivot]) j--;
        
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[pivot],arr[j]);

    return j;
}
void Quicksort(int low,int high,vector<int>&arr){
    if(low<high){
        int partition_index=partition(low,high,arr);
        Quicksort(low,partition_index-1,arr);
        Quicksort(partition_index+1,high,arr);
    }
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    Quicksort(0,arr.size()-1,arr);
    return arr;
}

so dekho sbase pahle to hame partition index chahihe jisse left sare chote ele and right sare bde ele alright and then call quick sort for left and right 
individually alright 



fantastic code alright t.c : -O(nlogn) and s.c:-O(1)

the quicksort is called n times so O(n) and each time the array got halved to solve it so at last total recursive levels is o(logn) so u know


but worst case t.c of q.s is O(n^2) ( possible when the array is already sorted alright )



((((((((( What happens in the worst case?
At each recursive call, you reduce the problem size by only 1 element instead of about half.

So the recursive calls form a chain of length n (depth of recursion = n).

Each call does O(n) work to partition. ))))))))




it is inplace , not stable ( due to swapping of elements )  , not adaptive
