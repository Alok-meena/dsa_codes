547. Number of Provinces
Solved
Medium
Topics
Companies
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]




class Solution {
public:
    void dfs(int n,vector<vector<int>>&graph,vector<bool>&visited,int curr){
        if(visited[curr]==true) return;

        visited[curr]=true;

        for(int i=0;i<graph.size();i++){
   //as it is a matrix representation so we have to check if there is a edge b/w them or not
            if(graph[curr][i]==1){
                if(visited[i]==false) dfs(n,graph,visited,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n+1,false);
        int connected=0;

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                connected++;
                dfs(n,isConnected,visited,i);
            }
        }

        return connected;
    }
};

