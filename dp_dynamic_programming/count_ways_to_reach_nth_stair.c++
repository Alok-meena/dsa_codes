coding site :- https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=DISCUSS

You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.



Each time, you can climb either one step or two steps.



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
brute force using recursion 


int getCount(int currStep, int nStairs, const int& mod) {

    // Base case.
    if(currStep >= nStairs) {

        return (currStep == nStairs);
    }

    //  Climb one stair.
    int oneStepcount = getCount(currStep + 1, nStairs, mod);

    //  Climb two stairs
    int twoStepCount = getCount(currStep + 2, nStairs, mod);

    return (oneStepcount + twoStepCount) % mod; 

}

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Initialize the variable 'ways'.
    int ways = getCount(0, nStairs, mod);

    return ways;
}

    Time Complexity: O( 2 ^ N )
    Space complexity: O( N )



//in this code bottom-up is used and memorization is also used 
#include <bits/stdc++.h> 
int mod=1e9 + 7;
int solve(int n,vector<int>&dp,int i){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    
    if(dp[i]!=-1){
        return dp[i];
    }
    int oneStepcount=solve(n,dp,i+1)%mod;
    int twoStepCount=solve(n,dp,i+2)%mod;

    dp[i]=(oneStepcount+twoStepCount)%mod;
    return dp[i];
}
int countDistinctWays(int nStairs) {
    vector<int>dp(nStairs+1,-1);
    int ans=solve(nStairs,dp,0);
    return ans;
}


 Time Complexity: O( N )
    Space complexity: O( N )


can use the following for top-bottom approach



#include <bits/stdc++.h> 

int mod = 1e9 + 7;

int solve(int n,vector<int>& dp){

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

    //  Write your code here.''

     vector<int> dp(nStairs+1, -1);

    int ans=solve(nStairs, dp);

    return ans%mod;

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

 Time Complexity: O( N )
    Space complexity: O( 1)

