
Code
Testcase
Testcase
Test Result
733. Flood Fill
Solved
Easy
Topics
Companies
Hint
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

 


and is ques me bhi sbko visite hi karna hai to dfs and bfs woulb be the best approach okk


by bfs firstly

class Solution {
public:

    void bfs(vector<vector<int>>&image,int i,int j,int color,int initialC){
        queue<pair<int,int>>q;
        q.push({i,j});
        image[i][j]=color;

        int n=image.size();
        int m=image[0].size();

        while(!q.empty()){
            pair<int,int> front=q.front();
            q.pop();

            int x=front.first;
            int y=front.second;

            //x-1 y up 
            if(x-1>=0 and image[x-1][y]==initialC){
                q.push({x-1,y});
                image[x-1][y]=color;
            }

            //x+1 y down
            if(x+1<n and image[x+1][y]==initialC){
                q.push({x+1,y});
                image[x+1][y]=color;
            }

            //x y-1 left
            if(y-1>=0 and image[x][y-1]==initialC){
                q.push({x,y-1});
                image[x][y-1]=color;
            }

            //x y+1 right
            if(y+1<m and image[x][y+1]==initialC){
                q.push({x,y+1});
                image[x][y+1]=color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int initialC=image[sr][sc];

        int n=image.size();
        int m=image[0].size();

        bfs(image,sr,sc,color,initialC);  //dhyan se dekho sr and sc is given which is the source to be start with so we need to call bfs only once 
      // not for each component alright

        return image;

        
    }
};

t.c and s.c is O(n*m) okk


now by dfs

class Solution {
public:

    void dfs(vector<vector<int>>&image,int x,int y,int color,int initialC){
        image[x][y]=color;

        int n=image.size();
        int m=image[0].size();

        
        //x-1 y up 
            if(x-1>=0 and image[x-1][y]==initialC){
                image[x-1][y]=color;
                dfs(image,x-1,y,color,initialC);
            }

            //x+1 y down
            if(x+1<n and image[x+1][y]==initialC){
                image[x+1][y]=color;
                dfs(image,x+1,y,color,initialC);
            }

            //x y-1 left
            if(y-1>=0 and image[x][y-1]==initialC){
                image[x][y-1]=color;
                dfs(image,x,y-1,color,initialC);
            }

            //x y+1 right
            if(y+1<m and image[x][y+1]==initialC){
                image[x][y+1]=color;
                dfs(image,x,y+1,color,initialC);
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int initialC=image[sr][sc];

        int n=image.size();
        int m=image[0].size();

        dfs(image,sr,sc,color,initialC);

        return image;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(image[i][j]==initialC){
        //             bfs(image,)
        //         }
        //     }
        // }
    }
};

same t.c and s.c
  
