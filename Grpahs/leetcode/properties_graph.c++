100615. Properties Graph
User Accepted:1570
User Tried:2164
Total Accepted:1617
Total Submissions:2853
Difficulty:Medium
You are given a 2D integer array properties having dimensions n x m and an integer k.

Define a function intersect(a, b) that returns the number of distinct integers common to both arrays a and b.

Construct an undirected graph where each index i corresponds to properties[i]. There is an edge between node i and node j if and only if intersect(properties[i], properties[j]) >= k, where i and j are in the range [0, n - 1] and i != j.

Return the number of connected components in the resulting graph.

 

Example 1:

Input: properties = [[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]], k = 1

Output: 3

Explanation:

The graph formed has 3 connected components:



Example 2:

Input: properties = [[1,2,3],[2,3,4],[4,3,5]], k = 2

Output: 1

Explanation:

The graph formed has 1 connected component:



Example 3:

Input: properties = [[1,1],[1,1]], k = 2

Output: 2

Explanation:

intersect(properties[0], properties[1]) = 1, which is less than k. This means there is no edge between properties[0] and properties[1] in the graph.

 

Constraints:

1 <= n == properties.length <= 100
1 <= m == properties[i].length <= 100
1 <= properties[i][j] <= 100
1 <= k <= m





class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>&visited,int node){
        visited[node]=true;
        
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,visited,neigh);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<int>a(properties[i].begin(),properties[i].end());
                unordered_set<int>b(properties[j].begin(),properties[j].end());
                
                int common=0;
                for(auto value:a){
                    if(b.count(value)){
                        common++;
                    }
                }
                
                if(common>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
        }
        
        return ans;
    }
};

but this is giving tle for N^2 so have to optimize that thing


class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>&visited,int node){
        visited[node]=true;
        
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,visited,neigh);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<int> adj[n];
        vector<bitset<101>> freq(n); // Since values are from 1 to 100
        for (int i = 0; i < n; i++) {
            for (int num : properties[i]) {
                freq[i][num] = 1;
            }
        }

        // Step 2: Build the adjacency list efficiently
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((freq[i] & freq[j]).count() >= k) { // Fast common count
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
        }
        
        return ans;
    }
};


this is optimized code
