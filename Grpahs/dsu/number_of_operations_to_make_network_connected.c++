Connecting the graph
Difficulty: MediumAccuracy: 52.79%Submissions: 23K+Points: 4Average Time: 30m
You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
If it is not possible to connect the graph, return -1.

Example 1: 

Input:
n = 4
m = 3
Edges = [ [0, 1] , [0, 2] , [1, 2] ]
Output:
1
Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
 

Example 2:

Input:
n = 6
m = 5
Edges = [ [0,1] , [0,2] , [0,3] , [1,2] , [1,3] ]
Output:
2
Explanation:
Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)
 
Your Task:
You don't need to read or print anything. Your task is to complete the function Solve() which takes an integer n denoting a number of vertices and a 2d matrix denoting the edges of a graph and returns the minimum number of operations to connect a graph.

Expected Time Complexity: O(m*n)
Expected Space Complexity: O(m*n)

Constraints:
1<=n<=105
0<=m<=102
1<=edge[i][0],edge[i][1]<=n-1










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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int extraedges=0;
        
        for(int i=0;i<edge.size();i++){
            int u=edge[i][0];
            int v=edge[i][1];
            
            if(ds.findUPar(u)==ds.findUPar(v)) extraedges++;
            else ds.unionByRank(u,v);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        
        if(extraedges>=cnt-1) return cnt-1;
        else return -1;
    }
};


Time Complexity: O(m + n)
✔ Space Complexity: O(m + n)
