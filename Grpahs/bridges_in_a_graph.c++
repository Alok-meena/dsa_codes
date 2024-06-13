A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected 
 (or more precisely, increases the number of connected components in the graph).




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
