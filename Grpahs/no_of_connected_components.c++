#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool>&visited,vector<int>adj[],int curr){
    if(visited[curr]==true) return;

    cout<<curr<<" ";
    visited[curr]=true;

    for(auto neigh:adj[curr]){
        if(visited[neigh]==false){
            dfs(visited,adj,neigh);
        }
    }
}

int main(){
    int n;
    cout<<"nodes:";
    cin>>n;

    int e;
    cout<<"edges:";
    cin>>e;

    vector<int>adj[n+1];

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<bool>visited(n+1,false);
    int connected=0;
    for(int i=1;i<n+1;i++){
        if(visited[i]==false){
            dfs(visited,adj,i);
            connected++;
        }
        cout<<endl;
    }

    cout<<"total connected components are :"<<connected;
}


for a matrix code is below


class Solution {
public:
    void dfs(int n,vector<vector<int>>&graph,vector<bool>&visited,int curr){
        if(visited[curr]==true) return;

        visited[curr]=true;

        for(int i=0;i<graph.size();i++){
           //here first we have to check that if there is a edge b/w curr and it's neighbour then only go to check the dfs function okk
            if(graph[curr][i]==1){
                if(visited[i]==false) dfs(n,graph,visited,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n+1,false);
        int connected=0;

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                connected++;
                dfs(n,isConnected,visited,i);
            }
        }

        return connected;
    }
};
