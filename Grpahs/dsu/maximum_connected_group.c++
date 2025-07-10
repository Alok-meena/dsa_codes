Maximum Connected group
Difficulty: HardAccuracy: 49.48%Submissions: 43K+Points: 8Average Time: 30m
You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

Examples :

Input: grid = [1, 1]
             [0, 1]
Output: 4
Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
[1, 1]
[1, 1]
Input: grid = [1, 0, 1]
             [1, 0, 1]
             [1, 0, 1]
Output: 7
Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
[1, 0, 1]
[1, 0, 1]
[1, 1, 1]
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= size of the grid<= 500
0 <= grid[i][j] <= 1






bhai this ques is super easy with dsu and without this u can think how difficut it will be

to khuch nhi hai pahle to nodes ko flat krke sare cc's ki size ko store kr lo and then go at every 0 and update max size of unique ultimate parents 
and return max size but if all 1's return n*n o/w if all 0's then return 1 as maxsize that's it

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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        DisjointSet ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    
                    int dirx[4]={-1,0,0,1};
                    int diry[4]={0,-1,1,0};
                    
                    for(int d=0;d<4;d++){
                        int newi=i+dirx[d];
                        int newj=j+diry[d];
        
                        if(newi>=0 and newi<n and newj>=0 and newj<n and grid[newi][newj]==1){
                            int currnode=(i*n)+j;
                            int neigh=(newi*n)+newj;
                            
                            if(ds.findUPar(currnode)!=ds.findUPar(neigh)){
                                ds.unionBySize(currnode,neigh);
                            }
                        }
                    }
                }
            }
        }
        
        int maxsize=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int size=0;
                if(grid[i][j]==0){
                    
                    int dirx[4]={-1,0,0,1};
                    int diry[4]={0,-1,1,0};
                    
                    set<int>uniqueUPar;
                    
                    for(int d=0;d<4;d++){
                        int newi=i+dirx[d];
                        int newj=j+diry[d];
        
                        if(newi>=0 and newi<n and newj>=0 and newj<n and grid[newi][newj]==1){
                            int neigh=(newi*n)+newj;
                            
                            int ultimate_parent_of_neigh=ds.findUPar(neigh);
                            uniqueUPar.insert(ultimate_parent_of_neigh);
                        }
                    }
                    
                    for(auto up:uniqueUPar){
                        size+=ds.size[up];
                    }
                }
                
                
                maxsize=max(maxsize,size+1);
            }
        }
        
        bool allOne = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    allOne = false;
                    break;
                }
            }
            if(!allOne) break;
        }
        
        if(allOne) return n * n;

        
        return maxsize;
    }
};



t.c:-O(n*n*4) alright and other complexities are negligible
