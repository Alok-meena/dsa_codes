
Code
Testcase
Testcase
Test Result
64. Minimum Path Sum
Solved
Medium
Topics
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200









class Solution {
public:
     int solve(vector<vector<int>>&grid,int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int path1=INT_MAX,path2=INT_MAX;

        //choose right
        if(j+1<n) path1=grid[i][j]+solve(grid,m,n,i,j+1,dp); //yha pe store kro na ki add as we want min value so path's me hamne max value store krai hai okk
        //and here do grid[i][j]+ not grid[i][j+1] because aage j+1 ki value to recursive fun call krke  la rhe hai o/w current value miss ho jayegi aor add nhi
        //hogi alright 

        //choose down
        if(i+1<m) path2=grid[i][j]+solve(grid,m,n,i+1,j,dp);

        return dp[i][j]=min(path1,path2);


    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        vector<vector<int>>dp(m,vector<int>(n,-1));

        

        return solve(grid,m,n,0,0,dp);
    }
};

t.c:-O(n*m) and s.c:-O(n*m) + O(n+m)
