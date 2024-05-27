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
            return;
        }
        
        // to aage pahuche to visited ko 1 kr do
        visited[x][y]=1;
        
        //4 choises D L R U
        
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
