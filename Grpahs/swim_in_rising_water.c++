
Code


Test Result
Testcase
Testcase
778. Swim in Rising Water
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.



t.c:-(n*nlog(n*n)) alright


nothing hme bs vo shortest path chaihhe jisme elevation min ho and also have to store max elevation of that path right

to bhai ek kam kro na min elevation leni hai har bar to pq me grid[i][j] dala do along with i,j and do store max elevation each time that's it alright



class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int elevation=0;

        int n=grid.size();

        vector<vector<int>>vis(n,vector<int>(n,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            int value=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            elevation=max(elevation,value);
            if(i==n-1 and j==n-1) return elevation;

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};

            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<n and !vis[newi][newj]){
                    vis[newi][newj]=1;
                    pq.push({grid[newi][newj],{newi,newj}});
                }
            }
        }

        return -1;
    }
};
