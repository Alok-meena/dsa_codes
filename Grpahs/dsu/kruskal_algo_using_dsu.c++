Minimum Spanning Tree - Kruskal's Algorithm
Difficulty: MediumAccuracy: 69.19%Submissions: 7K+Points: 4
Given a weighted, undirected, and connected graph with V vertices and E edges, the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm. The graph is represented as an edge list edges[][], where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.

Input: V = 3, E = 3, edges[][] = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]

Output: 4
Explanation:

The Spanning Tree resulting in a weight of 4 is shown above.
Input: V = 2, E = 1, edges = [[0, 1, 5]]
  
Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.



t.c:-O(nlogn+4*alpha)

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
    int kruskalsMST(int V, vector<vector<int>> &edge) {
        // code here
        int n=V;
        vector<pair<int,pair<int,int>>>edges;

      
    //O(n+e)
    for(int i=0;i<edge.size();i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());  //sorting edges based on weights to get mst alright
    int mstwt=0;

    DisjointSet ds(n);

    //O(m*2*4*apha)
    for(int i=0;i<edge.size();i++){
        int wt=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;

        if(ds.findUPar(u)!=ds.findUPar(v)){
            mstwt+=wt;
            ds.unionBySize(u,v);
        }
    }

    return mstwt;
    }
};

here we just have to return the minweight so returned it 

if u and v does not belong to same compo then merge them by size / rank and if belong to same compo then skip them alright




and if we have to return {{u,v},wt} of mst then code is ( for coding ninja also )

#include <bits/stdc++.h>

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
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int wt=g[i].second;

        edges.push_back({wt,{u,v}});
    }

    vector<pair<pair<int,int>,int>>mst;

    sort(edges.begin(),edges.end());
    int mstwt=0;

    DisjointSet ds(n);

    for(int i=0;i<m;i++){
        int wt=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;

        if(ds.findUPar(u)!=ds.findUPar(v)){
            mst.push_back({{u,v},wt});
            ds.unionBySize(u,v);
        }
    }

    return mst;
}


same t.c and s.c
