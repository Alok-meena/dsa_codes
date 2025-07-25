#include<bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>>&v,vector<vector<int>>&vis,int n,int m,int i,int j,string &ans){

    if(i==n-1 && j==m-1){
        cout<<ans<<" ";
        return;
    }

    //down
    int ni=i+1;
    int nj=j;

    if((ni>=0 && ni<n) and (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('D');
        vis[ni][nj]=1;
        solve(v,vis,n,m,ni,nj,ans);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //up

     ni=i-1;
     nj=j;

    if((ni>=0 && ni<n) and (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('U');
        vis[ni][nj]=1;
        solve(v,vis,n,m,ni,nj,ans);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //right

     ni=i;
     nj=j+1;

    if((ni>=0 && ni<n) and (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('R');
        vis[ni][nj]=1;
        solve(v,vis,n,m,ni,nj,ans);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //left

     ni=i;
     nj=j-1;

    if((ni>=0 && ni<n) and (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('L');
        vis[ni][nj]=1;
        solve(v,vis,n,m,ni,nj,ans);
        ans.pop_back();
        vis[ni][nj]=0;
    }


}

int main() {
	
    vector<vector<int>>v={
        {0,1,0,0,1},
        {0,0,1,0,0},
        {1,0,0,0,1},
        {0,1,1,0,1},
        {1,0,1,0,0},
    };

    int n=v.size();
    int m=v[0].size();
    string ans="";

    vector<vector<int>>visited(n,vector<int>(m,0));
    //and if imposible to traverse then return your answer
    if (v[0][0] == 1 || v[n-1][n-1] == 1) {
        return output;
    }
    //it should be done because uper code me to ham jha move kiye vha vis=1 kr rhe but initially jha hai vo to 1 krna hoga
    visited[0][0]=1;

    solve(v,visited,n,m,0,0,ans);
    cout<<endl<<ans;

	
	return 0;
}

t.c:-O(4^n*m)


more short code


void solve_2(vector<vector<int>>&v,vector<vector<int>>&vis,int n,int m,int i,int j,string &ans){
    if(i==n-1 && j==m-1){
        cout<<ans<<" ";
        return;
    }

    int x[]={0,0,-1,1};
    int y[]={-1,1,0,0};

    string direction="LRUD";
    int ni,nj;

    for(int k=0;k<4;k++){
        ni=i+x[k];
        nj=j+x[k];

        if((ni>=0 && ni<n) and (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
            ans.push_back(direction[k]);
            vis[ni][nj]=1;
            solve(v,vis,n,m,ni,nj,ans);
            ans.pop_back();
            vis[ni][nj]=0;
        }
    }
}

int main() {
	
    vector<vector<int>>v={
        {0,1,0,0,1},
        {0,0,1,0,0},
        {1,0,0,0,1},
        {0,1,1,0,1},
        {1,0,1,0,0},
    };

    int n=v.size();
    int m=v[0].size();
    string ans="";

    vector<vector<int>>visited(n,vector<int>(m,0));
    visited[0][0]=1;

    solve_2(v,visited,n,m,0,0,ans);
    cout<<endl<<ans;

	
	return 0;
}

if u used 8 directions 
then O(8^n*m)


to print all possible answers use 

#include <bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>>&v,int i,int j,int n,int m,string &ans,vector<vector<int>>&vis,vector<string>&s){
    if(i==n-1 && j==m-1){
        s.push_back(ans);
        // for(auto i:ans){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return;
    }

    int ni,nj;
    vis[i][j]=1;

    //up
    ni=i-1;
    nj=j;
    if((ni>=0 && ni<n) && (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('U');
        vis[ni][nj]=1;
        solve(v,ni,nj,n,m,ans,vis,s);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //down
    ni=i+1;
    nj=j;
    if((ni>=0 && ni<n) && (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('D');
        vis[ni][nj]=1;
        solve(v,ni,nj,n,m,ans,vis,s);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //left
    ni=i;
    nj=j-1;
    if((ni>=0 && ni<n) && (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('L');
        vis[ni][nj]=1;
        solve(v,ni,nj,n,m,ans,vis,s);
        ans.pop_back();
        vis[ni][nj]=0;
    }

    //right
    ni=i;
    nj=j+1;
    if((ni>=0 && ni<n) && (nj>=0 && nj<m) && vis[ni][nj]==0 && v[ni][nj]==0){
        ans.push_back('R');
        vis[ni][nj]=1;
        solve(v,ni,nj,n,m,ans,vis,s);
        ans.pop_back();
        vis[ni][nj]=0;
    }
}

int main(){
    vector<vector<int>>v={
        {0,1,0,0},
        {0,0,0,0},
        {1,0,0,1},
        {1,0,0,0},
    };

    int n=v.size();
    int m=v[0].size();
    vector<string>ans;
    string s;

    vector<vector<int>>visited(n,vector<int>(m,0));

    solve(v,0,0,n,m,s,visited,ans);

    for(auto i:ans){
        cout<<i<<" ";
    }


}



we can mark visited in the each direction also or once also outside alright

class Solution {
  public:
    void solve(int i,int j,int n,vector<string>&ans,string &output,vector<vector<int>>&mat,vector<vector<int>>&visited){
        if(i==n-1 and j==n-1){
            if(!output.empty()){
                ans.push_back(output);
            }
            return;
        }
        
        visited[i][j]=1;
        
        int newi,newj;
        
        //up
        newi=i-1;
        newj=j;
        
        if((newi>=0 and newj<n) and visited[newi][newj]==0 and mat[newi][newj]==1){
            output.push_back('U');
            solve(newi,newj,n,ans,output,mat,visited);
            output.pop_back();
        }
        
        //down
        newi=i+1;
        newj=j;
        
        if((newi<n and newj<n) and visited[newi][newj]==0 and mat[newi][newj]==1){
            output.push_back('D');
            solve(newi,newj,n,ans,output,mat,visited);
            output.pop_back();
        }
        
        //left
        newi=i;
        newj=j-1;
        
        if((newi<n and newj>=0) and visited[newi][newj]==0 and mat[newi][newj]==1){
            output.push_back('L');
            solve(newi,newj,n,ans,output,mat,visited);
            output.pop_back();
        }
        
        //right
        newi=i;
        newj=j+1;
        
        if((newi<n and newj<n) and visited[newi][newj]==0 and mat[newi][newj]==1){
            output.push_back('R');
            solve(newi,newj,n,ans,output,mat,visited);
            output.pop_back();
        }
        
        visited[i][j]=0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        
        if(maze[0][0]==0) return ans;
         
        string output;
        int n=maze.size();
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        solve(0,0,n,ans,output,maze,visited);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

look this is 
