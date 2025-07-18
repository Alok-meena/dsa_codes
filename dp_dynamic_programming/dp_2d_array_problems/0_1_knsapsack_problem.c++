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

mostly start with 0 only it will be easy to understand alright

 #include <bits/stdc++.h> 

int solve(vector<int>&weight,vector<int>&value,int n,int capacity,int idx){
  if(idx==n-1){
    if(weight[idx]<=capacity){ //if we not return like this then also it is fine
      return value[idx];
    }
    else return 0;
  }

  int include=0; //very imp to initialize the include o/w get garbage value which will be wrong alright
  if(weight[idx]<=capacity){
    include=value[idx]+solve(weight,value,n,capacity-weight[idx],idx+1);
  }

  int exclude=0+solve(weight,value,n,capacity,idx+1); // 0 add hamne understanding ke liye kiya hai just o/w no need of it

  return max(include,exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  return solve(weight,value,n,maxWeight,0);
}


or can do this with a diff wt factor also

#include <bits/stdc++.h> 

int solve(int i,int wt,vector<int>&weight,vector<int>&value,int maxWeight,int n,vector<vector<int>>&dp){
  if(i>=n){
    // if(wt+weight[i]<=maxWeight){
    //   return value[i];
    // }
    return 0;
  }

  if(dp[i][wt]!=-1) return dp[i][wt];

  int op1=0,op2=0;
  op2=solve(i+1,wt,weight,value,maxWeight,n,dp);

  if(wt+weight[i]<=maxWeight){
    op1=value[i]+solve(i+1,wt+weight[i],weight,value,maxWeight,n,dp);
  }

  return dp[i][wt]=max(op1,op2);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
  return solve(0,0,weight,value,maxWeight,n,dp);
}


the bottom up

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));

  for(int wt=0;wt<=maxWeight;wt++){
    if(wt+weight[n-1]<=maxWeight){
      dp[n-1][wt]=value[n-1];
    }
  }
  
  for(int i=n-2;i>=0;i--){
    for(int wt=maxWeight;wt>=0;wt--){
      int op1=0,op2=0;
      op2=dp[i+1][wt];

      if(wt+weight[i]<=maxWeight){
        op1=value[i]+dp[i+1][wt+weight[i]];
      }

      dp[i][wt]=max(op1,op2);
    }
  }
  return dp[0][0];
}


space optimization

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
  
  for(int capacity=0;capacity<=maxWeight;capacity++){
    if(weight[n-1]<=capacity){
      dp[n-1][capacity]=value[n-1];
    }
  }

  for(int i=n-2;i>=0;i--){
    for(int capacity=0;capacity<=maxWeight;capacity++){
      int op1=0,op2=0;
      op2=dp[i+1][capacity];

      if(weight[i]<=capacity){
        op1=value[i]+dp[i+1][capacity-weight[i]];
      }

      dp[i][capacity]=max(op1,op2);
    }
  }
  return dp[0][maxWeight];
} 


in above one idx i and capacity is curr row and i+1 ( whatever the capacity is the next row alright


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
  vector<int>next(maxWeight+1,0);
  vector<int>curr(maxWeight+1,0);
  
  for(int capacity=0;capacity<=maxWeight;capacity++){
    if(weight[n-1]<=capacity){
      curr[capacity]=value[n-1];
    }
  }

  next=curr; //in this curr is updated but then also update the next row alright

  for(int i=n-2;i>=0;i--){
    for(int capacity=0;capacity<=maxWeight;capacity++){
      int op1=0,op2=0;
      op2=next[capacity];

      if(weight[i]<=capacity){
        op1=value[i]+next[capacity-weight[i]];
      }

      curr[capacity]=max(op1,op2);
    }
    next=curr;
  }
  return next[maxWeight];
} 


in this this optimization is just as per to above code

more optimized

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
  vector<int>curr(maxWeight+1,0);
  
  for(int capacity=0;capacity<=maxWeight;capacity++){
    if(weight[n-1]<=capacity){
      curr[capacity]=value[n-1];
    }
  }


  for(int i=n-2;i>=0;i--){
    for(int capacity=maxWeight;capacity>=0;capacity--){
      int op1=0,op2=0;
      op2=curr[capacity];

      if(weight[i]<=capacity){
        op1=value[i]+curr[capacity-weight[i]];
      }

      curr[capacity]=max(op1,op2);
    }
  }
  return curr[maxWeight];
} 

1 hi vector use kiya because dekho curr value either apne curr y next pe depend kr rhi thi to bs 

like this

  
#include <bits/stdc++.h> 

int solve(vector<int>&weight, vector<int>&value,int index, int capacity){
	//if only one item to steal then just compare it's weight with maxweight
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		else{
			return 0;
		}
	}

	int include=0;

	//now ab ham jis item pe hai vo condn full fill kiya to include kr lo nhi to exclude

	if(weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);//update capactiy and index both
	}

	int exclude=0+solve(weight,value,index-1,capacity);//dont update capacity as it is not consumed
	int ans=max(exclude,include);
	return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight,value,n-1,maxWeight);
}

2:memorization

 #include <bits/stdc++.h> 

