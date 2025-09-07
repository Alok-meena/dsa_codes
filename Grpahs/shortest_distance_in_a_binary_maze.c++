Shortest Distance in a Binary Maze
Difficulty: MediumAccuracy: 58.22%Submissions: 77K+Points: 4Average Time: 20m
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.
Example 2:

Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and 
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:

1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
The source and destination cells are always inside the given matrix.




simplest of all

// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        
        while(!q.empty()){
            int dist=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            
            if(i==destination.first and j==destination.second) return dist;
            
            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];
                
                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1){
                    grid[newi][newj]=0;
                    q.push({dist+1,{newi,newj}});
                }
            }
        }
        
        return -1;
    }
};



            



// User function Template for C++

class Solution {
  public:
     int solve(int i,int j,int n,vector<vector<int>>&grid,vector<vector<int>>&vis,pair<int,int>d){
        vis[i][j]=1;
        int m=grid[0].size();

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{i,j}});

        while(!q.empty()){
            int path=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            if(x==d.first and y==d.second) return path;

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};

            for(int d=0;d<4;d++){
                int newi=x+dirx[d];
                int newj=y+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and vis[newi][newj]==0 and grid[newi][newj]==1){
                    vis[newi][newj]=1;
                    q.push({path+1,{newi,newj}});
                }
            }
        }

        return -1;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(grid[source.first][source.second]==0 or grid[destination.first][destination.second]==0) return -1;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        return solve(source.first,source.second,n,grid,vis,destination);
    }
};



t.c:-O(n*m) and same s.c alright


and below is also correct instead of storing dist we stored in dist 2d vector and used it as a vis array alright


// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,0));
        dist[source.first][source.second]=1;
        
        queue<pair<int,int>>q;
        q.push({source.first,source.second});
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(i==destination.first and j==destination.second) return dist[i][j]-1;
            
            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];
                
                if(newi>=0 and newi<n and newj>=0 and newj<m and dist[newi][newj]==0 and grid[newi][newj]==1){
                    dist[newi][newj]=dist[i][j]+1;
                    q.push({newi,newj});
                }
            }
        }
        
        return -1;
    }
};

