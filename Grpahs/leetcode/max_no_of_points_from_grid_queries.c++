2503. Maximum Number of Points From Grid Queries
Attempted
Hard
Topics
Companies
Hint
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 

Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106


  


class Solution {
public:
    void solve(vector<vector<int>>&grid,int i,int j,int maxi,vector<vector<bool>>&vis,int m,int n,int &points){
        if(i<0 or j<0 or i>=m or j>=n or vis[i][j]) return;

        if(grid[i][j]>=maxi) return;

        vis[i][j]=true;
        points++;

        solve(grid,i-1,j,maxi,vis,m,n,points); //up
        solve(grid,i+1,j,maxi,vis,m,n,points);//down
        solve(grid,i,j-1,maxi,vis,m,n,points);//left
        solve(grid,i,j+1,maxi,vis,m,n,points);//right

       

    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int>ans;
        int m=grid.size();
        int n=grid[0].size();

        for(auto i:queries){
            int points=0;
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            solve(grid,0,0,i,vis,m,n,points);
            ans.push_back(points);
        }
        return ans;
    }
};


this approach is giving tle using dfs approach t.c:-O(m*n*k)
