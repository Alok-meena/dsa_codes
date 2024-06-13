Using Kosaraju's Algorithm

You are given an unweighted directed graph having 'V' vertices and 'E' edges. 
Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. 
The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.

The given graph doesn’t contain any self-loops.

#include <unordered_map>
#include <list>
#include <vector>
#include <stack>

void dfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,stack<int>&st){
	visited[node]=true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(nbr,adj,visited,st);
		}
	}
	//topological sort logic
	st.push(node);
}

void newDfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
	visited[node]=true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			newDfs(nbr,visited,adj);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		
		//because directed graph is given
		adj[u].push_back(v);
	}

	stack<int>st;
	unordered_map<int,bool>visited;

    //topological sort dfs call
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,adj,visited,st);
		}
	}

    //creating transpose of the old graph
	unordered_map<int,list<int>>transpose;
	for(int i=0;i<v;i++){
		visited[i]=0;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	int count=0;

	//dfs call using above 
	while(!st.empty()){
		int top=st.top();
		st.pop();

		if(!visited[top]){
			count++;
			newDfs(top,visited,transpose);
		}
	}
	return count;
}


t.c:-O(E+V) and s.c:-O(V)
