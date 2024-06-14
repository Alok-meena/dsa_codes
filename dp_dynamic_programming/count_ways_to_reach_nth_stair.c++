

#include <bits/stdc++.h> 
int mod=1e9 + 7;
int solve(int n,vector<int>&dp){
    if(n==0){
       return 1;
    }
   if(n<0){
       return 0;
   }
    if(dp[n]!=-1){
       return dp[n];
   }

   int inc=solve(n-1,dp)%mod;
   int exc=solve(n-2,dp)%mod;
   dp[n]=(inc+exc)%mod;

   return dp[n];
}
int countDistinctWays(int nStairs) {
    vector<int>dp(nStairs+1,-1);

    dp[0]=1;
    d[1]=2;

    for(int i=)
    int ans=solve(nStairs,dp);
    return ans;
}
