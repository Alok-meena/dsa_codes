Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
Example 3:



  HASHMAP+DP solution

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>dp;
        int ans=0;

        for(int i=0;i<n;i++){
            int temp=arr[i]-difference;
            int count=0;

           //check if ans already present or not
            if(dp.count(temp)){
                count=dp[temp];
            }

            dp[arr[i]]=1+count;

            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
