1091. Shortest Path in Binary Matrix
Solved
Medium
Topics
Companies
Hint
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1







class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1) return -1;

        queue<vector<int>>q; //{i,j,dist}

        q.push({0,0,1}); 

        vector<vector<int>>visited(n,vector<int>(n,-1));
        visited[0][0]=1;

        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();

            int r=v[0];
            int c=v[1];
            int dist=v[2];

            if(r==n-1 and c==n-1) return dist;

            int dirx[]={-1,-1,-1,0,0,0,1,1,1};
            int diry[]={-1,0,1,-1,0,1,-1,0,1};

            for(int i=0;i<9;i++){
                int nr=r+dirx[i];
                int nc=c+diry[i];

                if(nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]==0 and visited[nr][nc]==-1){
                    visited[nr][nc]=1;
                    q.push({nr,nc,dist+1});
                }
            }
        }

        return -1;
    }
};

t.c:-O(n^2) and s.c:-O(n^2)
