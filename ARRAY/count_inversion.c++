Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: n = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: n = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count




brute force class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int solve(long long arr[],int n,long long int count){
        
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        long long int count=0;
        
        // return solve(arr,n,count);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]{
                    count++;
                }
            }
        }
        return count;
    }
};

t.c:-O(n^2) ans s.c:-O(1)



using mergesort

#include <bits/stdc++.h>
using namespace std;

long long merge(vector<long long>& nums, int low, int mid, int high) {
    long long count = 0;
    vector<long long> temp;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
            count += (mid - left + 1);
        }
    }

    while (left <= mid) {
        temp.push_back(nums[left++]);
    }

    while (right <= high) {
        temp.push_back(nums[right++]);
    }

    for (int i = low; i <= high; ++i) {
        nums[i] = temp[i - low];
    }

    return count;
}

long long mergesort(vector<long long>& nums, int low, int high) {
    long long count = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        count += mergesort(nums, low, mid);
        count += mergesort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
    }
    return count;
}

long long getInversions(long long *arr, int n) {
    vector<long long> array(n);
    for (int i = 0; i < n; ++i) {
        array[i] = arr[i];
    }
    return mergesort(array, 0, n - 1);
}

