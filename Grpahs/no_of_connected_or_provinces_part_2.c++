
Number of Provinces
Difficulty: MediumAccuracy: 54.29%Submissions: 139K+Points: 4Average Time: 20m
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)













in this what if we are given with a matrix then here is how to solve it 

class Solution {
  public:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int curr){
        visited[curr]=true;
        
        for(int i=0;i<adj.size();i++){
            //yha bs ye farak hai ki ager curr ka neigh hai i to vo 1 hona chahihe aor ager vo 1 hai to  tbhi aap check kro o/w mat kro                                                                            
            if(adj[curr][i]==1){
                if(!visited[i]){
                    dfs(adj,visited,i);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int provinces=0;
        vector<bool>visited(V);

       //to bat same hai just hame matrix pe lagana hai okk so listen niche to same rhega
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                provinces++;
            }
        }
        
        return provinces;
    }
};

as in ques it is 0 - based indexing so we are taking it okk



and through bfs it is like this 

class Solution {
  public:
    void bfs(vector<vector<int>>&adj,vector<bool>&visited,int curr){
        queue<int>q;
        visited[curr]=true;
        q.push(curr);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            
            for(int i=0;i<adj.size();i++){
                if(adj[front][i]==1){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int provinces=0;
        vector<bool>visited(V);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(adj,visited,i);
                provinces++;
            }
        }
        
        return provinces;
    }
};
