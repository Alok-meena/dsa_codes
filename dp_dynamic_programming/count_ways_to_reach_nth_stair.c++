coding site :- https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=DISCUSS

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


//space optimized
#include <bits/stdc++.h> 

int m = 1e9 + 7;

int countDistinctWays(int nStairs) {

    

    if(nStairs == 0){

        return 1;

    }

    if(nStairs == 1){

        return 1;

    }

 

    int prev1 = 1;

    int prev2 = 1;

 

    for(int i = 2; i <= nStairs; i++){

 

        int curr = (prev1 + prev2) % m;

        prev2 = prev1;

        prev1 = curr;    

    }  

    return prev1;

}
