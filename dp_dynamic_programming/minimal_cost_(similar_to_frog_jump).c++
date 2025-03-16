Minimal Cost
Difficulty: MediumAccuracy: 51.08%Submissions: 97K+Points: 4Average Time: 20m
Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Constraints:

1 <= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104


normal recursion : exponential

class Solution {
  public:
    int solve(int idx,int k,vector<int>&height){
        
        if(idx<=0) return 0;
        
        int cost=1e9;
        //jump from i-1 index
        for(int j=1;j<=k;j++){
            if(idx-j>=0){
                cost=min(cost,solve(idx-j,k,height)+abs(height[idx-j]-height[idx]));
            }
        }
        
        return cost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        return solve(arr.size()-1,k,arr);
    }
};

memorization (top-down)

class Solution {
  public:
    int solve(int idx,int k,vector<int>&height,vector<int>&dp){
        
        if(idx<=0) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int cost=1e9;
        //jump from i-1 index
        for(int j=1;j<=k;j++){
            if(idx-j>=0){
                cost=min(cost,solve(idx-j,k,height,dp)+abs(height[idx-j]-height[idx]));
            }
        }
        
        return dp[idx]=cost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int>dp(arr.size()+1,-1);
        return solve(arr.size()-1,k,arr,dp);
    }
};

t.c:-O(n*k) and s.c:-O(n)

tabulation 


class Solution {
  public:
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int>dp(arr.size()+1,-1);
        int n=arr.size();
        
        dp[0]=0;
        

        for(int idx=1;idx<n;idx++){
            int cost=1e9;
            
            for(int j=1;j<=k;j++){
                if(idx-j>=0){
                    cost=min(cost,dp[idx-j]+abs(arr[idx-j]-arr[idx]));
                }
            }
            dp[idx]=cost;
        }
        return dp[n-1];
    }
};

t.c:-O(n*k) and s.c:-O(n)


but here we cant optimize space as the current state is depending on multiple previous states not only on some states okk that's why

