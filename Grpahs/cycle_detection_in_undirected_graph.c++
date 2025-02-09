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

##using bfs algo

#include <unordered_map>
#include  <list>
#include <queue>

bool iscycleBfs(int src_node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;

    parent[src_node]=-1;//to pahla node tha uske liye -1 kr diya parent ko 
    visited[src_node]=true;
    queue<int>q;

    q.push(src_node);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neighbour:adj[front]){//ye kya krega adj[fornt] ke sare neighbours o access krke check krega code apna
            //this is the condition if cycle is present
            if(visited[neighbour]==true && neighbour!=parent[front]){//yha parent[front] se compare kiya mtlb ki ager front ka parent khi neighbour to nnhi hai na
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>>adj;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;

    //for disconnected components
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscycleBfs(i,visited,adj);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
}

t.c:-linear

Time Complexity
O(N + M), where ‘N’ is the number of vertices and ‘M’ is the number of edges in the graph.

 

In the worst case, we are visiting each vertex and edge of the graph only once. Hence, the time complexity is O(N + M).

Space Complexity
O(N), where ‘N’ is the number of vertices in the graph.

 

We are using an extra array to keep track of visited vertices and in the worst case, the size of the queue can go up to ‘N’.
Hence, the space complexity is O(N). 


##using dfs


bool iscycleDfs(int node,int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    visited[node]=true;

    for(auto neighbour:adj[node]){//to ye vala loop adjlist ke node ke sare neighbours ko ek ek krke access krega
        if(!visited[neighbour]){
            bool ans=iscycleDfs(neighbour,node,visited,adj);//aor yha hmara  node hai neighbour aor iska parent current node hai
            //example 1->2 so 2 is the neighbour and 1 is the parent 
            if(ans){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>>adj;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;

    //for disconnected components
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscycleDfs(i,-1,visited,adj);//pahle node ka parent to -1 hoga to pass kr diya
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
}


below one is written by me second time 


#include <bits/stdc++.h>

bool dfs(vector<int> adj[],vector<bool>&visited,unordered_map<int,int>&node_to_parent,int currnode){
    visited[currnode]=true;


    for(auto neigh:adj[currnode]){
        if(!visited[neigh]){
            node_to_parent[neigh]=currnode;
             ///to yha pe check also o/w if u directly return it then it will not check the adjacent nodes okk
            if(dfs(adj,visited,node_to_parent,neigh)) return true;
        }
        else if(visited[neigh] and neigh!=node_to_parent[currnode]) return true;
    }
    
    return false;
}

bool bfs(vector<int> adj[],vector<bool>&visited,int currnode){
    queue<int>q;
    unordered_map<int,int>node_to_parent;

    q.push(currnode);
    visited[currnode]=true;

    node_to_parent[currnode]=-1;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neigh:adj[front]){
            if(!visited[neigh]){
                visited[neigh]=true;
                q.push(neigh);
                node_to_parent[neigh]=front;
            }
            else if(visited[neigh] and neigh!=node_to_parent[front]) return true; //here we can directly return our ans in bfs alright
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n+1,false);
        unordered_map<int,int>node_to_parent;
        node_to_parent[1]=-1;


    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            bool cycle=dfs(adj,visited,node_to_parent,i);
            if(cycle) return "Yes";
        }
    }

    return "No";
}

same t.c and s.c


and here we have to take n+1 size as the nodes are from 1 not zero


