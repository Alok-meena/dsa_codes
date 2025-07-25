You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the 
constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, 
leaving the remaining elements in their original order.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

if we start from 0 to n 

int solve(int i,vector<int>&nums){
    if(i>=nums.size()) return 0;

    //skip;
    int nottake=solve(i+1,nums);

    int take=nums[i]+solve(i+2,nums);
    
    return max(nottake,take);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(0,nums);
}


top down + memo

int solve(int i,vector<int>&nums,vector<int>&dp){
    if(i>=nums.size()) return 0;

    if(dp[i]!=-1) return dp[i];

    //skip;
    int nottake=solve(i+1,nums,dp);

    int take=nums[i]+solve(i+2,nums,dp);
    
    return dp[i]=max(nottake,take);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size()+1,-1);
    return solve(0,nums,dp);
}

bottom up

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(nums.size()+2,0);


    for(int i=n-1;i>=0;i--){
        int nottake=dp[i+1];

        int take=nums[i]+dp[i+2];
        
        dp[i]=max(nottake,take);
    }

    return dp[0];
}

space optimization

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(nums.size()+2,0);

    int next1=0;
    int next2=0;

    for(int i=n-1;i>=0;i--){
        int nottake=next1;

        int take=nums[i]+next2;
        
        int curr=max(nottake,take);
        next2=next1;
        next1=curr;
    }

    return next1;
}

this is optimized that's it my lord

    




1st:recusion

#include <bits/stdc++.h> 
int solve(vector<int>&nums,int n){
    if(n<0){//to ham last index se start kr rhe hai to if -ve hua to return 0
        return 0;
    }
    if(n==0){
      
        return nums[0]; //not required mostly
    }

    int incl=solve(nums,n-2)+nums[n]; 
    int excl=solve(nums,n-1)+0;

    return max(incl,excl);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans=solve(nums,nums.size());
    return ans;
}





Time Complexity
O(2^N ), Where ‘N’ is the number of elements in the given array/list.

 

Since for each element in the given array/list, we have two choices, either we can include it into our subsequence or not. 
So for the ‘N’ number, there will be 2 ^ N possible choices. So, the overall time complexity will be O(2 ^ N).

Space Complexity
O(N), Where ‘N’ is the number of elements in the given array/list.

 

Since we are using the recursion for exploring all the possible combinations, so in the worst case when we keep excluding the elements 
from our subsequence then there will be the depth of the recursion tree will be O(N). So, overall space complexity will be O(N).

2nd approach : recursion + memorization



//can use this also
#include <bits/stdc++.h> 
int solve(vector<int>&nums,int n,vector<int>&dp){
    if(n<0){//to ham last index se start kr rhe hai to if -ve hua to return 0
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int incl=solve(nums,n-2,dp)+nums[n];
    int excl=solve(nums,n-1,dp)+0;

    dp[n]=max(incl,excl);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,0);
    int ans=solve(nums,n-1,dp);//here we have to pass the last index
  
    return ans;
}


Time Complexity
O(N), Where ‘N’ is the number of elements in the given array/list.

 

Since we iterate through the given array/list resulting in total ‘N’ iterations, so the overall time complexity will be O(N).

Space Complexity
O(N)+O(N)=O(N), Where ‘N’ is the number of elements in the given array/list.

 

Since we are storing the result of every step in the ‘DP’ array/list of length ‘N’. So there will be ‘N’ elements. So, overall space complexity will be O(N).


approach 3:bottomup tabulation


#include <bits/stdc++.h> 


int solve2(vector<int>&nums,int n){
    vector<int>dp(n,0);
    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        //but not correct as i-2 may be out of bound so use below one
        int incl=dp[i-2]+nums[i];//here i-2 and i-1 because we are not starting from 0 it is from 1 ok!
        int excl=dp[i-1]+0;

        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve2(nums,n);
    return ans;
}

int solve2(vector<int>&nums,int n){
    vector<int>dp(n+1,0);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);

    for(int i=2;i<n;i++){
        int incl=dp[i-2]+nums[i];//here i-2 and i-1 because we are not starting from 0 it is from 1 ok!
        int excl=dp[i-1]+0;

        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}

t.c:-O(N) and s.c:-O(N)

4th approach : space optimization

#include <bits/stdc++.h> 


int solve2(vector<int>&nums,int n){
    int prev1=0;//because base case if n<0 then return 0
    int prev2=nums[0];

    for(int i=1;i<n;i++){//aor iteration to 1 se hi hogi 
        int incl=prev1+nums[i];
        int excl=prev2+0;
        int ans=max(incl,excl);
        prev1=prev2;
        prev2=ans;
    }

    return prev2;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve2(nums,n);
    return ans;
}
t.c:-O(N) and s.c:-O(1)

