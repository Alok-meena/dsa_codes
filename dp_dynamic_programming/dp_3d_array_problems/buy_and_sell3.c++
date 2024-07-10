123. Best Time to Buy and Sell Stock III
Solved
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

  

JUST SET A LIMIT OF TIME OF 2 TIMES BUY AND SELL AND DECREMENT TIME ONLY AFTER SELLING THE BOUGHT ITEM / STOCK


  
1:recursion


class Solution {
public:
 
    int solve(vector<int>&prices,int index,int buy){
        if(index==prices.size() || time==0 ){
            return 0;
        }
      
        int ans;

        if(buy){
            int profit=-prices[index]+solve(prices,index+1,0,time);
            int ignore=0+solve(prices,index+1,1,time);
            ans=max(profit,ignore);
        }
        else{
            int sell=prices[index]+solve(prices,index+1,1,time-1);//decrease time only after buy and then sell
            int ignore=0+solve(prices,index+1,0,time);
            ans=max(sell,ignore);
        }
        return dp[index][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,1,2);
    }
};





2:memorization

class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,int time,vector<vector<vector<int>>>&dp){
        if(index==prices.size() || time==0){
            return 0;
        }
        
        if(dp[index][buy][time]!=-1){
            return dp[index][buy][time];
        }
  
        int ans;

        if(buy){
            int profit=-prices[index]+solve(prices,index+1,0,time,dp);
            int ignore=0+solve(prices,index+1,1,time,dp);
            ans=max(profit,ignore);
        }
        else{
            int sell=prices[index]+solve(prices,index+1,1,time-1,dp);
            int ignore=0+solve(prices,index+1,0,time,dp);
            ans=max(sell,ignore);
        }
        return dp[index][buy][time]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //bs khuch nhi array ke ander 2d array chahihe for buy and time
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));//n for index 2 for buy and sell and 3 for time can be 2 1 0
        return solve(prices,0,1,2,dp);
    }
};

3:  bottom-up approach 

class Solution {
public:
    
    int solve(vector<int>&prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));//n for index 2 for buy and sell and 3 for time can be 2 1 0

        //just reverse all of the loops
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int time=1;time<=2;time++){
                    int ans;

                    if(buy){
                        int profit=-prices[index]+dp[index+1][0][time];
                        int ignore=0+dp[index+1][1][time];
                        dp[index][buy][time]=max(profit,ignore);
                    }
                    else{
                        int sell=prices[index]+dp[index+1][1][time-1];
                        int ignore=0+dp[index+1][0][time];
                        dp[index][buy][time]=max(sell,ignore);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};

t.c:=O(n*2*3)=O(n) and s.c:-O(n*2*3)


4:space optimization

class Solution {
public:
    
    int solve(vector<int>&prices){
        int n=prices.size();

        vector<vector<int>>curr(2,vector<int>(3,0));//dp[index+1] is next and index is curr
        vector<vector<int>>next(2,vector<int>(3,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int time=1;time<=2;time++){
                    int ans;

                    if(buy){
                        int profit=-prices[index]+next[0][time];
                        int ignore=0+next[1][time];
                        curr[buy][time]=max(profit,ignore);
                    }
                    else{
                        int sell=prices[index]+next[1][time-1];
                        int ignore=0+next[0][time];
                        curr[buy][time]=max(sell,ignore);
                    }
                }
                next=curr;
            }
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};

t.c:O(n) and s.c:-O(1)
