Shortest Path in Weighted undirected graph
Difficulty: MediumAccuracy: 50.0%Submissions: 79K+Points: 4Average Time: 20m
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.
Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n+m)

Constraint:
2 <= n <= 106
0 <= m <= 106
1 <= a, b <= n
1 <= w <= 105








class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
    
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        dist[1]=0;
        pq.push({0,1});
    
        while(!pq.empty()){
            int curr=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
    
            for(auto neigh:adj[curr]){
                if(dist[curr]+neigh.second<dist[neigh.first]){
                    parent[neigh.first]=curr;
                    dist[neigh.first]=dist[curr]+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        
        if(dist[n]==INT_MAX) return {-1};
        
        
        vector<int>path;
        int i=n;
        while(parent[i]!=-1){
            path.push_back(i);
            i=parent[i];
        }
        
        path.push_back(1);
        
        vector<int>ans;
        ans.push_back(dist[n]);
        for(auto i:path) ans.push_back(i);
        
        return ans;
    }
};
bhai pta nhi ye alg path and ans bnnane ke bad hi chl rhi thi o/w not okk
