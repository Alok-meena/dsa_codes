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


t.c and s.c ---> linear
