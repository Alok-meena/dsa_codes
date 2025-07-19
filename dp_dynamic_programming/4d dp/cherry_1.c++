
Code
Test Result
Testcase
Testcase
741. Cherry Pickup
Solved
Hard
Topics
premium lock icon
Companies
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

Example 1:


Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1



  



class Solution {
public:
    int solve(int i1,int j1,int i2,int j2,int n,vector<vector<int>>&grid){
        if(i1>=n or j1>=n or i2>=n or j2>=n){
            return INT_MIN;
        }

        if(grid[i1][j1]==-1 or grid[i2][j2]==-1){
            return INT_MIN;
        }

        if(i1==n-1 and j1==n-1 and i2==n-1 and j2==n-1){
            return grid[i1][j1];
        }

        
        int cherry=0;
        if(j1==j2){
            cherry=grid[i1][j1];
        }
        else cherry=grid[i1][j1]+grid[i2][j2];


        int temp=max({
            solve(i1+1,j1,i2+1,j2,n,grid),
            solve(i1+1,j1,i2,j2+1,n,grid),
            solve(i1,j1+1,i2+1,j2,n,grid),
            solve(i1,j1+1,i2,j2+1,n,grid)
        });

        if(temp==INT_MIN) return INT_MIN;

        cherry+=temp;

        return cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=solve(0,0,0,0,n,grid);
        return ans==INT_MIN?0:ans;
    }
};


but not optimized


class Solution {
public:
    int solve(int i1,int j1,int i2,int j2,int n,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp){
        if(i1>=n or j1>=n or i2>=n or j2>=n){
            return INT_MIN;
        }

        if(grid[i1][j1]==-1 or grid[i2][j2]==-1){
            return INT_MIN;
        }

        if(i1==n-1 and j1==n-1 and i2==n-1 and j2==n-1){
            return grid[i1][j1];
        }

        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];

        
        int cherry=0;
        if(j1==j2){
            cherry=grid[i1][j1];
        }
        else cherry=grid[i1][j1]+grid[i2][j2];


        int temp=max({
            solve(i1+1,j1,i2+1,j2,n,grid,dp),
            solve(i1+1,j1,i2,j2+1,n,grid,dp),
            solve(i1,j1+1,i2+1,j2,n,grid,dp),
            solve(i1,j1+1,i2,j2+1,n,grid,dp)
        });

        if(temp==INT_MIN) return  dp[i1][j1][i2][j2]=INT_MIN;

        cherry+=temp;

        return dp[i1][j1][i2][j2]=cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans=solve(0,0,0,0,n,grid,dp);
        return ans==INT_MIN?0:ans;
    }
};
