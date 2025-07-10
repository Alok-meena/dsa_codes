Strongly Connected
Difficulty: MediumAccuracy: 50.61%Submissions: 112K+Points: 4Average Time: 20m
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.
 

Examples :

Input: adj[][] = [[2, 3], [0], [1], [4], []]

Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: adj[][] = [[1], [2], [0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: adj[][] = [[1], []]
Output: 2
Constraints:
2<=adj.size()<=106
0<=edges<=adj.size()-1



t.c:-O(v+e)

either ques can be to return no. of scc's or print them so we can also store them in their dfs call alright

algo:

  store topo sort
  reverse edges 
  apply dfs and count connected compo's alright


  (no change in scc if the edges are reversed alright)



//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int curr,vector<vector<int>>&adj,stack<int>&s,vector<int>&vis){
        vis[curr]=true;
        
        for(auto neigh:adj[curr]){
            if(!vis[neigh]){
                dfs(neigh,adj,s,vis);
            }
        }
        
        s.push(curr);
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int>s;
        
        int n=adj.size();
        
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,s,vis);
            }
        }
        
        vector<vector<int>>revAdj(n);
        
        for(int i=0;i<n;i++){
            for(int j:adj[i]){
                revAdj[j].push_back(i);
            }
        }
        
        int cnt=0;
        fill(vis.begin(),vis.end(),0);
        
        while(!s.empty()){
            int top=s.top();
            s.pop();
            
            if(!vis[top]){
                cnt++;
                //can make a separate dfs fun for this so to not call for stack okk
                dfs(top,revAdj,s,vis);
            }
        }
        
        return cnt;
    }
};
