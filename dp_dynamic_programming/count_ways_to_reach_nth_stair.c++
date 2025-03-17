coding site :- https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=DISCUSS

You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
     Count Ways To Reach The N-th Stairs
Moderate
80/80
Average time to solve is 30m
Contributed by
553 upvotes
Asked in companies
Problem statement
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.



Each time, you can climb either one step or two steps.



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

Example :
N=3

We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= 'T' <= 10
0 <= 'N' <= 10^5

Where 'T' is the number of test cases, and 'N' is the number of stairs.

It is guaranteed that sum of 'N' over all test cases is <= 10^5.
Sample Input 1 :
2
2
3
Sample Output 1 :
2
3
Explanation Of Sample Input 1 :
In the first test case, there are only two ways to climb the stairs, i.e. {1,1} and {2}.

In the second test case, there are three ways to climb the stairs i.e. {1,1,1} , {1,2} and {2,1}.
Sample Input 2 :
2
4
5
Sample Output 2 :
5
8
Explanation Of Sample Input 2 :
In the first test case, there are five ways to climb the stairs i.e. {1,1,1,1} , {1,1,2} , {2,1,1} , {1,2,1} , {2,2}.

In the second test case, there are eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {1,2,2},{2,1,1,1},{2,1,2} and {2,2,1}.


    




    
Each time, you can climb either one step or two steps.


so this ques is same to same as fibonacci series just a little modification and if told that we can climb 0-3 stairs in one go then can add dp[i-3] also



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
brute force using recursion 




and in the below one we are starting from 0 and going till n alright

#include <bits/stdc++.h> 

int mod=1e9;

int solve(int n,int i,vector<int>&dp){
    if(i==n || i==n-1){
        return 1;
    }
    if(i>n){
        return 0;
    }
    
    if(dp[i]!=-1){
        return dp[i]%mod;
    }
    dp[i]=(solve(n,i+1,dp)+solve(n,i+2,dp))%mod;
    return dp[i];
}

int countDistinctWays(int nStairs) {

    //  Write your code here.''

    vector<int>dp(nStairs+1,-1);
    int ans=solve(nStairs,0,dp);
    return ans;

}

but it will cause tle okkkkk

    Time Complexity: O( 2 ^ N )
    Space complexity: O( N )



//in this code bottom-up is used and memorization is also used 

 #include <bits/stdc++.h> 
 using namespace std;

int mod=1e9+7;


int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1,-1);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=nStairs;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[nStairs];
}




 Time Complexity: O( N )
    Space complexity: O( N )


can use the following for top-bottom approach


 #include <bits/stdc++.h> 
 using namespace std;

int mod=1e9+7;


int solve(int n,vector<int>&dp){
    if(n<=1) return 1; //because 0 se aane ka bhi 1 man liya and 1 tk aane ka to 1 hi hai that's why

    if(dp[n]!=-1) return dp[n];

    dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
    return dp[n];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1,-1);
    return solve(nStairs,dp);
}





//space optimized
#include <bits/stdc++.h> 

int mod=1e9+7;

int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1,-1);
    
    int a=1;
    int b=1;

    for(int i=2;i<=nStairs;i++){
        int c=(a+b)%mod;
        a=b;
        b=c;
    }
    return b;
}


or can also use bottom up appraoch with only dp 

 Time Complexity: O( N )
    Space complexity: O( 1)

