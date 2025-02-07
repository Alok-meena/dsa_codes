Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges.
Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.



In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'.
The BFS traversal should include all nodes directly or indirectly connected to vertex 0.



Note:
The traversal should proceed from left to right according to the input adjacency list.

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void bfs(vector<int>& ans, unordered_map<int, bool>& visited, vector<vector<int>>& adj, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;//to ye hamne pahle vale source node ke liye externally kr diya and then for loop me to individual kr liye alag se kr hi rhe hai

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        // Store the frontnode into ans
        ans.push_back(frontnode);

        // Traverse all the neighbours of the frontnode
        for (auto i : adj[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                 visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {
    vector<int> ans;
    unordered_map<int, bool> visited;

    // We have to check all the components of the graph

   //include this for loop only if there are components of the graph also otherwise don't include 
    for(int i=0;i<n;i++){ //we have to run this loop for all the nodes so it is run till <n okkkk!
        if(!visited[i]){
            bfs(ans,visited,adj,i);
        }
    }

    //do this if disconnected component is not present 
    bfs(ans,visited,adj,0);
    
    return ans;
}


do this if adjlist is not given and only edges are given


void  preparedAdjList ( unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;// like this because vector of pair is given and in pair to acces 1st value i.first and 2nd value i.second
        int v= edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
     unordered_map<int,bool> visited;
    
    preparedAdjList(adjList,edges);
    // traverse all components


    for(int i =0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i); 
        }
    }
  and the bfs is same as above


Time Complexity
O(n + m), where ‘n’ is the number of vertices and ‘m’ is the number of edges in the input graph.

Space Complexity
O(n), where ‘n’ is the number of vertices.


we can also store the levels into the queue alright like below


#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
       map<int,vector<int>>adj;

       void addEdge(int u,int v,int dir){
          adj[u].push_back(v);

          if(dir==0){
             adj[v].push_back(u);
          }
       }

       void printAdjList(){
          for(auto i:adj){
            cout<<i.first<<"=>";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
          }
       }
};

void dfs(vector<int>adj[],vector<bool>&visited,int curr){
    if(visited[curr]){
        return;
    }

    visited[curr]=true;
    cout<<curr<<" ";

    for(auto neigh:adj[curr]){
        if(!visited[neigh]){
            dfs(adj,visited,neigh);
        }
    }
}

void bfs(vector<int>adj[],vector<bool>&visited,int curr){
    queue<pair<int,int>>q; //{level,node}

    q.push({0,curr});
    visited[curr]=true;


    while(!q.empty()){
        int front=q.front().second;
        int level=q.front().first;
        q.pop();

        cout<<level<<":"<<front<<" ";

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push({level+1,i});
                visited[i]=true;
            }
        }
    }
}

int main(){
    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    int e;
    cout<<"enter the number of edges:";
    cin>>e;

    cout<<"now enter the edges"<<endl;

    vector<int> adj[n+1];

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n+1,false);

    bfs(adj,visited,1);

    // for(int i=1;i<n+1;i++){
    //     if(visited[i]==false){
    //         bfs(adj,visited,i);
    //     }
    // }
}

// 1 2
// 1 3
// 3 2
// 2 4
// 3 4

t.c:-O(n+v) 
