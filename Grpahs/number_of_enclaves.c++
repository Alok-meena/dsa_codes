1020. Number of Enclaves
Solved
Medium
Topics
Companies
Hint
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.




to ques me bola tha uske hisab se jo bhi cell bounday vale cell se connected hai jo 1 hai un sbhi ko visited mark kr do bs bche hue sare vo hai jinse boundary 
pe nhi jaya ja skta okk alright



solution by bfs

class Solution {
public:
    void bfs(vector<vector<int>>&grid,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=2;

        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            //x-1 y up 
            if(x-1>=0 and grid[x-1][y]==1){
                grid[x-1][y]=2;
                q.push({x-1,y});
            }
            
            //x+1 y down
            if(x+1<n and grid[x+1][y]==1){
                grid[x+1][y]=2;
                q.push({x+1,y});
            }

            //x y+1 right
            if(y+1<m and grid[x][y+1]==1){
                grid[x][y+1]=2;
                q.push({x,y+1});
            }

            //x y-1 left
            if(y-1>=0 and grid[x][y-1]==1){
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or j==0 or i==n-1 or j==m-1) and grid[i][j]==1){
                    bfs(grid,i,j);
                }
            }
        }

        //check if all
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }

        return ans;

    }
};

t.c:-O(n*m) and s.c:-O(n*m) due to queue storage


same question dfs approach

class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x,int y){
        if(grid[x][y]==0) return;
        grid[x][y]=2;

        int n=grid.size();
        int m=grid[0].size();

        //x-1 y up 
            if(x-1>=0 and grid[x-1][y]==1){
                grid[x-1][y]=2;
                dfs(grid,x-1,y);
            }
            
            //x+1 y down
            if(x+1<n and grid[x+1][y]==1){
                grid[x+1][y]=2;
                dfs(grid,x+1,y);
            }

            //x y+1 right
            if(y+1<m and grid[x][y+1]==1){
                grid[x][y+1]=2;
                dfs(grid,x,y+1);
            }

            //x y-1 left
            if(y-1>=0 and grid[x][y-1]==1){
                grid[x][y-1]=2;
                dfs(grid,x,y-1);
            }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or j==0 or i==n-1 or j==m-1) and grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }
        }

        //check if all
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }

        return ans;

    }
};

same t.c and s.c s.c is due to recursive depth alright
