Given a number N. Find the minimum number of squares of any number that sums equal to N. For Example: 
If N = 100, N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as the minimum number of square is 1, i.e (10*10).
 

Example 1:

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100
Example 2:

Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6





1:recursion

class Solution{
	public:
	
	int solve(int n){
	    if(n==0){
	        return 0;
	    }
	    
	    int ans=n;
	    
	    for(int i=1;i*i<=n;i++){
	        int t=i*i
	        ans=min(ans,1+solve(n-t));//because i*i on this stop only not initializing
	    }
	    
	    return ans;
	}
	int MinSquares(int n)
	{
	    // Code here
	    return solve(n);
	}
};

t.c:- O(root(n)^n) and s.c :- O(n)


2:memorization

class Solution{
	public:
	
	int solve(int n,vector<int>&dp){
	    if(n==0){
	        return 0;
	    }
	    
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    
	    int ans=n;
	    
	    for(int i=1;i*i<=n;i++){
	        int t=i*i;
	        ans=min(ans,1+solve(n-t,dp));//because i*i on this stop only not initializing
	    }
	    
	    dp[n]=ans;
	    
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    vector<int>dp(n+1,-1);
	    return solve(n,dp);
	}
};

t.c:-O(n*(root(n)) s.c:-(N)  because yha bhi n no. ke liye root(n) time call kiya

3:tabulation

//to ham uper har ek number ke liye call kar rhe recusion to yha bhi vhi karna hoga



class Solution{
	public:
	
	int solve(int n){
	    vector<int>dp(n+1,INT_MAX);
	    dp[0]=0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j*j<=n;j++){//can also do j*j<=i because we ar calculating for i only
	            int t=j*j;
	            if(i-t>=0){
	                dp[i]=min(dp[i],1+dp[i-t]);
	            }
	        }
	    }
	    
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    return solve(n);
	}
};

t.c:-O(n*(root(n)) s.c:-(N)


we cant do space optimization as there is no exact pattern as dp[i] depend on dp[i-t] which can lie in any block
