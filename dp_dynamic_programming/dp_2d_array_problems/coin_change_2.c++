518. Coin Change II
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000








class Solution {
public:
    int solve(int idx,vector<int>&coins,int tar,vector<vector<int>>&dp){
        if(idx>=coins.size()){
            if(tar==0) return 1;
            return 0;
        }
        if(tar==0) return 1;
        if(tar<0) return 0;

        if(dp[idx][tar]!=-1) return dp[idx][tar];

        int skip=solve(idx+1,coins,tar,dp);

        int take=solve(idx,coins,tar-coins[idx],dp);

        return dp[idx][tar]=skip+take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(0,coins,amount,dp);
    }
};
