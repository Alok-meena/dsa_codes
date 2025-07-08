Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 105K+Points: 4Average Time: 20m
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1








// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v,int row0,int col0){
        vis[i][j]=1;
        
        int n=grid.size();
        int m=grid[0].size();
        
        v.push_back({i-row0,j-col0});
        
        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};
        
        for(int d=0;d<4;d++){
            int newi=i+dirx[d];
            int newj=j+diry[d];
            
            if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj] and grid[newi][newj]==1){
                dfs(newi,newj,vis,grid,v,row0,col0);
            }
        }
    }
    
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v,int row0,int col0){
        vis[i][j]=1;
        
        int n=grid.size();
        int m=grid[0].size();
        
        v.push_back({i-row0,j-col0});
        
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newi=x+dirx[d];
                int newj=y+diry[d];
                
                if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj] and grid[newi][newj]==1){
                    vis[newi][newj]=1;
                    v.push_back({newi-row0,newj-col0});
                    q.push({newi,newj});
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>st;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>v;
                    bfs(i,j,vis,grid,v,i,j);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
    }
};

by bfs and dfs both 


listen if the two islands are same then counted as 1 alright if diff structure then diff so to store same in set we used indices and subtracting them from the base 
1 indices alright 
