City With the Smallest Number of Neighbors at a Threshold Distance
Difficulty: MediumAccuracy: 49.12%Submissions: 60K+Points: 4Average Time: 30m
There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Examples

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1], 
         [1, 3, 4],  
         [2, 3, 1]]
distanceThreshold = 4
Output:
3
Explaination:

The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Input: 
n = 5, m = 6
edges = [[0, 1, 2],
         [0, 4, 8],
         [1, 2, 3], 
         [1, 4, 2], 
         [2, 3, 1],
         [3, 4, 1]]
distanceThreshold = 2.
Output:
0
Explaination:

The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a number of nodes n, total number of edges m and vector of edges and distanceThreshold. and return the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, return the city with the greatest label.

Expected Time Complexity: O(n2 + length(edges)*nlog(n) )
Expected Auxiliary Space:  O(n3)

Constraints:











// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        
        for(int i=0;i<n;i++) dist[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                    }
                }
            }
        }
        
        int city=-1;
        int mini=n+1;
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j and dist[i][j]<=distanceThreshold) cnt++;
            }
            
            if(cnt<=mini){
                mini=cnt;
                city=i;
            }
            
        }
        
        return city;
    }
};
