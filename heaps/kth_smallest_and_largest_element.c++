Given an array arr[] and an integer k where k is smaller than the size of the array,\
the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Note:-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
n = 6
arr[] = 7 10 4 3 20 15
k = 3
l=0 r=5

Output : 
7

Explanation :
3rd smallest element in the given 
array is 7.


first by sorting then returning kth smallest element

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        sort(arr,arr+r+1);//O(nlogn) by any of the algorithms to sort
        return arr[k-1]; O(1)
    }
};



2nd approach : using heap data structure 

#include <queue>
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
         priority_queue<int>pq;

        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<=r;i++){// r : ending index of the array i.e size-1 isi vajah se r tk liya if size hoti to size -1 tak lete only
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }
};
  //  Kth Smallest element:  Time Complexity - O(r Log k) 

In which,  r = total no. of elements, k = size of priority queue
s.c:- O(K)



kth largest element:- using min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //code here
        int n=nums.size();
         priority_queue<int,vector<int>, greater<int>>pq;

        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans=pq.top();
        return ans;
    
    }
};
