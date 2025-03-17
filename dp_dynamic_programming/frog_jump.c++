Frog Jump
Difficulty: MediumAccuracy: 49.55%Submissions: 121K+Points: 4Average Time: 15m
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Example:

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30
Constraints:

1 <= height.size() <= 105
0 <= height[i]<=104

normal recursive code:



class Solution {
  public:
    int solve(int idx,vector<int>&height){
        
        if(idx<=0) return 0;
        
        int cost1=1e9,cost2=1e9;
        //jump from i-1 index
        if(idx-1>=0){
            cost1=solve(idx-1,height)+abs(height[idx-1]-height[idx]);
        }
        
        //jump from i-2 index
        if(idx-2>=0){
            cost2=solve(idx-2,height)+abs(height[idx-2]-height[idx]);
        }
        
        return min(cost1,cost2);
    }
    int minCost(vector<int>& height) {
        // Code here
        return solve(height.size()-1,height);
    }
};


but the base case is handling the bound check so no need to explicitely checking bounds so can do like this 


  public:
    int solve(int idx,vector<int>&height){
        if(idx<=0) return 0;
        
        int cost1=1e9,cost2=1e9;
        
        
        
        return min(solve(idx-1,height)+abs(height[idx-1]-height[idx]),solve(idx-2,height)+abs(height[idx-2]-height[idx]));
        
    }
    int minCost(vector<int>& height) {
        // Code here
        
        return solve(height.size()-1,height);
    }
};


t.c:- exponential

top down approach with memorization t.c :-O(n) and s.c:-O(n) 


class Solution {
  public:
    int solve(int idx,vector<int>&height,vector<int>&dp){
        
        if(idx<=0) return 0;
        
        int cost1=1e9,cost2=1e9;
        
        if(dp[idx]!=-1) return dp[idx];
        
        //jump from i-1 index
        if(idx-1>=0){
            cost1=solve(idx-1,height,dp)+abs(height[idx-1]-height[idx]);
        }
        
        //jump from i-2 index
        if(idx-2>=0){
            cost2=solve(idx-2,height,dp)+abs(height[idx-2]-height[idx]);
        }
        
        return dp[idx]=min(cost1,cost2);
    }
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size()+1,-1);
        return solve(height.size()-1,height,dp);
    }
};

class Solution {
  public:
    int solve(int idx,vector<int>&height,vector<int>&dp){
        if(idx<=0) return 0;
        if(idx==1) return abs(height[1]-height[0]);
        
        int cost1=1e9,cost2=1e9;
        
        if(dp[idx]!=-1) return dp[idx];
        
        
        
        dp[idx]=min(solve(idx-1,height,dp)+abs(height[idx-1]-height[idx]),solve(idx-2,height,dp)+abs(height[idx-2]-height[idx]));
        return dp[idx];
    }
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size()+1,-1);
        
        return solve(height.size()-1,height,dp);
    }
};

in this case we have to add that idx==1 case also 


bottom up approach (tabulation)



int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size()+1,-1);
        int n=height.size();
        
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            int cost1=1e9,cost2=1e9;
        
            //jump from i-1 index
            if(i-1>=0){
                cost1=dp[i-1]+abs(height[i-1]-height[i]);
            }
            
            //jump from i-2 index
            if(i-2>=0){
                cost2=dp[i-2]+abs(height[i-2]-height[i]);
            }
            
            dp[i]=min(cost1,cost2);
        }
        
        return dp[n-1];
    }


t.c:-O(n) and s.c:-O(n)


space optimization 


class Solution {
  public:
   
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        
        if (n == 1) return 0;  // No jump needed if there's only one stone
        if (n == 2) return abs(height[1] - height[0]);  // Only one possible jump 
    
        int a=0;
        int b=abs(height[1]-height[0]);
        
        for(int i=2;i<n;i++){

            //jump from i-1 index
           
            int cost1=b+abs(height[i-1]-height[i]);
            
            
            //jump from i-2 index
            
            int cost2=a+abs(height[i-2]-height[i]);
            
            
            int c=min(cost1,cost2);
            a=b;
            b=c;
        }
        
        return b;
    }
};

t.c:-O(n) and s.c:-O(1)

