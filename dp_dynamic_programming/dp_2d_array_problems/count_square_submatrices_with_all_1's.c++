1277. Count Square Submatrices with All Ones
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1





this is perfect




class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i>=n or j>=m or mat[i][j]==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i,j+1,n,m,mat,dp);
        int diagonal=solve(i+1,j+1,n,m,mat,dp);
        int down=solve(i+1,j,n,m,mat,dp);

        return dp[i][j]=1+min({right,diagonal,down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    count+=solve(i,j,n,m,matrix,dp);
                }
            }
        }

        return count;
    }
};


or

class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&mat,int &count,vector<vector<int>>&dp){
        if(i>=n or j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i,j+1,n,m,mat,count,dp);
        int diagonal=solve(i+1,j+1,n,m,mat,count,dp);
        int down=solve(i+1,j,n,m,mat,count,dp);
        
        if(mat[i][j]==1){
            int ans=1+min({right,diagonal,down});
            return dp[i][j]=ans;
        }
        else return dp[i][j]=0;
    }
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // solve(0,0,n,m,mat,count,dp);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=solve(i,j,n,m,mat,count,dp);
            }
        }

        return count;
    }
};
