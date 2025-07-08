Eventual Safe States
Difficulty: MediumAccuracy: 55.52%Submissions: 69K+Points: 4Average Time: 20m
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Examples

Input:

Output: 2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
Input:

Output: 3
Explanation:
Only node 3 is a terminal node, and every path 
starting at node 3 leads to node 3.
Your Task:
You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

Expected Time Complexity: O(V + E)

Expected Space Complexity: O(V)

Constraints:

1 <= V <= 104
0 <= E <= 104
The graph won't contain self loops.
Each node in the graph has a distinct value in the range 0 to V - 1.





// User function Template for C++

class Solution {
  public:
    bool dfs(int curr,vector<int> adj[],vector<bool>&vis,vector<bool>&dfs_call,vector<bool>&check){
        vis[curr]=true;
        dfs_call[curr]=true;
        check[curr]=false;
    
        for(auto neigh:adj[curr]){
            if(vis[neigh] and dfs_call[neigh]){
                check[neigh]=false; //ye yha aor niche krne ki jrurat hi nhi because ham initially false hi kr rkhe hai jaise hi enter kr alright
                return true;
            }
            else if(!vis[neigh]){
                if(dfs(neigh,adj,vis,dfs_call,check)){
                    check[neigh]=false;
                    return true;
                }
            }
        }

        //ye niche ki 3 lines cycle present hai to call hi nhi hogi direct true return ho jayega alright
        
        check[curr]=true;
        dfs_call[curr]=false; //jate jate return kr rhe ho to ise mark krte jao alright
    
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int n=V;
        vector<bool>vis(n,false);
        vector<bool>dfs_call(n,false);
        vector<bool>check(n,false);
        vector<int>safenodes;
    
          for(int i=0;i<n;i++){
              if(!vis[i]){
                  dfs(i,adj,vis,dfs_call,check);
                  
              }
          }
          
          for(int i=0;i<n;i++){
              if(check[i]) safenodes.push_back(i);
          }
          
          return safenodes;
          
    }
};

//bue ek aor cheez jo last me 3 statement hai na dfs me vo execute hi nhi hogi ager cycle present hai aor return ho jayegi to apka dfscall update bhi nhi
//hoga aor usme jo bhi false hai vo sare without cycle vale hai to unhe bhi ans mme dal skte ho no need of check array alright


// User function Template for C++

class Solution {
  public:
    bool dfs(int curr,vector<int> adj[],vector<bool>&vis,vector<bool>&dfs_call,vector<bool>&check){
        vis[curr]=true;
        dfs_call[curr]=true;
        check[curr]=false;
    
        for(auto neigh:adj[curr]){
            if(vis[neigh] and dfs_call[neigh]){
                check[neigh]=false;
                return true;
            }
            else if(!vis[neigh]){
                if(dfs(neigh,adj,vis,dfs_call,check)){
                    check[neigh]=false;
                    return true;
                }
            }
        }
        
        check[curr]=true;
        dfs_call[curr]=false; //jate jate return kr rhe ho to ise mark krte jao alright
    
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int n=V;
        vector<bool>vis(n,false);
        vector<bool>dfs_call(n,false);
        vector<bool>check(n,false);
        vector<int>safenodes;
    
          for(int i=0;i<n;i++){
              if(!vis[i]){
                  dfs(i,adj,vis,dfs_call,check);
                  
              }
          }
          
          
          for(int i=0;i<n;i++){
              if(!dfs_call[i]) safenodes.push_back(i);
          }
          
          return safenodes;
          
    }
};

alright
