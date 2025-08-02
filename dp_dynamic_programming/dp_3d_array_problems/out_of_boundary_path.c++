
Code
Test Result
Testcase
Testcase
576. Out of Boundary Paths
Solved
Medium
Topics
premium lock icon
Companies
Hint
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n







class Solution {
public:
    int mod=1e9+7;
    int solve(int m,int n,int moves,int i,int j,vector<vector<vector<int>>>&dp){
        if(i<0 or j<0 or i==m or j==n) return 1;

        if(moves==0) return 0;

        if(dp[i][j][moves]!=-1) return dp[i][j][moves];

        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};

        int count=0;

        for(int d=0;d<4;d++){
            int newi=i+dirx[d];
            int newj=j+diry[d];

            count=(count+solve(m,n,moves-1,newi,newj,dp))%mod;
        }

        return dp[i][j][moves]=count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};

O(n^3) s.c 
