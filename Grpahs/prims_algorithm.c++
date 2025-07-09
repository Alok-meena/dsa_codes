 Prim's MST
Moderate
80/80
Average time to solve is 15m
91 upvotes
Asked in companies
Problem statement
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.

For example :

The MST (Minimum Spanning Tree) for the above graph is:

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(1000, N(N - 1) / 2)
1 <= E[i][0], E[i][1] <= N


Time Limit: 1 sec
Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
Explanation of Input 1 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.
Sample Input 2 :
1
5 15
1 2 21
1 4 16
2 1 12
2 3 13
2 4 18
2 5 15
3 2 13
3 5 17
4 1 16
4 2 18
4 5 19
5 1 18
5 2 15
5 3 17
5 4 19
Sample Output 2 :
1 2 12
1 4 16
2 3 13
2 5 15
Explanation of Input 2 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 12, (1,4) with weight 16, (2,3) with weight 13 and (2,5) with weight 15.



    

#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <limits.h>
#include <vector>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adjacency list
    unordered_map<int,list<pair<int,int>>>adjlist;

    for(int i=0;i<m;i++){
        int u=g[i].first.first; //yha -1 karna ager test cases me nodes 0 se start hai 
        int v=g[i].first.second;
        int w=g[i].second;

        adjlist[u].push_back(make_pair(v,w));
        adjlist[v].push_back(make_pair(u,w));
    }

    //sbko n+1 se initialize kiya because we are doing index 1 to 1 because nodes start from 1 only
    vector<int>key(n+1);//in this we will store the weights of the edges
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    
    for(int i=1;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }

    //algo started
    //in this question our source node is 1 that's why hamne adjlist me -1 nhi kiya ager source node 0 hoti to ham krte
    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<=n;i++){
        int u;
        int mini=INT_MAX;

        //finding min value node and it is from 1 to equal to n okkk
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }

        mst[u]=true;

        //visiting neighbouring nodes
        for(auto i:adjlist[u]){
            int v=i.first;
            int w=i.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    //0 se nhi chalaya because node 1 se start hai and 1 se bhi nhi because 1 ke parent -1 hai so 2 se start kiya hai taki ho ske to 2 ka parent 1 ho jaye
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i], i}, key[i]});// we do like this because hme output is format me hi dena hai ((parent,node),weight) bhai ager edge
        //show krni hai 1->2 to 2 k parent to 1 hai to parent[2],2 ===>  parent[i],i alright
    }
    return ans;
}
t.c:-o(n^2)

we can optimize this code using minheap (priority queue) then t.c:-O(nlogn)


  #include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjlist;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Min-heap priority queue (key value, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize source node
    key[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        // Get the node with the smallest key value
        int u = pq.top().second;
        pq.pop();

        // Mark this node as included in MST
        mst[u] = true;

        // Traverse all adjacent nodes of u
        for (auto neighbor : adjlist[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and weight of (u, v) is smaller than current key of v
            if (!mst[v] && weight < key[v]) {
                // Update key of v
                key[v] = weight;
                // Update parent of v
                parent[v] = u;
                // Push updated key and node into the priority queue
                pq.push(make_pair(key[v], v));
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        if (parent[i] != -1) {
            ans.push_back({{parent[i], i}, key[i]});
        }
    }
    return ans;
}



2nd time 

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>>adj[n+1];

    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>dist(n+1,1e9);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    dist[1]=0;

    for(int i=1;i<=n;i++){ 
        int mini=INT_MAX;
        int node;

        for(int i=1;i<=n;i++){
            if(mst[i]==false and dist[i]<mini){
                node=i;
                mini=dist[i];
            }
        }

        mst[node]=true;

        //check all adjacent nodes
        for(auto neigh:adj[node]){
            int v=neigh.first;
            int wt=neigh.second;

            if(mst[v]==false and wt<dist[v]){
                parent[v]=node;
                dist[v]=wt;
            }
        }
    }

    vector<pair<pair<int,int>,int>>ans;
    for(int i=2;i<=n;i++){ //sari nodes 1 se start hoti hai to 0 se nhi and 1 ka parent -1 so start from 2 okk
        ans.push_back({{parent[i],i},dist[i]});
    }

    return ans;


}

t.c O(n^2) and s.c:-O(n+m) and can be optimized using priority queue

optimized using priority queue then t.c :-O(mlogn) alright because n nodes are pushed into the queue not m edges okk so nlogn+mlogn = mlogn

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

    //prepare key , mst , parent vectors

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    key[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        

        mst[node]=true;

        for(auto neigh:adj[node]){
            int u=neigh.first;
            int wt=neigh.second;
            if(mst[u]==false and wt<key[u]){
                key[u]=wt;
                parent[u]=node;
                pq.push({key[u],u});
            }
        }
    }

    vector<pair<pair<int,int>,int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }

    return ans;
}

  
