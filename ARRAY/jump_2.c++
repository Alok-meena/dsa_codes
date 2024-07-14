45. Jump Game II
Medium
Topics
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

1 recursion here we are trying all possible combinations and taking out the min as answer

class Solution {
public:
    int solve(int index,int jumps,vector<int>&nums){
        if(index>=nums.size()-1){
            return jumps;
        }

        int ans=INT_MAX;

        for(int i=1;i<=nums[index];i++){
            ans=min(ans,solve(index+i,jumps+1,nums));
        }
        
        return ans;
    }
    int jump(vector<int>& nums) {
        vector<vector<int>>dp()
        return solve(0,0,nums);
    }
};

t.c:-O(N^N) and s.c:-O(N)


2:
class Solution {
public:
    int solve(int index,int jumps,vector<int>&nums,vector<vector<int>>&dp){
        if(index>=nums.size()-1){
            return jumps;
        }
        if(dp[index][jumps]!=-1){
            return dp[index][jumps];
        }

        int ans=INT_MAX;

        for(int i=1;i<=nums[index];i++){
            ans=min(ans,solve(index+i,jumps+1,nums,dp));
        }
        
        return dp[index][jumps]=ans;
    }
    int jump(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(0,0,nums,dp);
    }
}; 
memorization
t.c ans s.c --> O(N^2)


  class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
 
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
           //to is loop se farthest ham l se calculate kr rhe hai
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
}; 

t.c:-O(n) and s.c:-O(1)

3:
