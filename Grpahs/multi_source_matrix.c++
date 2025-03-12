542. 01 Matrix
Solved
Medium
Topics
Companies
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.








class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        queue<vector<int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    vis[i][j]=true;
                    q.push({i,j,0});
                }
            }
        }

        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();

            int i=v[0];
            int j=v[1];
            int step=v[2];

            dist[i][j]=step;

            int dirx[]={-1,0,0,1};
            int diry[]={0,-1,1,0};

            for(int k=0;k<4;k++){
                int newi=i+dirx[k];
                int newj=j+diry[k];

                if(newi>=0 and newi<n and newj>=0 and newj<m and vis[newi][newj]==false){
                    vis[newi][newj]=true;
                    q.push({newi,newj,step+1});
                }
            }
        }

        return dist;
    }
};

t.c is n*m and s.c is also n*m

will work normally if the dist is updated inside the loop also 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        queue<vector<int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    vis[i][j]=true;
                    q.push({i,j,0});
                }
            }
        }

        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();

            int i=v[0];
            int j=v[1];
            int step=v[2];


            int dirx[]={-1,0,0,1};
            int diry[]={0,-1,1,0};

            for(int k=0;k<4;k++){
                int newi=i+dirx[k];
                int newj=j+diry[k];

                if(newi>=0 and newi<n and newj>=0 and newj<m and vis[newi][newj]==false){
                    vis[newi][newj]=true;
                    dist[newi][newj]=step+1;
                    q.push({newi,newj,step+1});
                }
            }
        }

        return dist;
    }
};
