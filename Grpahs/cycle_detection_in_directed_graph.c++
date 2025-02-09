Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3. 

Note:

1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3.
So, there exists a cycle in the graph. 




#include <unordered_map>
#include <list>

bool isdfs_cycle(int node,unordered_map<int,bool>&visited,  unordered_map<int,bool>&dfs_visited
,unordered_map<int,list<int>>&adjlist){
  visited[node]=true;
  dfs_visited[node]=true;//to bs jaise hi kisi node ke liye ye function call hua to hmne isko true kr diya hai

  for(auto neighbour:adjlist[node]){
    if(!visited[neighbour]){
      bool ans=isdfs_cycle(neighbour,visited,dfs_visited,adjlist);
      if(ans){
        return true;
      }
    }
    else if(dfs_visited[neighbour]){//condition for cycle detection if both visited and dfs_visited are true;
      return true;
    }
  }
  dfs_visited[node]=false;//and return krte time isko false bhi karna hai 
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //creating adjlist
  unordered_map<int,list<int>>adjlist;

  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjlist[u].push_back(v);
  }

  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfs_visited;//iski help se hi hme pta chlega ki cycle hai ya nhi

  for(int i=0;i<n;i++){
    if(!visited[i]){
      bool ans=isdfs_cycle(i,visited,dfs_visited,adjlist);
      if(ans){
        return true;
      }
    }
  }
  return false;

}

t.c :-O(n+m) s.c:-O(n)



using bfs and kahn's algo


#include <unordered_map>
#include <list>
#include <queue>



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>>adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;//because nodes 1 se start thi to hamne 0 se krva di ya do niche indegree ka loop 1 se <=n tk le jao
        int v=edges[i].second-1;

        adjlist[u].push_back(v);
    }
   
    //find all indegrees
    vector<int>indegree(n);
    for(auto i:adjlist){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int>q;
    //0 indegree valo ko push krdo
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //do bfs

    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        count++;

        //neighbours indgree update
        for(auto neighbours:adjlist[front]){
            indegree[neighbours]--;
            if(indegree[neighbours]==0){
                q.push(neighbours);
            }
        }
    }
    //if valid topological sort then no cycle present 
    //if n no. of nodes are there in topological sort then it measn no cycle
    if(count==n){
      return false;
    }
    //otherwise cycle is present if wrong topological sort is there
    else{//we assumed that if invalid topological sort then it's nodes will not be equal to n
      return true;
    }

}




done second time by me

#include <bits/stdc++.h>

bool dfs(vector<int> adj[],vector<bool>&visited,unordered_map<int,int>&node_to_parent,int currnode,vector<bool>&dfsCall){
    visited[currnode]=true;
    dfsCall[currnode]=true; //we have to mark it true as soon as we start the dfs call for the currnode right and after loop when we return we have
    //have to mark it false also remember 

    //and here we cant use the approach of undirected graph u all know why okk u can check it by dry run 


    for(auto neigh:adj[currnode]){
        if(!visited[neigh]){
            node_to_parent[neigh]=currnode;
            if(dfs(adj,visited,node_to_parent,neigh,dfsCall)) return true;
        }
        else if(visited[neigh] and dfsCall[neigh]) return true;
    }

    dfsCall[currnode]=false;
    
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<bool>visited(n+1,false);
    unordered_map<int,int>node_to_parent;
    node_to_parent[1]=-1;

    vector<bool>dfsCall(n+1,false);


    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            bool cycle=dfs(adj,visited,node_to_parent,i,dfsCall);
            if(cycle) return 1;
        }
    }

    return 0;
}
