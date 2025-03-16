787. Cheapest Flights Within K Stops
Attempted
Medium
Topics
Companies
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst




it is dont similar to dijkstra algo 

just have to keep an eye on both cost and k okk and according to them we have to return our answer alright


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>adj;

        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
            //node->node,weight
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,-1,src});//cost,k,source    and initially hamne -1 kiya because first stop ko ye 0 bol rhe hai okk

        while(!pq.empty()){
            vector<int>v=pq.top();
            pq.pop();

            int currCost=v[0];
            int curr_k=v[1];
            int curr_node=v[2];

            if(curr_node==dst and curr_k<=k) return currCost;

            for(auto neigh:adj[curr_node]){
                if(curr_k<k){
                    pq.push({currCost+neigh.second,curr_k+1,neigh.first});
                }
            }
        }

        return -1;
    }
};


but this is giving tle so one way to optimize is using mincost array similar to dijkstra okk but we cant do it as we also have to take care of k not only of cost 
okk ex: if k=1 then we cant choose path of min cost with greater k than 1 okk

t.c of dijkstra is of nlogn type



so now we are giving priority to k first so we will get values based on min k okk and we are also maintatinng a mincost array to give priority to cost also okk

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>adj;

        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
            //node->node,weight
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({-1,0,src});//k,cost,source
        vector<int>mincost(n,1e9);

        while(!pq.empty()){
            vector<int>v=pq.top();
            pq.pop();

            int currCost=v[1];
            int curr_k=v[0];
            int curr_node=v[2];


            for(auto neigh:adj[curr_node]){
                if(currCost + neigh.second < mincost[neigh.first] and curr_k<k){
                    mincost[neigh.first]=min(mincost[neigh.first],currCost+neigh.second);
                    pq.push({curr_k+1,currCost+neigh.second,neigh.first});
                }
            }
        }

        if(mincost[dst]==1e9) return -1;

        return mincost[dst];

        return -1;
    }
};

and we can also remove that logn factor by using a simple queue as we are prioritizing k and cost in queue and different array so no need of pq okk

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>adj;

        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
            //node->node,weight
        }

        queue<vector<int>>pq;
        pq.push({-1,0,src});//cost,k,source
        vector<int>mincost(n,1e9);

        while(!pq.empty()){
            vector<int>v=pq.front();
            pq.pop();

            int currCost=v[1];
            int curr_k=v[0];
            int curr_node=v[2];


            for(auto neigh:adj[curr_node]){
                if(currCost + neigh.second < mincost[neigh.first] and curr_k<k){
                    mincost[neigh.first]=min(mincost[neigh.first],currCost+neigh.second);
                    pq.push({curr_k+1,currCost+neigh.second,neigh.first});
                }
            }
        }

        if(mincost[dst]==1e9) return -1;

        return mincost[dst];

        return -1;
    }
};

aor isme hamne normal queue use kiya becaue no. of stops always 1 se hi badh rhe hai okk

