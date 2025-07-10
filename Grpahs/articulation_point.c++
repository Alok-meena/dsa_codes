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
    int child=0;//case for the root node which is parent to all bhai ye vo case hai 
    //ager parent -1 hai and child >1 hai to ye bhi ap hai alright ap== articulation point

    for(auto nbr:adj[node]){
        if(parent==nbr){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,dis,low,vis,adj,ap,timer);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>=dis[node] && parent!=-1){ //just modified condition and can dry run
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



for coding ninja code 


#include<bits/stdc++.h>
using namespace std;

void dfs(int curr,int &timer,vector<int> adj[],vector<int>&discoveryTime,vector<int>&lowestTime,vector<int>&nodeToparent,vector<int>&vis,vector<int>&ans){
    vis[curr]=1;
    discoveryTime[curr]=lowestTime[curr]=timer++;

    int child=0;

    for(auto neigh:adj[curr]){
        if(neigh==nodeToparent[curr]){
            continue;
        }
        else if(!vis[neigh]){
            nodeToparent[neigh]=curr;
            dfs(neigh,timer,adj,discoveryTime,lowestTime,nodeToparent,vis,ans);
            lowestTime[curr]=min(lowestTime[curr],lowestTime[neigh]);

            //check if bridge
            if(lowestTime[neigh]>=discoveryTime[curr] and nodeToparent[curr]!=-1){
                ans[curr]=1;
            }
            child++;
        }
        else{
            //back edge (vis bhi hai aor parent bhi nhi hai)
            lowestTime[curr]=min(lowestTime[curr],discoveryTime[neigh]);
        }
    }

    if(nodeToparent[curr]==-1 and child>1){
        ans[curr]=1;
    }
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;

        vector<pair<int,int>>edges;

        vector<int> adj[n+1];
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;

            edges.push_back({u,v});
        }
        
        for(int i=0;i<e;i++){
            int u=edges[i].first;
            int v=edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int v=n;

        vector<int>discoveryTime(v+1,-1);
        vector<int>lowestTime(v+1,-1);
        vector<int>nodeToparent(v+1,-1);
        vector<int>vis(v+1,0);
        vector<int>ap(v+1,0);

        int timer=0;

        for(int i=0;i<v+1;i++){
            if(!vis[i]){
                dfs(i,timer,adj,discoveryTime,lowestTime,nodeToparent,vis,ap);
            }
        }

        for(int i=0;i<n+1;i++){
            if(ap[i]==1) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
