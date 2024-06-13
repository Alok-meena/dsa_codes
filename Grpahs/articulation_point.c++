if removing a vertex and its related edges causes the graph to become disconnected,
the vertex is considered to be an articulation point in the graph.
Therefore, the number of related components in a graph grows as articulation points are removed.
A connected component, or simply component, is a subgraph where every pair of nodes is connected to every other node by a path.


  #include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int node,int parent,vector<int>&dis,vector<int>&low,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,vector<int>&ap,int &timer){
    vis[node]=true;
    dis[node]=low[node]=timer++;
    int child=0;//case for the root node which is parent to all

    for(auto nbr:adj[node]){
        if(parent==nbr){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,dis,low,vis,adj,ap,timer);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>=dis[node] && parent!=-1){
                ap[node]=true;
            }
            child++;
        }
        else{
            low[node]=min(low[node],dis[nbr]);
        }
    }
    if(parent==-1 && child>1){
        ap[node]=true;
    }
}

int main(){
    //nodes and edges
    //nodes
    int n=5;
    int e=5;

    
    vector<pair<int,int>>edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));

    edges.push_back(make_pair(0,4));

    edges.push_back(make_pair(0,1));

    edges.push_back(make_pair(1,2));


    //adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int>disc(n);
    vector<int>low(n);
    unordered_map<int,bool>visited;

    vector<int>ap(n,0);//means of n size and each element initialized with 0
    
    for(int i=0;i<n;i++){
        disc[i]=-1;
        low[i]=-1;
    }

    //dfs
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,-1,disc,low,visited,adj,ap,timer);
        }
    }
    
    //printing articulation points
    cout<<"articulation points are as follows"<<endl;
    //hamne indices prin kiya because ham to only nodes ko true kr rhe hai okk
    
    for(int i=0;i<n;i++){
        if(ap[i]!=0){
            cout<<i<<" ";
        }
    }

    return 0;
}

//time complexity:-O(N+E);
//spcae complexity:-O(N);
