

#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class Graph{
    public:

    unordered_map<int,list<pair<int,int>>>adjlist;

    void addedge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adjlist[u].push_back(p);
    }

    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"-->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s){
     visited[node]=true;

     for(auto neighbour:adjlist[node]){
        if(!visited[neighbour.first]){
            dfs(neighbour.first,visited,s);
        }
     }
     s.push(node);
    }

    void getShortespath(int src,vector<int>&dist,stack<int>&s){
        dist[src]=0;

        while(!s.empty()){
            int top=s.top();
            s.pop();

            //here it is necessary to check if the dist is max or not because here we are processing nodes based on the order 
            //but in dijkstra we dont need this as we are getting nodes based on min distance okk
            if(dist[top]!=INT_MAX){
                for(auto i:adjlist[top]){//to adjlist me top pe gye 
                    if(dist[top]+i.second<dist[i.first]){//dist[top] means dist array me top index pe jo distance hai and i.second means pair me first to
                        //node hai and second me distance < hai ager dist[i.firt] so i.first next node btata hai aor is index pe jo distance hai dist array
                        //me ager usse kam hai to usko update kr do okkk
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }


};


int main(){
    Graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    
    g.print();

    //topological sort 
    unordered_map<int,bool>visited;
    stack<int>s;

    int n=6;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    
    int src=1;
    vector<int>distance(n);

    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    } 

    g.getShortespath(src,distance,s);

    cout<<"answer is:"<<endl;

    for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" ";
    }

}

t.c & s.c:-O(N+E)


second time written by me

#include <bits/stdc++.h>

void dfs(vector<pair<int,int>> adj[],vector<bool>&visited,stack<int>&s,int currnode){
    visited[currnode]=true;

    for(auto neigh:adj[currnode]){
        if(!visited[neigh.first]){
            visited[neigh.first]=true;
            dfs(adj,visited,s,neigh.first);
        }
    }

    s.push(currnode);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<pair<int,int>> adj[n];

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u].push_back({v,w});
    }

    vector<bool>visited(n,false);
    stack<int>s;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,s,i);
        }
    }

    vector<int>distance(n,INT_MAX);
    distance[0]=0;

    while(!s.empty()){
        int top=s.top();
        s.pop();

        if(distance[top]!=INT_MAX){
            for(auto neigh:adj[top]){
                if(distance[top]+neigh.second<distance[neigh.first]){
                    distance[neigh.first]=distance[top]+neigh.second;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(distance[i]==INT_MAX) distance[i]=-1;
    }

    return distance;
}
same t.c and s.c
