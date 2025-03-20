You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.


 and array size is n so only n-1 tk ki cost given hai and we only have to add cost if we jump from that index to next so no need to add destination cost alright
 

class Solution {
public:
    int solve1(vector<int>&cost,int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }


        int ans=min(solve1(cost,n-1),solve1(cost,n-2))+cost[n];
        return ans;
        //it will cause tle
    }
    int solve2(vector<int>&cost,vector<int>&dp,int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        //step 3:-
        if(dp[n]!=-1){
            return dp[n];
        }

        //step2
        dp[n]=min(solve2(cost,dp,n-1),solve2(cost,dp,n-2))+cost[n];
        return dp[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        //normal recursion code
        t.c:-O(2^N) and s.c:-O(N)

      
        int n=cost.size();
        int ans=min(solve1(cost,n-1),solve1(cost,n-2)); //mereko isme confusion thi but the thing is in this ques we can either start from 0 or 1
        //so we have to return the min of both that's why this is done the below code in which we started from 0 is more related to this and easily understandable
        return ans;
    
        //top-down approach with memorization
        t.c:-O(N) and s.c:-O(N)+O(N)=O(N) (recusion (jo stack me calls store hoti hai) and memorization of dp array)

      
        // int n=cost.size();
        step 1:-
        // vector<int>dp(n+1,-1);
        // int ans=min(solve2(cost,dp,n-1),solve2(cost,dp,n-2));
        // return ans;
    }
};


class Solution {
public:
    int solve(vector<int>&cost,int idx,vector<int>&dp){
        if(idx>=cost.size()) return 0; //top floor ki cost given nhi hai so 0 liya

        if(dp[idx]!=-1) return dp[idx];

        int op1=cost[idx]+solve(cost,idx+1,dp);
        int op2=cost[idx]+solve(cost,idx+2,dp);
        
        return dp[idx]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(solve(cost,0,dp),solve(cost,1,dp));
        return ans;
    }
};



2nd approach : - bottom-up approach

class Solution {
public:
    int solve3(vector<int>&cost,int n){
        //creation of dp array
        vector<int>dp(n+1);
        
        //base case analysis
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);//because ham n-2 aor n-1 se cost fill krte hi ja skte hai nth stair pe
    }
    int minCostClimbingStairs(vector<int>& cost) {
       
        
        int n=cost.size();
        int ans=solve3(cost,n);
        return ans;
    }
};

t.c:-O(N) and s.c:-O(N)


3rd approach

class Solution {
public:
    int solve(vector<int>&cost,int n){
        //because    0    1     2 ....
        //        prev1 prev2
         int prev1=cost[0];
        int prev2=cost[1];

        int curr;

        for(int i=2;i<n;i++){ //n tk nhi jayenge as 0 based indexing hai okk
            curr=min(prev1,prev2)+cost[i];
            prev1=prev2;
            prev2=curr;
        }

        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //  int n=cost.size();
        // int ans=min(solve1(cost,n-1),solve1(cost,n-2));
        // return ans;
    

        // int n=cost.size();
        // vector<int>dp(n+1,-1);
        // int ans=min(solve2(cost,dp,n-1),solve2(cost,dp,n-2));
        // return ans;
        
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
    }
};

t.c:- O(N) and s.c:- O(1)
