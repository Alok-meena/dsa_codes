Subset Sum Problem
Difficulty: MediumAccuracy: 32.0%Submissions: 336K+Points: 4
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104








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
        if(idx==arr.size()){
            if(target==0) return true;
            else return false;
        }

        if(target==0) return true;
        
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
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1)); //we should have to store int in this dp as bool value can create error alright
        return solve(arr,sum,0,dp);
    }
};

bottom up


bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
          
        for(int idx=n-1;idx>=0;idx--){
            for(int target=1;target<=sum;target++){
                bool inc=false,exc=false;
                if(target-arr[idx]>=0 and arr[idx]<=target) inc=dp[idx+1][target-arr[idx]];
                exc=dp[idx+1][target];
                
                dp[idx][target]=inc or exc;
            }
        }
        
        return dp[0][sum];
    }

bs vhi hai direct conversion top down o-n and sum-0 so just reverse n-0 0-sum alright 

and ye niche vala bhi tik hai 

bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

     //so ager first element within the bound hai to vo bn skta hai target me help so mark it first 
         if (arr[0] <= sum) {
                dp[0][arr[0]] = 1;
            }        
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=sum;target++){
                bool inc=false,exc=false;
                if(arr[idx]<=target) inc=dp[idx-1][target-arr[idx]];
                exc=dp[idx-1][target];
                
                dp[idx][target]=inc or exc;
            }
        }
        return dp[n-1][sum];
    }

so isme uper k same to same nhi karna i-1 hi check karna hoga and if uper n se 0 gye to i+1 think logically then u will understand


space optimized

bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
        vector<int>next(sum+1,0);
        vector<int>curr(sum+1,0);
        //iska mtlb hai ki sbhi ke pahle column ko 1 kr do that's it
        
        next[0]=1;
        curr[0]=1;
  //and yha nich loop me ham bs har pahle colmun ko 1 kr rhe vhi kr do in dono row me bhi that's it
        // for(int i=0;i<=n;i++){
        //     curr[0]=1;
        // }
        
        //  if (arr[0] <= sum) {
        //         dp[0][arr[0]] = 1;
        //     }        
        for(int idx=n-1;idx>=0;idx--){
            for(int target=1;target<=sum;target++){
                bool inc=false,exc=false;
                if(target-arr[idx]>=0 and arr[idx]<=target) inc=next[target-arr[idx]];
                exc=next[target];
                
                curr[target]=inc or exc;
            }
            next=curr;
        }

to bs khuch nhi idx+1 so next pe depend kr rha hai to bs rows ke equla means sum+1 sizse k bna liya 
