322. Coin Change
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104






class Solution {
public:
    int solve(int idx,vector<int>&nums,int tar,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            return INT_MAX;
        }

        if(tar==0) return 0;

        if(tar<0) return INT_MAX;

        if(dp[idx][tar]!=-1) return dp[idx][tar];

        int skip=solve(idx+1,nums,tar,dp);

        int take=INT_MAX;
        if(nums[idx]<=tar){
            int val=solve(idx,nums,tar-nums[idx],dp);
            if(val!=INT_MAX) take=1+val;
        }

        return dp[idx][tar]=min(skip,take);
    }
    int coinChange(vector<int>& num, int tar) {
        int n=num.size();

        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        int ans=solve(0,num,tar,dp);
        return ans==INT_MAX?-1:ans;
    }
};
