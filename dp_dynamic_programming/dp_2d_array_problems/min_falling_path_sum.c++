931. Minimum Falling Path Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100






class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==grid.size()-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

        if(i+1<grid.size() and j-1>=0) op1=grid[i][j]+solve(i+1,j-1,grid,dp);
        if(i+1<grid.size()) op2=grid[i][j]+solve(i+1,j,grid,dp);
        if(i+1<grid.size() and j+1<grid.size()) op3=grid[i][j]+solve(i+1,j+1,grid,dp);

        return dp[i][j]=min(op1,min(op2,op3));
    }


it's bottom up is little tricky as we are reaching last row then we are returning just that value in top down so do same
and start i from n-2 n-1 is done and j from n-1 only and in top down we are starting from any value of 1st row so here our ans is stored in any column of first
row so just return min of all those alright


    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();

        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++) dp[n-1][j]=grid[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

                if(i+1<grid.size() and j-1>=0) op1=grid[i][j]+dp[i+1][j-1];
                if(i+1<grid.size()) op2=grid[i][j]+dp[i+1][j];
                if(i+1<grid.size() and j+1<grid.size()) op3=grid[i][j]+dp[i+1][j+1];

                dp[i][j]=min(op1,min(op2,op3));
            }
        }

        int a=INT_MAX;
        for(int i=0;i<n;i++){
            a=min(a,dp[0][i]);
        }
        return a;
    }
};
