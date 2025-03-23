

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.


ye ques similar to subset sum problem hai jisme hame target given tha and we have to check if there is any subset with sum equals target alright so is ques me
equal sum dono subset me means totalsum/2 right so just run this code for target=totalsum/2 that's it and if totalsum is odd then not possible 

class Solution {
public:
     bool solve(vector<int>&arr,int target,int idx,vector<vector<int>>&dp){
        if(idx==arr.size()){
            if(target==0){
                return true;
            }
            else return false;
        }
        if(target==0) return true;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        //include
        bool inc=false,exc=false;
        if(arr[idx]<=target) inc=solve(arr,target-arr[idx],idx+1,dp);
        exc=solve(arr,target,idx+1,dp);
        
        dp[idx][target]=inc or exc;
        return dp[idx][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0) return false;
        sum=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,sum,0,dp);
    }
};

and below one is by love sir concept



1:recursion

or we can also start from sum=0 and making it equal to target alright but this one is preferrable

class Solution{
public:
    int solve(int index,int arr[],int target,int n){
        if(index>=n){ 
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        //yha pe pahle ki tarah khuch add nhi karna hai because yha hme 1 ya 0 return ho rha hai khuch add nhi karna hai
        int include=solve(index+1,arr,target-arr[index],n);
        int exclude=solve(index+1,arr,target,n);

        //if any one of them returns 1 then return 1
        if(include || exclude){
            return 1;
        }
        else{
            return 0;
        }
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2==0){
            return solve(0,arr,sum/2,N);
        }
        else{
            return 0;
        }
    }
};

2:memorization

class Solution{
public:
    int solve(int index,int arr[],int target,int n,vector<vector<int>>&dp){
        if(index>=n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        int include=solve(index+1,arr,target-arr[index],n,dp);
        int exclude=solve(index+1,arr,target,n,dp);
        
        dp[index][target]=include || exclude ;
        
        return dp[index][target];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int target=sum/2;
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        
        if(sum%2==0){
            return solve(0,arr,target,N,dp);
        }
        else{
            return 0;
        }
    }
};

3:tabulation / bottom up appraoch



class Solution{
public:
    
    int solve(int n,int arr[],int t){
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        
        // dp[0][0]=1; this is wrong as we have target 0 but not index

        //sbhi row ke ander column ke ander 0 dal diya
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        //apna index 0 se n tk ja rha tha and n ko 0 to kr diya so can start with n-1
        for(int index=n-1;index>=0;index--){
            for(int target=0;target<=t;target++){
                int include=0;
                if(target-arr[index]>=0){
                    include=dp[index+1][target-arr[index]];
                }
                
                int exclude=dp[index+1][target];
                
                dp[index][target]=include || exclude ;
            }
        }
        return dp[0][t];//loop 0 and t tk ja rha
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int target=sum/2;

        if(sum%2==0){
            return solve(N,arr,target);
        }
        else{
            return 0;
        }
    }
};


4:space optimization

class Solution{
public:
    
    int solve(int n,int arr[],int t){
        vector<int>curr(t+1,0);//shows dp[index] curr row
        vector<int>next(t+1,0);//shows dp[index+1] next row
        
        //no loop reuqire as what we are doing we are making 0th column 1
        curr[0]=1;
        next[0]=1;
        
        for(int index=n-1;index>=0;index--){
            for(int target=0;target<=t;target++){
                int include=0;
                if(target-arr[index]>=0){
                    include=next[target-arr[index]];
                }
                
                int exclude=next[target];
                
                curr[target]=include || exclude ;
            }
            next=curr;//as we have n rows and loop starts from n-1 so n-1 is curr row and n is next so update next
        }
        return next[t];//loop 0 and t tk ja rha
        //next[t] kro ya curr[t] correct because at last next me curr ko hi copy kr rhe hai ham
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int target=sum/2;

        if(sum%2==0){
            return solve(N,arr,target);
        }
        else{
            return 0;
        }
    }
};

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(sum of elements)
