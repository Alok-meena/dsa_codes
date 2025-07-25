198. House Robber
Solved
Medium
Topics
premium lock icon
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400





#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;

        //skip;
        int nottake=solve(i+1,nums,dp);

        int take=nums[i]+solve(i+2,nums,dp);
        
        return dp[i]=max(nottake,take);
    }

    //above is top down + memo but giving tle  

    //below is bottom up approach 


    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,0);

        for(int i=n-1;i>=0;i--){
            int nottake=dp[i+1];

            int take=nums[i]+dp[i+2];
            
            dp[i]=max(nottake,take);
        }
        return dp[0];
    }
};
