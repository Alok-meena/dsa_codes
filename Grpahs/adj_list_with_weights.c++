#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
       map<int,vector<int>>adj;

       void addEdge(int u,int v,int dir){
          adj[u].push_back(v);

          if(dir==0){
             adj[v].push_back(u);
          }
       }

       void printAdjList(){
          for(auto i:adj){
            cout<<i.first<<"=>";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
          }
       }
};

int main(){
    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    int e;
    cout<<"enter the number of edges:";
    cin>>e;

    cout<<"now enter the edges"<<endl;

    vector<pair<int,int>> adj[n+1]; // {node:{node,weight}}

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0;i<n+1;i++){
        cout<<i<<"=>";
        for(auto j:adj[i]){
            cout<<"{"<<j.first<<","<<j.second<<"}";
        }
        cout<<endl;
    }
}

// 0 1
// 0 2
// 1 3
// 2 3
// 2 4
// 3 4
