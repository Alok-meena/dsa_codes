Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. 
Considering the constraints of the maximum weight that a knapsack can carry,
you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13


1:recursion---

  
#include <bits/stdc++.h> 

int solve(vector<int>&weight, vector<int>&value,int index, int capacity){
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		else{
			return 0;
		}
	}

	int include=0;

	if(weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	}

	int exclude=0+solve(weight,value,index-1,capacity);
	int ans=max(exclude,include);
	return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vec
	return solve(weight,value,n-1,maxWeight);
}

2:memorization

#include <bits/stdc++.h> 
#include <vector>

int solve(vector<int>&weight, vector<int>&value,int index, int capacity,vector<vector<int>>&dp){
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		else{
			return 0;
		}
	}

	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}

	int include=0;

	if(weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
	}

	int exclude=0+solve(weight,value,index-1,capacity,dp);
	dp[index][capacity]=max(exclude,include);
	return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));//aor columns ko vector type diya hai 
  //is code me index aor capacity 2 variable change ho rhe hai so we require a 2D array
	return solve(weight,value,n-1,maxWeight,dp);
}
