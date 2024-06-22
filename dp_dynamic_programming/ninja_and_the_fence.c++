Ninja has given a fence, and he gave a task to paint this fence.
The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011
Detailed





1:recursion

#include <bits/stdc++.h> 

#define mod 1000000007

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}

int multiply(int a,int b){
    return ((a%mod)*1LL * (b%mod))%mod; //*1LL is used to avoid overflow and to have 64 bit multiplication
}

int solve(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,multiply(k,k-1));
    }

    int ans=add(multiply(solve(n-2,k),k-1), multiply(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n, k);
}

Time Complexity
O(2^N), where 'N' and 'K' are input integers.

 

As we are using the recursion and in every recursion call, there are two separate recursion calls; hence the time complexity will be O(2^N).

Space Complexity
O(1)

 

As we are using the constant extra space, the space complexity will be O(1)

  


2:memorization

#include <bits/stdc++.h> 
#include <vector>
#define mod 1000000007

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}

int multiply(int a,int b){
    return ((a%mod)*1LL * (b%mod))%mod;
}

int solve(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,multiply(k,k-1));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=add(multiply(solve(n-2,k,dp),k-1), multiply(solve(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {

    vector<int>dp(n+1,-1);
    return solve(n, k,dp);
}

Time Complexity
O(N), where 'N' and 'K' are input integers.

 

As we are using the recursion and there will be at max 'N' recursive calls because of memoization, the time complexity will be O(N)

Space Complexity
O(N), where 'N' and 'K' are input integers.

 

As we are using the extra 'DP' array of linear size and also we are using the recursion with maximum linear stack size, the space complexity will be O(N)


3:tabulation

#include <bits/stdc++.h> 
#include <vector>
#define mod 1000000007

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}

int multiply(int a,int b){
    return ((a%mod)*1LL * (b%mod))%mod;
}

int numberOfWays(int n, int k) {

    vector<int>dp(n+1);

    dp[1]=k;
    dp[2]=add(k,multiply(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i]=add(multiply(dp[i-2],k-1),multiply(dp[i-1],k-1));
    }
    return dp[n];
}


Time Complexity
O(N), where 'N' and 'K' are input integers.

 

As we are iterating over the array of size 'N' the time complexity will be O(N)

Space Complexity
O(N), where 'N' and 'K' are input integers.

 

As we are using the extra 'DP' array of linear size, the space complexity will be O(N)


4:space optimization


#include <bits/stdc++.h> 
#include <vector>
#define mod 1000000007

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}

int multiply(int a,int b){
    return ((a%mod)*1LL * (b%mod))%mod;
}


int numberOfWays(int n, int k) {

    vector<int>dp(n+1);

    int prev1=k;
    int prev2=add(k,multiply(k,k-1));

    for(int i=3;i<=n;i++){
        int curr=add(multiply(prev1,k-1),multiply(prev2,k-1));
        prev1=prev2;
        prev2=curr;
    }
    return prev2;
}


t.c:- O(N) and s.c:- O(1)

