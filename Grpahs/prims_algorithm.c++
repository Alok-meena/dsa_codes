

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
        ans.push_back({{parent[i], i}, key[i]});// we do like this because hme output is format me hi dena hai ((parent,node),weight)
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

  
