994. Rotting Oranges
Solved
Medium
Topics
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.










if this problem is for single source orange then we should the below code

so if there is single rotten orange within a single component then the below code will run definitely 

class Solution {
public:
    int bfs(vector<vector<int>>& grid,int x,int y){
        queue<pair<int,int>>q;
        q.push({x,y});
        int level=0;

        while(q.size()!=0){
            int size=q.size();
            level++;

          
            for(int k=0;k<size;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                //i j+1 right and this bound checking of column should be as per to the no. of columns only
                if(j+1<grid[i].size() and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }

                //i j-1 left
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }

                //i-1 j up 
                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }

                //i+1 j down
                if(i+1<grid.size() and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
            }
        }

        return level-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int maxtime=-1;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    int time=bfs(grid,i,j);
                    maxtime=max(maxtime,time);
                }
            }
        }

        //checking if all become rotten or not

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return maxtime;
    }
};


but if there are multiple sources then we should have to process all of the sources parallelly at the same time right 



so below code should be used

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int maxtime=-1;

          queue<pair<int,int>>q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        //checking if all become rotten or not
        int level=0;

        while(q.size()!=0){
            int size=q.size();
            level++;
          //to dekho yha pe ham ek level pe multiple rotten oranges se kam krva rhe hai that's why it is multisource bfs alright
         //to ek bar me sare rotten orange jo queue me hai unhe use kro means use q.size of current ookk

            for(int k=0;k<size;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                //i j+1 right and this bound checking of column should be as per to the no. of columns only
                if(j+1<grid[i].size() and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }

                //i j-1 left
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }

                //i-1 j up 
                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }

                //i+1 j down
                if(i+1<grid.size() and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
            }
        }


        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }

        if(level==0) return 0;

        return level-1;
    }
};


t.c:-O(n*m) and s.c:-O(N*m) 



 little short code

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int mintime=0;


        while(!q.empty()){
            int size=q.size();
            mintime++;

            for(int k=0;k<size;k++){
                pair<int,int> p=q.front();
                int i=p.first;
                int j=p.second;

                q.pop();


                int dirx[]={-1,0,0,1};
                int diry[]={0,-1,1,0};
                
                for(int d=0;d<4;d++){
                    int newi=i+dirx[d];
                    int newj=j+diry[d];

                    if(newi>=0 and newi<m and newj>=0 and newj<n and grid[newi][newj]==1){
                        grid[newi][newj]=2;
                        q.push({newi,newj});
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return mintime==0?0:mintime-1;  //to ans ko mintime-1 hi bhejna pdega u can dryrun on [2 1 1][1 1 0][0 1 1] alright ans 5 aayega but should be 5
     //as hamne 0th level ko pahle hi 1 kr diya i mean rotten orange k count nhi krna hme okk
    }
};
