
Code
Test Result
Testcase
Testcase
743. Network Delay Time
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)








class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto neigh:adj[node]){
                if(wt+neigh.second<dist[neigh.first]){
                    dist[neigh.first]=wt+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }

        for(auto i:dist) cout<<i<<" ";

        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }

        return ans==0?-1:ans;
    }
};


dijskstra ques
