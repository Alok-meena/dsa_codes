122. Best Time to Buy and Sell Stock II
Solved
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.







1:recursion



class Solution {
public:
    int solve(vector<int>&prices,int i,int buy){
        if(i==prices.size()){
            return 0;
        }
        
        int ans;
        if(buy){
           int profit1=-prices[i]+solve(prices,i+1,0);
           int ignore1=0+solve(prices,i+1,1);
            ans=max(profit1,ignore1);
        }
        else{
           int profit2=prices[i]+solve(prices,i+1,1);
           int ignore2=0+solve(prices,i+1,0);
            ans=max(profit2,ignore2);
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,1);
    }
};

2:memorization


class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        
        int ans;
        if(buy){
           int profit1=-prices[i]+solve(prices,i+1,0,dp);//buy kr liya to ab nhi kr skte buy to 0 kr diya
           int ignore1=0+solve(prices,i+1,1,dp);//1 to ignore kiya means buy nhi kiya to abhi bhi kr skte hai
            ans=max(profit1,ignore1);
        }
        else{
           int profit2=prices[i]+solve(prices,i+1,1,dp);//sell kr diya to 1 because ab buy kr skte hai ham
           int ignore2=0+solve(prices,i+1,0,dp);//because sell nhi kiya to 0
            ans=max(profit2,ignore2);
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};

3:bottom-up

  class Solution {
public:
    int solve(vector<int>&prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int ans;
                if(buy){
                int profit1=-prices[i]+dp[i+1][0];
                int ignore1=0+dp[i+1][1];
                 dp[i][buy]=max(profit1,ignore1);
                }
                else{
                int profit2=prices[i]+dp[i+1][1];
                int ignore2=0+dp[i+1][0];
                    dp[i][buy]=max(profit2,ignore2);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};

t.c:-O(n) and s.c:-O(n)

4:space optimization


class Solution {
public:
 
    int solve(vector<int>&prices){
        int n=prices.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int ans;
                if(buy){
                int profit1=-prices[i]+next[0];
                int ignore1=0+next[1];
                 curr[buy]=max(profit1,ignore1);
                }
                else{
                int profit2=prices[i]+next[1];
                int ignore2=0+next[0];
                    curr[buy]=max(profit2,ignore2);
                }
            }
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};

t.c:-O(n) and s.c:-O(1)
