M-Coloring Problem
Difficulty: MediumAccuracy: 34.42%Submissions: 166K+Points: 4Average Time: 45m
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3
Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V






t.c:-O(m^n) because m choices hai for n nodes so m^n similar to 0 1 for n things have 2^n

class Solution {
  public:
    bool isvalid(int col,vector<int>&color,vector<int> adj[],int node){
        for(auto neigh:adj[node]){
            if(color[neigh]==col) return false;
        }
        return true;
    }
    bool solve(int node,vector<int> adj[],vector<int>&color,int m,int n){
        if(node==n) return true;
        
        for(int c=1;c<=m;c++){
            if(isvalid(c,color,adj,node)){
                color[node]=c;
                if(solve(node+1,adj,color,m,n)) return true;
                color[node]=c;
            }
        }
        return false;
    }
  
    bool graphColoring(int n, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(n,0);
        
        return solve(0,adj,color,m,n);
    }
};
