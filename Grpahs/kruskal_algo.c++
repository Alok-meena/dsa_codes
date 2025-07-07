You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected,
edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

#include <bits/stdc++.h> 
#include <algorithm>


// Comparator for sorting edges in increasing order of their weights
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void makeset(vector<int>&parent,vector<int>&rank,int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

//and it will be done in o(1) time okk
int findParent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    //to node ko direct root pe attack krne ke liye use parent[node]= ok!
    //to suno meri bat uper se hme parent node milegi jo ki parent hai to ab ham us node ko directly uske parent pe lga denge to parent[node] = node jo function
   // return krega as a parent and it is known as path compression (*******ye karne se hmne time ko constant me convert kr diya hai)
    //aor function me bhi parent[node] pass kiya hai because iska hi to parent nikalna hai
    return parent[node]=findParent(parent,parent[node]);
}


//it will also take constant time O(1) time
void unionSet(vector<int>&parent,vector<int>&rank,int u,int v){
    u=findParent(parent,u);
    v=findParent(parent,v);

    //to ager rank km hai to usko jyada rank ka child bna do
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int>parent(n);
  vector<int>rank(n);
  makeset(parent,rank,n);

  int minimum_weight=0;
  for(int i=0;i<edges.size();i++){
      int u=findParent(parent,edges[i][0]);
      int v=findParent(parent,edges[i][1]);
      int weight=edges[i][2];

      if(u!=v){
          minimum_weight+=weight;
          unionSet(parent,rank,u,v);
      }
  }
  return minimum_weight;
    
}



O(V) time is taken to initialize the parent of each vertex and O(E) time is taken to set the parents of each vertex in the two connected subtrees 
to be equal for all edges. 

 

Therefore the overall time complexity is O(E * log(V))

Space Complexity
O(E) to store the edges and O(V) to store the parents of each vertex.

 

Therefore the overall space complexity is O(E + V).




or can also do like 

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
