55. Jump Game
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105






used dp


class Solution {
public:
    bool solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1) return true;

        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,nums,dp)) return true;
        }

        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n+1,-1);    
        return solve(0,nums,dp);
    }
};


t.c and s.c is O(n) alright

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;

        for(int i=0;i<nums.size();i++){
            if(i>farthest) return false;
            farthest=max(farthest,i+nums[i]);
            if(farthest>=nums.size()-1) return true;
        }
        return false;
    }
};

optimized
