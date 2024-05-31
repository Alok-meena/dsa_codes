#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph{
    public:

    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool direction){//u and v liya mtlb edge ban rhi hai u to v or from v to u
        //direction = 0 ->undirected
        //direction = 1 ->directed

        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);//we did this because if direction ==0 means undirected graph
        }
    }

    void printAdjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    
};

int main(){

    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;

    int m;
    cout<<"Enter the number of edges:";
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        //creating an undirected graph so using 0 
        g.addEdge(u,v,0);
    }

    g.printAdjlist();

    return 0;
}


example:---
Enter the number of nodes:5
Enter the number of edges:6

//hamne yha only unique edges ko hi mention kiya hai
0 1
0 4 
4 3
3 1
3 2
1 2
2->3,1,
0->1,4,
1->0,3,2,
4->0,3,
3->4,1,2,


for AdjList:-
Add Edge T.C: O(m) and S.C: O(n+m)
Print Edge T.C: O(n*m) and S.C: O(1)



we can do like this also where we dont have to mention the type of data we are using in the graph we have used this "template <typename T>"
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>


class graph{
    public:

    unordered_map<T,list<T>>adj;

    void addEdge(T u,T v,bool direction){
        //direction = 0 ->undirected
        //direction = 1 ->directed

        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    
};

int main(){

    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;

    int m;
    cout<<"Enter the number of edges:";
    cin>>m;

    graph<char> g;//here you can mention the type of data inside <> this!

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjlist();

    return 0;
}
  
