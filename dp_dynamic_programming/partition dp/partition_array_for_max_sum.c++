
1043. Partition Array for Maximum Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length








class Solution {
public:
    int solve(int i,int k,vector<int>&arr,vector<int>&dp){
        if(i==arr.size()) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int len=0;
        int maxi=0;
        int maxsum=0;

        for(int j=i;j<min((int)arr.size(),i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi;
            maxsum=max(maxsum,sum+solve(j+1,k,arr,dp));
        }

        return dp[i]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return solve(0,k,arr,dp);
    }
};


bottom up 


int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,0);

        for(int i=arr.size()-1;i>=0;i--){
            int len=0;
            int maxi=0;
            int maxsum=0;

            for(int j=i;j<min((int)arr.size(),i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi;
                maxsum=max(maxsum,sum+dp[j+1]);
            }

            dp[i]=maxsum;
        }
        return dp[0];
    }

t.c:-O(n*k)
