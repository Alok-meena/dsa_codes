Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges,
the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.

IMPORTANT:----->>
"How does DFS work?
Depth-first search is an algorithm for traversing or searching tree or graph data structures.
The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible
along each branch before backtracking."


#include <unordered_map>
#include <list>
#include <vector>
void prepareadjlist(unordered_map<int,list<int>>&adj,vector<vector<int>>&edges,int m){

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjlist,vector<int>&component){
    component.push_back(node);

    visited[node]=true;
    
    //recursive call for each connected component
    for(auto i:adjlist[node]){
        if(!visited[i]){
            dfs(i,visited,adjlist,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>>adjlist;
    
    //prepare adjacency list
    prepareadjlist(adjlist,edges,E);

    vector<vector<int>>ans;

    unordered_map<int,bool>visited;
    

    //call dfs if node is not visited 
    //this for loop is for disconnected components
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;//we have to return vector<vector<int> so we have created ans of this type and we store our ans in component of vector type 
            //and then storing component in ans and returning ans
            dfs(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }
    return ans;
}


t.c and s.c ---> linear O(v+e) t.c and s.c


if we have undirected disconnected graph the we have to return all traversal possible 

void dfs(vector<int> adj[], vector<bool>& visited, vector<int>& component, int curr) {
    if (visited[curr]) return;

    component.push_back(curr);
    visited[curr] = true;

    for (auto i : adj[curr]) {
        if (!visited[i]) {
            dfs(adj, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> ans;
    
    vector<int> adj[V+1];  // ? Correct for 1-based indexing
    vector<bool> visited(V+1, false);  // ? Must also be of size V+1

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= V; i++) {  // ? Start from 1 (not 0)
        if (!visited[i]) {
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}



written by me 


class Solution {
public:
    void dfs(int n,vector<vector<int>>&graph,vector<bool>&visited,int curr){
        if(visited[curr]==true) return;

        visited[curr]=true;

        for(int i=0;i<graph.size();i++){
           //here first we have to check that if there is a edge b/w curr and it's neighbour then only go to check the dfs function okk
            if(graph[curr][i]==1){
                if(visited[i]==false) dfs(n,graph,visited,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n+1,false);
        int connected=0;

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                connected++;
                dfs(n,isConnected,visited,i);
            }
        }

        return connected;
    }
};
