A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected 
 (or more precisely, increases the number of connected components in the graph).



in leetcode critical n/w connections same code will be used like below



1192. Critical Connections in a Network
Solved
Hard
Topics
premium lock icon
Companies
Hint
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.



 


#include <unordered_map>
#include <list>
#include <vector>
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;//ignore this case
        }
        //check edge is brige or not
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            //call se vapas aate time update the node low time with it's nbr low time
            low[node]=min(low[node],low[nbr]);
            //check edge is bridge
            if(low[nbr]>disc[node]){//low[nbr]<disc[node] means ki nbr esi node se connected hai jo hmari node se pahle aati hai
                result.push_back({node,nbr});
            }
        }
        else{
            //edge case
            low[node]=min(low[node],disc[nbr]);
        }
    }

}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>>adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int>disc(v);//time required to reach a node
    vector<int>low(v);//earliest/lowest time possible to reach a node
    int parent=-1;
    unordered_map<int,bool>visited;

    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }

    vector<vector<int>>result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }

    return result;

}


t.c:-O(V+E)
  s.c:-O(V)



 2nd time

#include <bits/stdc++.h>


void dfs(int curr,int &timer,vector<int> adj[],vector<int>&discoveryTime,vector<int>&lowestTime,vector<int>&nodeToparent,vector<int>&vis,vector<vector<int>>&ans){
    vis[curr]=1;
    discoveryTime[curr]=lowestTime[curr]=timer++;

    for(auto neigh:adj[curr]){
        if(neigh==nodeToparent[curr]){
            continue;
        }
        else if(!vis[neigh]){
            nodeToparent[neigh]=curr;
            dfs(neigh,timer,adj,discoveryTime,lowestTime,nodeToparent,vis,ans);
            // return hoke aane ke bad update kr do khud k low neigh ke low se because it is possible ki neigh tk aane k koi aor rsta bhi ho 
            //because vhi ex lo 0 - 1 0 -2 0-3 3-4 okk to jb ham 2 se vapas 1 pe aaaye with (1\1) okk to ager curr ka low update kre bina hi ager ham lot jaye
            //to jb 0 pe (0\0)  brdige ki codntion check hogi to true aa jayega 1>0 mtlb 1 tk jane k yhi ek rsta tha but esa nhi hai to ager 1 tk jane k koi aor
            //chota rsta hai hai to update kro and we will know ki ye bridge nhi hai tik hai bs yhi imp hai okk
            lowestTime[curr]=min(lowestTime[curr],lowestTime[neigh]);

            //check if bridge aor bhai brdige ke time pe jab aap vapas aaye to apko ye dekhna hai ager neigh k low bda hai khud se to mtlb us tk jane
            //ka yhi ek rsta hai to ye bridge k edge hai but ager nhi to koi aor rsta bhi hai that's why us tk ja skte y nhi to uske sath low check krna hai 
            //khud ka nhi 
            if(lowestTime[neigh]>discoveryTime[curr]){
                ans.push_back({curr,neigh});
            }
        }
        else{
            //back edge (vis bhi hai aor parent bhi nhi hai to apne low times ko uske disc time se update kr lo)
            lowestTime[curr]=min(lowestTime[curr],discoveryTime[neigh]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<int> adj[v];

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>discoveryTime(v,-1);
    vector<int>lowestTime(v,-1);
    vector<int>nodeToparent(v);
    vector<int>vis(v,0);
    vector<vector<int>>ans;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            int timer=0;
            dfs(i,timer,adj,discoveryTime,lowestTime,nodeToparent,vis,ans);
        }
    }

    return ans;

}
