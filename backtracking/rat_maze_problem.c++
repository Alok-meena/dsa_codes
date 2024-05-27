Problem statement
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0)
(the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a 
square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations 
while value 1 is the open/available path that the rat can take to reach its destination.
The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the 
rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) ,
'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

Note:
Here, sorted paths mean that the expected output should be in alphabetical order.
For Example:
Given a square matrix of size 4*4 (i.e. here 'N' = 4):
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
Expected Output:
DDRDRR DRDDRR 
i.e. Path-1: DDRDRR and Path-2: DRDDRR

The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.


class Solution{
    private:
    
    bool isSafe(int x,int y,int n,vector<vector<int>>&m,vector<vector<int>>visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m,int n,int x,int y,vector<vector<int>>visited,vector<string>&ans,string path){
        //we have reached the destination x , y here
        
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            //aor yha jab ham path pe complete kr liya to push kr diya usko fir return krenge aor sari sides jha ja ske check krenge aor isse 
            //sare possible path aa jayenge
            
            return;
        }
        
        // to aage pahuche to visited ko 1 kr do
        visited[x][y]=1;
        
        //4 choises D L R U

        //so according to this code ham pahle down ka check kr rhe hai and so on 
        
        //1 down
        int newx=x+1;
        int newy=y;
        
        if(isSafe(newx,newy,n,m,visited)){
            path.push_back('D');
            solve(m,n,newx,newy,visited,ans,path);
            path.pop_back();//jab vapas aaoge to path string ko khali bhi kro for other path's
        }
        
        //2 up
        newx=x-1;
        newy=y;
        
        if(isSafe(newx,newy,n,m,visited)){
            path.push_back('U');
            solve(m,n,newx,newy,visited,ans,path);
            path.pop_back();
        }
        
        
        //3 left
        newx=x;
        newy=y-1;
        
        if(isSafe(newx,newy,n,m,visited)){
            path.push_back('L');
            solve(m,n,newx,newy,visited,ans,path);
            path.pop_back();
        }
        
        //4 right
        newx=x;
        newy=y+1;
        
        if(isSafe(newx,newy,n,m,visited)){
            path.push_back('R');
            solve(m,n,newx,newy,visited,ans,path);
            path.pop_back();
        }
        
        
        
        
        visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int srx=0;
        int sry=0;
        
        vector<string>ans;
        
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>>visited=m;
        
        string path="";
        
        //initially initialize the visited array with 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        solve(m,n,srx,sry,visited,ans,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};




Time Complexity
O(3^(N^2)), where N is the dimension of the square matrix.

 

Now, since there are N^2 cells in total and from each cell, there can only be three unvisited neighbouring cells. So the time complexity O(3^(N^2)).

Space Complexity
O(N^2), where N is the dimension of the square matrix.

 

As there can be at most N^2 cells in the answer for each possible path available for each cell with N^2 cells in total, so the space complexity is also O(N^2).
