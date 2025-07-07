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





 to suno ager isme ek 0 se sbka distance nikalna hota to ye single source hota right but hme multiple 0's se nikalna hai to ye multisource bfs hai right to
sabhi ko dal do 0's ko ek sath jinse distance nikalna hai ok



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
                    dist[i][j]=0; //we are updating in dist 2d vector not in original mat alright
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


or we can also use the given mat as a vis array if allowed if not then can use upside code


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }


        while(!q.empty()){
            int distance=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};

            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]==1){
                    dist[newi][newj]=distance+1;
                    mat[newi][newj]=0;
                    q.push({distance+1,{newi,newj}});
                }
            }
        }

        return dist;

    }
};

gfg ques of dist of nearest 1 to 0 


 class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }


        while(!q.empty()){
            int distance=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};

            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and mat[newi][newj]==0){
                    dist[newi][newj]=distance+1;
                    mat[newi][newj]=1;
                    q.push({distance+1,{newi,newj}});
                }
            }
        }

        return dist;
    }
}; similar with some changes
