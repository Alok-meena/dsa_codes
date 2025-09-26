Problem statement
You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 10^5
1 <= E <= 3 * 10^5
0 <= X < N
0 <= Y < N
1 <= W <= 10^4

where V and E represent the number of vertices and edges respectively.
X and Y represent the vertices between which there is an edge.
W is the weight of the edge.

Time limit: 1sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
Explanation for Sample Input 1:
The edge (2,3) having weight 8 will be excluded from the MST. The total weight of the MST then will be 1 + 3 + 5 = 9.
Sample Input 2:
4 4
1 2 6
2 3 2
1 3 2
1 0 2
Sample Output 2:
6


this code is if we only have to return the min wt

#include <bits/stdc++.h>

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
   int m=edges.size();
   vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<int>vis(n,0);

    int cost=0;

    while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();

        if(vis[node]) continue;

        vis[node]=1;
        cost+=wt;

        for(auto neigh:adj[node]){
            if(!vis[neigh.first]){
                pq.push({neigh.second,neigh.first});
            }
        }
    }

    return cost;
}


below code is if we hve to build mst also


#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int wt=g[i].second;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<vector<int>>mst;

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,1,-1});
    vector<int>vis(n+1,0);

    int cost=0;

    while(!pq.empty()){
        int parent=pq.top()[2];
        int node=pq.top()[1];
        int wt=pq.top()[0];
        pq.pop();

        if(vis[node]) continue;

        vis[node]=1;
        cost+=wt;
        if(parent!=-1) mst.push_back({parent,node,wt});

        for(auto neigh:adj[node]){
            if(!vis[neigh.first]){
                pq.push({neigh.second,neigh.first,node});
            }
        }
    }

    vector<pair<pair<int,int>,int>>ans;

    for(int i=0;i<mst.size();i++){
        int parent=mst[i][0];
        int node=mst[i][1];
        int wt=mst[i][2];
        ans.push_back({{parent,node},wt});
    }

    return ans;
}
