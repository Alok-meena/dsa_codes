








basic brute force what i thought t.c:-exponential 2^n 

class Solution {
  public:
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>output,int idx){
        if(idx>=arr.size()){
            ans.push_back(output);
            return;
        }
        
        //exc
        solve(arr,ans,output,idx+1);
        
        //incl
        output.push_back(arr[idx]);
        solve(arr,ans,output,idx+1);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>ans;
        vector<int>output;
        solve(arr,ans,output,0);
        
        for(int i=0;i<ans.size();i++){
            int count=0;
            for(int j=0;j<ans[i].size();j++){
                count+=ans[i][j];
            }
            if(count==sum) return true;
        }
        return false;
    }
};


recursive approach exponentail

class Solution {
  public:
    bool solve(vector<int>&arr,int target,int idx){
        if(idx>=arr.size()){
            if(target==0) return true;
            else return false;
        }
        
        int opt1=false,opt2=false;
        
        if(arr[idx]<=target){
            opt1=solve(arr,target-arr[idx],idx+1);
        }
        
        opt2=solve(arr,target,idx+1);
        
        return opt1 or opt2;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return solve(arr,sum,0);
    }
};

top down

class Solution {
  public:
    bool solve(vector<int>&arr,int target,int idx,vector<vector<int>>&dp){
        if(idx>=arr.size()){
            if(target==0) return true;
            else return false;
        }
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int opt1=false,opt2=false;
        
        if(arr[idx]<=target){
            opt1=solve(arr,target-arr[idx],idx+1,dp);
        }
        
        opt2=solve(arr,target,idx+1,dp);
        
        dp[idx][target]=opt1 or opt2;
        
        return dp[idx][target];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
    }
};

bottom up
