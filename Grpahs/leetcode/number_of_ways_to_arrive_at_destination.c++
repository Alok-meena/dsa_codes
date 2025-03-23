
Code
Testcase
Testcase
Test Result
1976. Number of Ways to Arrive at Destination
Solved
Medium
Topics
Companies
Hint
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.






int mod=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0}); //weight,node
        vector<long long>ways(n,0);
        ways[0]=1;

        while(!pq.empty()){
            pair<long long,int>top=pq.top();
            pq.pop();

            int node=top.second;
            long long wt=top.first;

            for(auto neigh:adj[node]){
                long long int distance=wt+neigh.second;

                if(distance<dist[neigh.first]){
                    dist[neigh.first]=wt+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                    ways[neigh.first]=ways[node];
                }
                else if(distance==dist[neigh.first]){
                    ways[neigh.first]=(ways[neigh.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};

everything is same just have to change datatype to long long as the dist and ways can be larger and add modulo also
so we are doing nothing just applying dijkstra okk to find min dist and if a new min dist is found then reset the ways as we want total ways to reach 
destination only with this min dist and if with same dist there are more ways then add it to the ways alright and initially dist[0]=1 alright 
