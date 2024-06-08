

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
