Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’,
vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG.
Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

For example, Consider the DAG shown in the picture.


In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3.
Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.

So, The topological sorting of this DAG is {0 1 3 2}.

Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}

Note:
1. It is guaranteed that the given graph is DAG.
2. There will be no multiple edges and self-loops in the given DAG.
3. There can be multiple correct solutions, you can find any one of them. 
4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.



#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
void prepareadjlist(unordered_map<int,list<int>>&adj,vector<vector<int>>&edges,int m){

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
}
void dfs_topologicalsort(int node,vector<bool>&visited,unordered_map<int,list<int>>&adjlist,stack<int>&s){
    visited[node]=true;
    
    //recursive call for each connected component
    for(auto i:adjlist[node]){
        if(!visited[i]){
            dfs_topologicalsort(i,visited,adjlist,s);
        }
    }
    // Push vertex in stack after pushing all its adjacent (and their adjacent and so on) verices.
    //to return krte time hmne stack me push kr diya hai 
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    unordered_map<int,list<int>>adjlist;
    
    //prepare adjacency list
    prepareadjlist(adjlist,edges,e);
    vector<bool>visited(v);
    

    //call dfs if node is not visited 
    //this for loop is for disconnected components
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs_topologicalsort(i,visited,adjlist,s);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

