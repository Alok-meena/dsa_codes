


Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 





brute force

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int longestSubarray=0;
    for(int i=0;i<a.size();i++){
        int sum=0;
        for(int j=i;j<a.size();j++){
            sum+=a[j];
            if(sum==k){
                longestSubarray=max(longestSubarray,j-i+1);
            }
        }
    }
    return longestSubarray;
}
