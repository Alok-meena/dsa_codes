188. Best Time to Buy and Sell Stock IV
Solved
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.\


SAME QUES THE CHANGE IS THAT NOW YOU CAN MAKE ATMOST K TRANSACTIONS




space optimization

can try other solutions also

class Solution {
public:
int solve(int k,vector<int>&prices){
        int n=prices.size();

        vector<vector<int>>curr(2,vector<int>(k+1,0));//dp[index+1] is next and index is curr
        vector<vector<int>>next(2,vector<int>(k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int time=1;time<=k;time++){
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
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices);
    }
};

t.c:-O(n*2*k) and s.c:-O(2*k)




NOW WE WILL USE operationNo. to solve this ques why it is even then we buy and when it is odd then we sell and do until 2*k operations as
int k times contain both buy and sell so 

1:recursion

class Solution {
public:
int solve(int k,vector<int>&prices){
        int n=prices.size();

        vector<vector<int>>curr(2,vector<int>(k+1,0));//dp[index+1] is next and index is curr
        vector<vector<int>>next(2,vector<int>(k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int time=1;time<=k;time++){
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
        return next[1][k];
    }

    int solve(int index,int k,int operationNo,vector<int>&prices){
        if(index==prices.size() || operationNo==2*k){//as we will increase O.No for each buy and sell
            return 0;
        }

        int ans=0;
        if(operationNo%2==0){
               int profit1=-prices[index]+solve(index+1,k,operationNo+1,prices);
               int ignore1=0+solve(index+1,k,operationNo,prices);
               ans=max(profit1,ignore1);
        }
        else{
               int profit2=prices[index]+solve(index+1,k,operationNo+1,prices);
               int ignore2=0+solve(index+1,k,operationNo,prices);
               ans=max(profit2,ignore2);
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,k,0,prices);
    }
};


2:memorization

class Solution {
public:

    int solve(int index,int k,int operationNo,vector<int>&prices,vector<vector<int>>&dp){
        if(index==prices.size() || operationNo==2*k){//as we will increase O.No for each buy and sell
            return 0;
        }
        if(dp[index][operationNo]!=-1){
            return dp[index][operationNo];
        }

        int ans=0;
        if(operationNo%2==0){
               int profit1=-prices[index]+solve(index+1,k,operationNo+1,prices,dp);
               int ignore1=0+solve(index+1,k,operationNo,prices,dp);
               ans=max(profit1,ignore1);
        }
        else{
               int profit2=prices[index]+solve(index+1,k,operationNo+1,prices,dp);
               int ignore2=0+solve(index+1,k,operationNo,prices,dp);
               ans=max(profit2,ignore2);
        }
        return dp[index][operationNo]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
        return solve(0,k,0,prices,dp);
    }
};

3:bottom-up

  class Solution {
public:

   
    int solve(vector<int>&prices,int k){
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int operationNo=2*k-1;operationNo>=0;operationNo--){
                int ans=0;
                if(operationNo%2==0){
                    int profit1=-prices[index]+dp[index+1][operationNo+1];
                    int ignore1=0+dp[index+1][operationNo];
                    dp[index][operationNo]=max(profit1,ignore1);
                }
                else{
                    int profit2=prices[index]+dp[index+1][operationNo+1];
                    int ignore2=0+dp[index+1][operationNo];
                    dp[index][operationNo]=max(profit2,ignore2);
        }
            }
        }    
        return dp[0][0];  
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }
};

s.c:O(n*2k) and same for time

4:space optimized

class Solution {
public:

   
    int solve(vector<int>&prices,int k){
        int n=prices.size();
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);

        for(int index=n-1;index>=0;index--){
            for(int operationNo=2*k-1;operationNo>=0;operationNo--){
                int ans=0;
                if(operationNo%2==0){
                    int profit1=-prices[index]+next[operationNo+1];
                    int ignore1=0+next[operationNo];
                    curr[operationNo]=max(profit1,ignore1);
                }
                else{
                    int profit2=prices[index]+next[operationNo+1];
                    int ignore2=0+next[operationNo];
                    curr[operationNo]=max(profit2,ignore2);
        }
        next=curr;
            }
        }    
        return next[0];  
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }
};

t.c:-O(n*k) and s.c:-O(k)
