Longest Subarray with Sum K
Difficulty: MediumAccuracy: 24.64%Submissions: 708K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109



brute genearte all subarrays t.c:-O(n^2)

int longestSubarray(vector<int>& arr, int k) {
        // code here
        int len=0;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    len=max(len,j-i+1);
                }
            }
        }
        
        return len;

two ptr:
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int len=0;
        
        int n=arr.size();
        
        int l=0,r=0,sum=0;
        
        while(r<n){
            sum+=arr[r];
            if(sum==k){
                len=max(len,r-l+1);
            }
            else{
                while(l<=r and sum>k){
                    sum-=arr[l];
                    l++;
                }
            }
            r++;
        }
        
        return len;
    }
};

valid only if all are positive o/w use below one


unordered_map<int,int>mp;
        
        int currsum=0;
        
        int len=0;
        
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            
            if(currsum==k){
                len=max(len,i+1);
            }
            
            if(mp.find(currsum-k)!=mp.end()){
                len=max(len,i-mp[currsum-k]);
            }
            
            if(mp.find(currsum)==mp.end()) mp[currsum]=i;
        }
        
        return len;
