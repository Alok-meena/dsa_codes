Floyd Warshall
Difficulty: MediumAccuracy: 32.89%Submissions: 166K+Points: 4Average Time: 15m
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix. mat[i][j] denotes the weight of the edge from i to j. If mat[i][j] = -1, it means there is no edge from i to j.
Note: Modify the distances for every pair in place.

Examples :

Input: mat = [[0, 25], [-1, 0]]

Output: [[0, 25], [-1, 0]]

Explanation: The shortest distance between every pair is already given(if it exists).
Input: mat = [[0, 1, 43],[1, 0, 6], [-1, -1, 0]]

Output: [[0, 1, 7], [1, 0, 6], [-1, -1, 0]]

Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.
Constraints:
1 <= mat.size() <= 100
-1 <= mat[ i ][ j ] <= 1000








class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();

	//TO AGER path nhi hai kinhi 2 nodes ke beech me to -1 hai to ise infinite bna do as ham har ek node se as intermediate hoke jayenge okk that's why 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1) mat[i][j]=1e8;
            }
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][k]+mat[k][j],mat[i][j]);
                }
            }
        }

	//and again normal bna do okk -1 kr do 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1e8) mat[i][j]=-1;
            }
        }
    }
};

t.c:-O(n^3)

  and we can also find negative cycle here if there the distance of node from itself is negative then there is negative cycle in the graph okk

for(int i=0;i<n;i++){
   if(mat[i][i]<0) cout<<"negative cycle is present in this graph";
}



like this 

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
        vector<vector<int>> mat(n, vector<int>(n, 1e8));

        // Fill the diagonal with 0 because dist to itself will always be 0 alright
        for(int i = 0; i < n; i++) mat[i][i] = 0;

        // Populate initial distances from edges
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mat[u][v] = w;
        }

        
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][k]+mat[k][j],mat[i][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1e8) mat[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
   if(mat[i][i]<0) return 1;
}
return 0;
	}
};

