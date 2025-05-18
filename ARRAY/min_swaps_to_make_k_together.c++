Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, 
i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or
equal to k together, i.e. make them a contiguous subarray.

Example 1:

Input : 
arr[ ] = {2, 1, 5, 6, 3} 
K = 3
Output : 
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}



1: brute force:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;

        // Count elements <= k
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                count++;
            }
        }

        // If there are no elements <= k, or all elements are <= k, no swaps are needed
        if (count == 0 || count == n) {
            return 0;
        }

        int minSwaps = INT_MAX;

        // Check all windows of size 'count'
        for (int i = 0; i <= n - count; i++) {//n-count tk hi jana taki last index tk pahuch paye with window of 3
            int bad = 0; // Number of elements > k in the current window
            // Count bad elements in the current window
            for (int j = i; j < i + count; j++) {//i+count karna taki index aage bdta rhe i se count distance aage
                if (arr[j] > k) {
                    bad++;
                }
            }
            // Update minSwaps with the minimum bad elements found
            minSwaps = min(minSwaps, bad);
        }

        return minSwaps;
    }
};

t.c:-O(n^2) and s.c:-O(1)


2:optimal O(n) and O(1) and just the previous code is optimized 

so instead of calculating bad for each window we have calculated bad count for the first window separately and then as a new bad element comes badd++
and first element of window ager bad hai so bad-- o/w continue;


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                count++;
            }
        }

        int bad=0;
        for(int j=0;j<count;j++){
                if(arr[j]>k){
                    bad++;
                }
        }
        
        int minswaps=bad;//store the initial window bad no. count to compare it with the updated bad
        
        for(int i=0,j=count;j<n;i++,j++){//if count=3 0 1 2 to yha =count kiya to include the next element and to check it
            if(arr[j]>k){
                bad++;
            }
            if(arr[i]>k){
                bad--;
            }
            minswaps=min(minswaps,bad);
        }
        if(minswaps==INT_MAX){
            return 0;
        }
        
        return minswaps;
    }
};



best code :


class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int count=0;
        for(auto i:arr){
            if(i<=k) count++;
        }
        
        int i=0,j=count-1;
        int ans=INT_MAX;

        while(j<arr.size()){
            int swaps=0;
            
            for(int m=i;m<=j;m++){
                if(arr[m]>k) swaps++;
            }
            

            ans=min(ans,swaps);
            i++;j++;
        }
        
        return ans==INT_MAX?0:ans;
    }
};

t.c:-O(n) and s.c:-O(1)
