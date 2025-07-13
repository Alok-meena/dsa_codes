
Code
Testcase
Testcase
Test Result
Q2. Minimize Maximum Component Cost
Solved
Medium
4 pt.
You are given an undirected connected graph with n nodes labeled from 0 to n - 1 and a 2D integer array edges where edges[i] = [ui, vi, wi] denotes an undirected edge between node ui and node vi with weight wi, and an integer k.

You are allowed to remove any number of edges from the graph such that the resulting graph has at most k connected components.

The cost of a component is defined as the maximum edge weight in that component. If a component has no edges, its cost is 0.

Return the minimum possible value of the maximum cost among all components after such removals.

 

Example 1:

Input: n = 5, edges = [[0,1,4],[1,2,3],[1,3,2],[3,4,6]], k = 2

Output: 4

Explanation:



Remove the edge between nodes 3 and 4 (weight 6).
The resulting components have costs of 0 and 4, so the overall maximum cost is 4.
Example 2:

Input: n = 4, edges = [[0,1,5],[1,2,5],[2,3,5]], k = 1

Output: 5

Explanation:



No edge can be removed, since allowing only one component (k = 1) requires the graph to stay fully connected.
That single component’s cost equals its largest edge weight, which is 5.
 

Constraints:

1 <= n <= 5 * 104
0 <= edges.length <= 105
edges[i].length == 3
0 <= ui, vi < n
1 <= wi <= 106
1 <= k <= n
The input graph is connected.©leetcode






class DisjointSet{
    public:
    vector<int>parent,rank;

    DisjointSet(int size){
        parent.resize(size+1);
        rank.resize(size+1,0);

        for(int i=0;i<size+1;i++){
            parent[i]=i;
        }
    }

    int findUPar(int u){
            if(parent[u]==u) return u;
            return parent[u]=findUPar(parent[u]);
        }

        void unionByRank(int u,int v){
            int up=findUPar(u);
            int vp=findUPar(v);

            if(up==vp) return;

            if(rank[up]<rank[vp]){
                parent[up]=vp;
            }
            else if(rank[vp]<rank[up]){
                parent[vp]=up;
            }
            else{
                parent[vp]=up;
                rank[up]++;
            }
        }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int,pair<int,int>>>edge;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            edge.push_back({wt,{u,v}});
        }


        sort(edge.begin(),edge.end());

        DisjointSet ds(n);

        int components=n;
        int maxedgeused=0;

        for(int i=0;i<edge.size();i++){
            int u=edge[i].second.first;
            int v=edge[i].second.second;
            int wt=edge[i].first;

            if(ds.findUPar(u)==ds.findUPar(v)) continue;

            ds.unionByRank(u,v);
            maxedgeused=max(maxedgeused,wt);
            components--;

            if(components==k) break;
        }

        if(k>=n) return 0;

        return maxedgeused;
        
        
    }
};©leetcode khuch nhi min of all edeg wt chaihe to mst lga diya that's it and as total compo are equal to k then we are returning maxedge wt

  or instead of compo=n

  we can count total compo at each step of loop like below 

int components = 0;
for (int i = 0; i < n; i++) {
    if (ds.findUPar(i) == i) components++;  // root node
}
