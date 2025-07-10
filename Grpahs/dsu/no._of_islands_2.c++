Number Of Islands
Difficulty: MediumAccuracy: 60.65%Submissions: 56K+Points: 4Average Time: 30m
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
 

 

Example 2:

Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000



this is similar to islands 1 problem we can apply the operations and do bfs and count no. of islands after each operation alright

// User function Template for C++
class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newi=x+dirx[d];
                int newj=y+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==1){
                    grid[newi][newj]=0;
                    q.push({newi,newj});
                }
            }
        }
    }
    int numIslands(vector<vector<int>>grid) {
        int islands=0;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    islands++;
                    bfs(i,j,grid);
                }
            }
        }

        return islands;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>grid(n,vector<int>(m,0));
        
        vector<int>ans;
        
        for(int i=0;i<operators.size();i++){
            int u=operators[i][0];
            int v=operators[i][1];
            
            grid[u][v]=1;
            
            int lands=numIslands(grid);
            ans.push_back(lands);
        }
        
        return ans;
        
    }
};


but it's t.c is too high O(n*m*k) as in k operations everytime n*m is performed by bfs alright


optimized using dsu O(n*m*4alpha)



// User function Template for C++
class DisjointSet{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int size){
        rank.resize(size+1,0);
        parent.resize(size+1);
        this->size.resize(size+1,1);
        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }

    //finding ultimate parent and  path compression
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        //if belong to same compo with same ultimate paretn then no need to do their unio alright
        if(up==vp) return;

        int rank_up=rank[up];
        int rank_vp=rank[vp];

        if(rank_up<rank_vp){
            parent[up]=vp;
        }
        else if(rank_vp<rank_up){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }

    void unionBySize(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        //if belong to same compo with same ultimate paretn then no need to do their unio alright
        if(up==vp) return;

        int size_up=size[up];
        int size_vp=size[vp];

        if(size_up<size_vp){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        } //else me equal ho ya chota koi sa bhi lga skte to ye lga diya alright
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        
        vector<vector<int>>vis(n,vector<int>(m,0)); //and yha ham is vis array ko hi as a given matrix use kr rhe hai jha 1 kiya vo visited
        vector<int>ans;
        
        int cnt=0;
        
        for(int i=0;i<operators.size();i++){
            int row=operators[i][0];
            int col=operators[i][1];

            //if already vis is coming so just push cnt ans skip
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }

            //visit it and increase the count alright because we are assuming it as a separate island but we will update if it is connected to any nearby island alright
            vis[row][col]=1;
            cnt++;
            
            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
            
            for(int d=0;d<4;d++){
                int newr=row+dirx[d];
                int newc=col+diry[d];

                //checking all 4 directions and if it is 1 then check both parents if both have same parents means both are connected to same compo so do nothing
                //o/w do union of both and decrement count as it cannot contribute as a separate island alright and at last push ans again  and return alright
                
                if(newr>=0 and newr<n and newc>=0 and newc<m and vis[newr][newc]==1){
                    int currnode=(row*m)+col;
                    int neigh=(newr*m)+newc;
                    
                    if(ds.findUPar(currnode)!=ds.findUPar(neigh)){
                        cnt--;
                        ds.unionByRank(currnode,neigh);
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
