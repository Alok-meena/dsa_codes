
Code


Testcase
Testcase
Test Result
785. Is Graph Bipartite?
Solved
Medium
Topics
Companies
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.




class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&color,int currnode,int col){
        color[currnode]=col;

        for(auto i:graph[currnode]){
            if(color[i]==-1){
                //yha ager ans false aya then immediately return false as answer o/w we have to check all of the neighbours till the end node and if 
                //correct then at last return answer as true okk
                if(!dfs(graph,color,i,!col)) return false;
            }
            else if(color[i]==col) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                //same case we have to check all components and if anyof it is false then return false and have to return true at last okk
                bool check=dfs(graph,color,i,0);
                if(!check) return false;
            }
        }

        return true;
    }
};


by bfs


class Solution {
public:
    bool bfs(vector<vector<int>>&graph,vector<int>&color,int currnode,int col){
        queue<int>q;
        color[currnode]=col;
        q.push(currnode);

        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto neigh:graph[front]){
                if(color[neigh]==-1){
                    color[neigh]=!color[front];
                    q.push(neigh);
                }
                else if(color[neigh]==color[front]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bool check=bfs(graph,color,i,0);
                if(!check) return false;
            }
        }

        return true;
    }
};


same t.c and s.c
