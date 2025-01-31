Problem statement
You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.



In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.



For Example:
If 'N' = 3 and edges = {{2,1}, {2,0}}.

So, the adjacency list of the graph is stated below.
0 → 2
1 → 2
2 → 0 → 1

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.

    //here insted of unordered_map<int,list<int>> we used vector<vector<int>>
    vector<vector<int>>ans(n);
    

    // Idhr hmlog sbko khudse conect kr rahe hai matlab manle 1st node 
    //sbse pelhe khudse connect hoga tbna aage jaayga wahi wahi hmlog self node add kr rahe hai\

    *** this is used because the format in which we have to return the answer is like this 0 : 1 -> {2,3,4} like this
    for(int i=0;i<n;i++){
        ans[i].push_back(i);
    }


     // Idhr dekh isme hmlog do values aara input me usko dekhre u hogya pelha value v hogya dusra
     // value dono ka number me matric me hmlog connection banare hai u ka v ke saath v ka u ke saath
    for(int i=0;i<m;i++){

        //because in vector<vector<int>> edges only two edges are present because it is in that format in the vector
        int u=edges[i][0];//because jo edges hai vector<vector<int>> me store hai aor pahle me u and doosre me v to pahli value ke liye (*** column 0 me u hai and i is used to access all the values
        int v=edges[i][1];//and here i is used and v value is present in 1st column

        //2 column hai u and v ke and multiple rows hai so for u to access all rows value use i then 0 for first column similarly for v [i][1] to access all the
        //values of 2nd column ex:- v

        // Assuming the graph is undirected, add edges in both directions

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}



#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
       
       unordered_map<int,vector<int>>adj;

       void addEdge(int u,int v,bool direction){
         adj[u].push_back(v);

         if(direction==0){
            adj[v].push_back(u);
         }
       }

       void printAdjList(){
          for(auto i:adj){
            cout<<i.first<<"=>";
            for(auto j:i.second){
                cout<<j<<",";
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

    graph g;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v,0);
    }

    g.printAdjList();
}


t.c:-  for adding edges (e) and printing adj list O(n+e) and s.c:-O(n+e)




#include <bits/stdc++.h>

using namespace std;

int adjecency_matrix()
{

    int n;
    cin >> n;
    int edges;
    cin >> edges;

    vector<vector<int>> adjmatrix(n + 1, vector<int>(n + 1, -1));
    // undirected
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmatrix[u][v] = w;
        // adjmatrix[v][u] = w;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(vector<int> adj[], int n, vector<bool> &vis, int curr)
{
    if (vis[curr] == true)
    {
        return;
    }

    cout << curr << " ";
    vis[curr] = true;
    // travel across neigh
    for (auto neig : adj[curr])
    {
        if (vis[neig] == false)
        {
            dfs(adj, n, vis, neig);
        }
    }
}

// adj list
int main()
{

    int n;
    cin >> n;
    int edges;
    cin >> edges;

    // unweighted
    vector<int> adjlist[n + 1];

    // weighted
    // vector<pair<int, int>> adjlist[n + 1];
    // [0] -> {  {neig1, val} , { neig2, val}  }

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v;

        // u -> from
        // v -> to
        // w -> weight/cost

        // case 1 : unweighted undirected
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

        // case 2: unweighted directed
        // adjlist[u].push_back(v);

        // case 3: weighted undirected
        // adjlist[u].push_back({v, w});
        // adjlist[v].push_back({u, w});

        // // case 4: weighted directed
        // adjlist[u].push_back({v, w});
    }

    vector<bool> visited(n + 1, false);

    int numberof_connected_comp = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == false)
        {
            dfs(adjlist, n, visited, i);
            numberof_connected_comp++;
        }
    }

    cout << "total number of compoonents are " << numberof_connected_comp << endl;

    // dfs(adjlist, n, visited, 2);
}



written by me below



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
    dfs(visited,adj,1);


    we have to do this for multiple components in the graph 

    //  for(int i=1;i<n+1;i++){
    //    if(visited[i]==false){
    //        dfs(visited,adj,i);
    //        connected++;
    //     }
    //     cout<<endl;
    // }

    and to calculate total connected components we just have to increment that value inside the if condition okk that how many times dfs is being called okk
    
}

