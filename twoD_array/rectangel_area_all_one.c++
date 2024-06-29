3195. Find the Minimum Area to Cover All Ones I


You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

 

Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:



The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[0,0],[1,0]]

Output: 1

Explanation:



The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.


THIS CODE IS ONLY TO FIND MIN AREA NOT FOR MAX AREA OF THE RECTANGLE AND 

 
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();

      //to dhyan se suno hme area nikalna hai of rectangle which is height*width okk to height aor width nikalni hogi to iske liye 
     //to height means bottom - top and width = right - left okk 
     //to ab sbko initializez kr do top jo hai bottom se kam hoga to iteration me min value lenge aor <m tk jayenge to top ko m rkh do 
     //because iteration m tk nhi jayegi and bottom me hm max lenge to -ve vaue rkh do 
     //same for left and right
     //then iteration me top ke liye top and i me se min value lenge becaue top upe se niche no. of rows tk hoga jaise hi 1 mila
     //and bottom me max of bottom and i 
     //and same left right me j ko include karna because vo horizonattly jayega
        
        int top = m;   
        int bottom = -1; 
        int left = n;  
        int right = -1; 
        
        // Iterate through the grid to find the boundaries
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        
        int width = right - left + 1;//dono me +1 kiya because indices 0 se start hoti hai but we want proper area o/w our area would be 0 in any case
        int height = bottom - top + 1;
        int area = width * height;
        
        return area;
    }
};
