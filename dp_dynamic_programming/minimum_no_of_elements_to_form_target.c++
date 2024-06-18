You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. 
You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.


1st : recursion approach : cause TLE
#include <bits/stdc++.h> 

int solve(vector<int>&num,int x){
    if(x==0){//means target achieved
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    int mini=INT_MAX;

    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);//+1 kiya means the current coin is selected ok!
        }
        
    }

    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans=solve(num,x);
    if(ans!=INT_MAX){
        return ans;
    }
    return -1;

}

Time Complexity
O( N^X ), where ‘X’ is the target sum and ‘N’ is the size of the array. (EXPONENTIAL)

 

Each time we have ‘n’ options from which we have to select one and in the worst-case ‘X’ is decreased 
by 1 each time. So, if you try to make the recursive tree you can see each time there will be ‘n’ recursive call generated.

So time complexity will be O( N^X ).

Space Complexity
O(X), where ‘X’ is the sum which we want.

 

The recursive stack for the “minimum” function can contain at most “X”. Therefore, the overall space complexity will be O(X).

2nd approach : recusion + memorization


  
#include <bits/stdc++.h> 

int solve(vector<int>&num,int x,vector<int>&dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    if(dp[x]!=-1){
        return dp[x];
    }

    int mini=INT_MAX;

    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);//+1 kiya means the current coin is selected ok!
        }
        
    }

    dp[x]=mini;//not required as  we used array but if used then

    return mini;//return dp[x]
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();

    vector<int>dp(x+1,-1);
    //The size of the dp array should be x + 1 rather than num.size() + 1 because the dp array is used to store the minimum number of 
    //elements needed to form each value from 0 to x. Here’s a detailed explanation:

    int ans=solve(num,x,dp);
    if(ans!=INT_MAX){
        return ans;
    }
    return -1;

}


Time Complexity
O(N * X), where ‘N’ is the size of the array and ‘X’ is the desired sum.

 

As we can see the dimension of dp is of N*X which means that at max N*X different cases will be made and all the other cases will be repetitive.
Hence the overall time complexity will be O(N * X).

Space Complexity
O(X), where ‘X’ is the desired sum.

 

We use an array ‘DP’ which is of size ‘X’. Hence the space complexity will be O(X).


3rd bottom up


#include <bits/stdc++.h> 

int solveBottomup(vector<int>&num,int x){
    vector<int>dp(x+1,INT_MAX);

    dp[0]=0;//just like base case if 0 is target


  //MTLB ISME EX:- [1,2,3] AND X=7 TO HM YHA 1 BNAYA USING 1,2,3  SE LEKE 7 BNAYA USING 1 ,2,3 T0 ANS AA JAYEGA 
  
    for(int i=1;i<=x;i++){//0 ho gya to 1 se x tk because we want min coin
     //solving for every target value from 1 to x

      //ye loop lgaya because har target ke liye hme 3no ka use karna hai okk
      
        for(int j=0;j<num.size();j++){//we are accessing all the elements of the array
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){//checking if index and value is correct
                dp[i]=min(dp[i],1+dp[i-num[j]]);//just like x-nums[i] yha target i mana to element num[j] ko subtract kiya hai
            }
        }
    }

    if(dp[x]!=INT_MAX){
        return dp[x];
    }
    return -1;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    return solveBottomup(num,x);

}

Time Complexity
O(N * X), where ‘N’ is the size of the array and ‘X’ is the desired sum.

 

As we are using 2 nested for loops one from [0,n-1] and the other from [0,X]. Hence the final time complexity will be O(N * X).

Space Complexity
O(X), where ‘X’ is the desired sum.

 

We are using a 1-d array of size ‘X’. Hence the final space complexity will be O(X).


AND FURTHER SPACE CAN'T BE OPTIMISED BECAUSE JAISE UPER VALE EX:- ME i nums[j] pe depend kr rha to ye krne ke liye hme bahut sare variable bnanae hone NOT POSSIBLE

