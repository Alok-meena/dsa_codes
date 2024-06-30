








1:recursion  

class Solution {
public:

    int solve(vector<int>&v,int i,int j){
        if(i+1==j){//this means if we have only two vertices then we can't form a traingle
            return 0;
        }
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){//i se leke k tk solve karna hai so loop lga do uska
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));//aor fir ek traingle ko select kiya aor fir i se leke k tka and then k se leke j tk
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        return solve(values,0,n-1);
    }
};

t.c:-O(2^n) exponenetial
s.c:-O(n) due to recursive staack calls   

2:using memorization  2D array bnega becaeuse i and j 2 variable change ho rhe hai

TOP DOWN APPROACH so here we use i=0 and j=n-1



class Solution {
public:

    int solve(vector<int>&v,int i,int j,vector<vector<int>>dp){
        if(i+1==j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};

t.c:-O(N^3) because there are n^2 subproblems and work to do in each subproblem is n so n^3
s.c:-O(N^2)


3:tabulation / /  bottom up approach

This is just reverse approach than top-down approach 

class Solution {
public:

    int solve(vector<int>&v){
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,0));//initialize 0 se hi karna no by one because this is bottom up approach

        //YHA HAME UPER KE CODE SE BASE CASE SMJ NHI AAYA TO NNHI DALA

        //but reverse i=n-1 se start kiya and j ko i+2 se table i . . . j 3 point se traingle formation ho payegi
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values);
    }
};

t.c:-O(N^3)
