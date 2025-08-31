
Code
Test Result
Testcase
Testcase
1463. Cherry Pickup II
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:


Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100








very good ques


class Solution {
public:
    int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(j1<0 or j2<0 or j1>=c or j2>=c) return INT_MIN;

        if(i==r-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxi=INT_MIN;

        //explore all paths

        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=solve(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                maxi=max(maxi,value);
            }
        }

        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return solve(0,0,c-1,r,c,grid,dp);
    }
};

t.c:-O(n*m*m) and s.c:-O(n) due to auxiliary stack space alright and after dp o(n*m*m) alright


bottom up alright


int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));

        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2) dp[r-1][j1][j2]=grid[r-1][j1];
                else dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }

        for(int i=r-2;i>=0;i--){
            for(int j1=c-1;j1>=0;j1--){
                for(int j2=c-1;j2>=0;j2--){
                    int maxi=INT_MIN;

                    //explore all paths

                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value=0;
                            if(j1==j2) value=grid[i][j1];
                            else value=grid[i][j1]+grid[i][j2];
                            if(i+1<r and j1+dj1>=0 and j1+dj1<c and j2+dj2>=0 and j2+dj2<c) value+=dp[i+1][j1+dj1][j2+dj2];
                            maxi=max(maxi,value);
                        }
                    }

                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][c-1];
    }


2nd time
int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(grid[0].size()+1,-1)));
        int n=grid.size();
        int m=grid[0].size();
        for(int j1=0;j1<grid[0].size();j1++){
            for(int j2=0;j2<grid[0].size();j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }

        for(int i=grid.size()-2;i>=0;i--){
            for(int j1=grid[0].size()-1;j1>=0;j1--){
                for(int j2=grid[0].size()-1;j2>=0;j2--){
                    int ans=INT_MIN;

        for(int dir=-1;dir<=1;dir++){
            for(int dir2=-1;dir2<=1;dir2++){
                int val1=grid[i][j1];
                int val2=grid[i][j2];

                if(j1==j2){
                    if(i+1<n and j1+dir>=0 and j1+dir<m and j2+dir2>=0 and j2+dir2<m) ans=max(ans,val1+dp[i+1][j1+dir][j2+dir2]);
                }
                else if(i+1<n and j1+dir>=0 and j1+dir<m and j2+dir2>=0 and j2+dir2<m) ans=max(ans,val1+val2+dp[i+1][j1+dir][j2+dir2]);
                    }
                }

                dp[i][j1][j2]=ans;
                }
            }
        }
        return dp[0][0][grid[0].size()-1];
