Coin Change (Count Ways)
Difficulty: MediumAccuracy: 43.1%Submissions: 289K+Points: 4
Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 

Examples:

Input: coins[] = [1, 2, 3], sum = 4
Output: 4
Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
Input: coins[] = [2, 5, 3, 6], sum = 10
Output: 5
Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
Input: coins[] = [5, 10], sum = 3
Output: 0
Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.
Constraints:
1 <= sum <= 103
1 <= coins[i] <= 104
1 <= coins.size() <= 103



this is similar to one ques in which we have to return min coins to meet the target alright 








class Solution {
  public:
    int solve(int idx,vector<int>&num,int x){
        if(x==0) return 1;
        
        if(x<0 or idx>=num.size()) return 0;
        
        return solve(idx,num,x-num[idx])+solve(idx+1,num,x);
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        return solve(0,coins,sum);
    }
};


top down :

here both idx and x are changing so we have to prepare a 2D dp alright so do accordingly


class Solution {
  public:
    int solve(int idx,vector<int>&num,int x,vector<vector<int>>&dp){
        if(x==0) return 1;
        
        if(x<0 or idx>=num.size()) return 0;
        
        if(dp[idx][x]!=-1) return dp[idx][x];
        
        dp[idx][x]=solve(idx,num,x-num[idx],dp)+solve(idx+1,num,x,dp);
        return dp[idx][x];
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>>dp(coins.size()+1,vector<int>(sum+1,-1));
        return solve(0,coins,sum,dp);
    }
};

t.c:-O(n*sum) and same s.c okk



tabulation 

class Solution {
  public:
    
    int count(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case: Making sum 0 is always possible (using no coins)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int idx = 1; idx <= n; idx++) {
        for (int x = 0; x <= sum; x++) {
            dp[idx][x] = dp[idx - 1][x];  // Exclude the coin
            if (x >= coins[idx - 1]) {
                dp[idx][x] += dp[idx][x - coins[idx - 1]];  // Include the coin
            }
        }
    }
    return dp[n][sum];
}

};
