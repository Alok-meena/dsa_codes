63. Unique Paths II
Solved
Medium
Topics
Companies
Hint
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1









class Solution {
public:
    int solve(vector<vector<int>>&grid,int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int total=0;

        //choose right
        if(j+1<n and grid[i][j+1]!=1) total+=solve(grid,m,n,i,j+1,dp);

        //choose down
        if(i+1<m and grid[i+1][j]!=1) total+=solve(grid,m,n,i+1,j,dp);

        return dp[i][j]=total;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1) return 0; //if there is a obstacle and start point or destination then no way to reach destination 
        //alright 

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(obstacleGrid,m,n,0,0,dp);
    }
};


just one change and same tabulation and space optimization like previous
