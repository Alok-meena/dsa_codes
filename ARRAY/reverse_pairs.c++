493. Reverse Pairs
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1



brilliant ques


t.c:-O(logn + n+2nlogn) s.c:-O(n)


class Solution {
public:
    
void merge(vector<int>&arr,int low,int high,int mid){
    vector<int>ans(high-low+1);

    int l=low,r=mid+1,k=0;

    while(l<=mid and r<=high){
        if(arr[l]<=arr[r]){
            ans[k]=arr[l];
            k++;l++;
        }
        else{
            ans[k]=arr[r];
            k++;r++;
        }
    }

    while(l<=mid){
        ans[k]=arr[l];
        k++;l++;
    }

    while(r<=high){
        ans[k]=arr[r];
        k++;
        r++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=ans[i-low];
    }
}

int solve(vector<int>&arr,int low,int high,int mid){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high and arr[i]>(1LL*2*arr[right])){
            right++;
        }
        cnt=cnt+(right-(mid+1));
    }
    return cnt;
}
int mergesort(vector<int>&arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;

    int mid=low+(high-low)/2;    

    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=solve(arr,low,high,mid);
    merge(arr,low,high,mid);
    return cnt;
}
int mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    return mergesort(arr,0,n-1);
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,nums.size());
    }
};
