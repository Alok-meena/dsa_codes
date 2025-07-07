200. Number of Islands
Solved
Medium
Topics
premium lock icon
Companies
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.


int this we only have to return no. of connected compo's alright





class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newi=x+dirx[d];
                int newj=y+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]=='1'){
                    grid[newi][newj]='0';
                    q.push({newi,newj});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    bfs(i,j,grid);
                }
            }
        }

        return islands;
    }
};

t.c:-O(n*m) and same s.c
