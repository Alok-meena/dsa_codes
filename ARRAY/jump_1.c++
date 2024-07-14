
55. Jump Game
Solved
Medium
Topics
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



class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
           //so we should have to check this condition first then update the maxreach
            if (i > maxReach) {
                // If at any point the current index is greater than maxReach, we can't proceed further
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                // If at any point we can reach or exceed the last index, return true
                return true;
            }
        }
        
        return true; 
    }
};


1:recursive soln


here in using min function do this
  The error you're encountering is due to the min function not being able to deduce the types correctly. This often happens when mixing signed and unsigned types, 
  especially with size() which returns an unsigned type.



#include <algorithm>
class Solution {
public:
    bool solve(int position,vector<int>&nums){
        if(position>=nums.size()-1){
            return true;
        }

        int nextjump =min(position + nums[position], (int)nums.size() - 1); // Cast to int
        for(int i=position+1;i<=nextjump;i++){
            if(solve(i,nums)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
       return solve(0,nums);
    }
};

shows tle and after adding memorization it will work

2:
#include <algorithm>
class Solution {
public:
    bool solve(int position,vector<int>&nums,vector<int>&dp){
        if(position>=nums.size()-1){
            return true;
        }
        if(dp[position]!=-1){
            return dp[position];
        }

        int nextjump =min(position + nums[position], (int)nums.size() - 1); // Cast to int
        for(int i=position+1;i<=nextjump;i++){
            if(solve(i,nums,dp)){
                return true;
            }
        }
        return dp[position]=false;
    }
    bool canJump(vector<int>& nums) {
       vector<int>dp(nums.size(),-1);
       return solve(0,nums,dp);
    }
};