int solve(vector<int>&weight,vector<int>&value,int n,int capacity,int idx,vector<vector<int>>&dp){
  if(idx==n-1){
    if(weight[idx]<=capacity){
      return value[idx];
    }
    else return 0;
  }

  if(dp[idx][capacity]!=-1) return dp[idx][capacity];

  int include=0;
  if(weight[idx]<=capacity){
    include=value[idx]+solve(weight,value,n,capacity-weight[idx],idx+1,dp);
  }

  int exclude=0+solve(weight,value,n,capacity,idx+1,dp);

  dp[idx][capacity]=max(include,exclude);
  return dp[idx][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
  return solve(weight,value,n,maxWeight,0,dp);
}

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
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));// and it has n rows and maxweight+1 columns with each -1 &&&& aor columns ko vector type diya hai 
  //is code me index aor capacity 2 variable change ho rhe hai so we require a 2D array
	return solve(weight,value,n-1,maxWeight,dp);
}



3rd:bottom up 


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
  for(int wt=0;wt<=maxWeight;wt++){
    if(weight[n-1]<=wt){
      dp[n-1][wt]=value[n-1];
    }
  }

  for(int i=n-2;i>=0;i--){
    for(int w=0;w<=maxWeight;w++){
      int include=0;
      if(weight[i]<=w){
        include=value[i]+dp[i+1][w-weight[i]];
      }

      int exclude=0+dp[i+1][w];

      dp[i][w]=max(include,exclude);
    }
  }

  return dp[0][maxWeight];
}

very imp


#include <bits/stdc++.h>
#include <vector>

int solve2(vector<int> &weight, vector<int> &value, int n, int capacity) {
  // step 1
  vector<vector<int>> dp(n, vector<int>(capacity + 1,0));

  // base case
  // to isme uper ki jaise 0th row ka logic lgana hai
  for (int w = weight[0]; w <=capacity; w++) {
    if (weight[0] <= capacity) {
      dp[0][w] = value[0];
    } else {
      dp[0][w] = 0;
    }
  }

  // now ab 0th row ka ho gya to ab 1 se n-1 means <n tk and 2nd loop 0 se
  // <=maxweight

  for (int index = 1; index < n; index++) {
    for (int w = 0; w <= capacity; w++) {
      int include = 0;

      if (weight[index] <= w) {
        include = value[index] +
                  dp[index - 1][w - weight[index]];
      }
      int excl = 0 + dp[index-1][w];

      dp[index][w] =max(include, excl);
    }
  }
  return dp[n-1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  return solve2(weight, value, n, maxWeight);
}






Time Complexity
O(index * W), where ‘N’ is the number of items and ‘W’ is the weight of bag.

Space Complexity
O(n*maxweight), where maxweight is the weight of bag.

4:space optimized

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
 //as our curr values are dependent on next idx+1 so we made an array for that okk and similarly one for current right
  vector<int>next(maxWeight+1,0);
  vector<int>curr(maxWeight+1,0);
  for(int wt=0;wt<=maxWeight;wt++){
    if(weight[n-1]<=wt){
      next[wt]=value[n-1];
    }
  }

  for(int idx=n-2;idx>=0;idx--){
    for(int wt=0;wt<=maxWeight;wt++){
      int include=0; //very imp to initialize the include o/w get garbage value which will be wrong alright
      if(weight[idx]<=wt){
        include=value[idx]+next[wt-weight[idx]];
      }

      int exclude=0+next[wt]; // 0 add hamne understanding ke liye kiya hai just o/w no need of it

      curr[wt]=max(include,exclude);
    }
    next=curr;
  }
  return next[maxWeight];
}

below is the case in recursion from n-1 to 0  okk




#include <bits/stdc++.h>
#include <vector>

int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {
  // step 1
  //to har row apni pichli vali pe hi depend kr rhi hai so we can also do space optimization
  //we require only two rows then we will update each 

  vector<int>prev(capacity+1,0); //ab suno dhyan se okk ab rows to chahihe nhi bs 2 row se kam chl rha hai to unki size to col ke acco hi hogi that's why alright
  vector<int>curr(capacity+1,0);

  for (int w = weight[0]; w <=capacity; w++) {
    if (weight[0] <= capacity) {
      prev[w] = value[0];
    } else {
      prev[w] = 0;
    }
  }

  //step 3

 //index -1 is prev and index is curr
  for (int index = 1; index < n; index++) {
    for (int w = 0; w <= capacity; w++) {
      int include = 0;

      if (weight[index] <= w) {
        include = value[index] +
                  prev[w - weight[index]];
      }
      int excl = 0 + prev[w];

      curr[w] =max(include, excl);
    }
    prev=curr;
  }
  return prev[capacity];//prev becaue hamne dp[n-1][capacity] return kiya tha
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

  return solve(weight,value,n,maxWeight);


}


t.c:- O(index ^ w) and s.c:- O(2*maxweight)



5: s.c to O(W)

#include <bits/stdc++.h>
#include <vector>

int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {
  // step 1
  //to har row apni pichli vali pe hi depend kr rhi hai so we can also do space optimization
  //we require only two rows then we will update each 

  vector<int>curr(capacity+1,0);

  for (int w = weight[0]; w <=capacity; w++) {
    if (weight[0] <= capacity) {
      curr[w] = value[0];
    } else {
       curr[w] = 0;
    }
  }

  //step 3

  for (int index = 1; index < n; index++) {
    for (int w = capacity; w>=0; w--) {
      int include = 0;

      if (weight[index] <= w) {
        include = value[index] +
                  curr[w - weight[index]];
      }
      int excl = 0 + curr[w];

      curr[w] =max(include, excl);
    }
  }
  return curr[capacity];//prev becaue hamne dp[n-1][capacity] return kiya tha
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

  return solve(weight,value,n,maxWeight);


}
