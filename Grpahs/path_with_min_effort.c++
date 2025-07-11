Path With Minimum Effort
Difficulty: MediumAccuracy: 53.13%Submissions: 52K+Points: 4Average Time: 25m
You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Example 1:

Input:
row = 3
columns = 3 
heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 
2
Explanation: 
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.
Example 2:

Input:
row = 2
columns = 2 
heights = [[7,7],[7,7]]
Output: 
0
Explanation: 
Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.
Your Task:
You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

Expected Time Complexity: O(rowsxcolumns)
Expected Space Complexity: O(rowsxcolumns)

Constraints:
1 <= rows, columns <= 100
rows == heights.length
columns == heights[i].length
0 <= heights[i][j] <= 106






we need max of all adj diff and min effort of all paths so for min effort we'll use p_q alright 

t.c:-O(n*m*4*log(n*m)) and s.c:-O(n*m) 

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        int n=rows;
        int m=columns;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0}); //dist i j

        while(!pq.empty()){
            int effort=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            
            if(i==n-1 and j==m-1) return effort; //dont worry if u think like we are returning ans but what if other min is there but the thing is we are using
            //pq and it will always provide us with mindiff alright
            
            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};
        
            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];
                
                if (newi >= 0 && newi < n && newj >= 0 && newj < m) {
                    int newEffort = max(abs(heights[i][j] - heights[newi][newj]),dist[i][j]);
                    //and this is the only thing in this ques to understand alright which we didnt just like dijkstra ques with dist array 
                    if (newEffort < dist[newi][newj]) {
                        dist[newi][newj] = newEffort;
                        pq.push({newEffort, newi, newj});
                    }
                }
            }
        }
        
        return -1;
    }
};
