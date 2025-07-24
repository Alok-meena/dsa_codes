45. Jump Game II
Solved
Medium
Topics
premium lock icon
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
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].











again used dp 


class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n-1){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int ans=INT_MAX;

        for(int j=1;j<=nums[i];j++){
            int check=solve(i+j,n,nums,dp);
            if(check!=INT_MAX){
                ans=min(ans,1+check);
            }
        }

        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};


t.c:-O(n^2) and s.c:-O(n)




optimized greedy t.c:-O(N) and O(1) s.c alright


class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        
        if(n==1) return 0;

        int jumps=0;

        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }

            l=r+1;
            r=farthest;

            jumps++;
        }

        return jumps;
    }
};

completed
