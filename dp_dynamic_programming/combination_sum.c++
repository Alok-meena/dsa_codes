
You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the 
array are there such that the sum of chosen elements is equal to the target number tar.

Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1]
both way1 and way 2 are the same.

But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

Input is given such that the answer will fit in a 32-bit integer. For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.



1:recusion 

//bs khuch nhi sbhi no. ke liye call krke dekha hai
#include <bits/stdc++.h> 


int solve(vector<int>&num , int target){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }

    int ans=0;

    for(int i=0;i<num.size();i++){
        ans+=solve(num,target-num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solve(num,tar);
}


2:memorization


#include <bits/stdc++.h> 



int solve(vector<int>&num , int target,vector<int>&dp){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }

    if(dp[target]!=-1){
        return dp[target];
    }

    int ans=0;

    for(int i=0;i<num.size();i++){
        ans+=solve(num,target-num[i],dp);
    }

    dp[target]=ans;
    return dp[target];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    //here we require 1D array because only the target is changing
    vector<int>dp(tar+1,-1);//size is tar+1 because hme har ek sum ki value store krni hai ookk
    return solve(num,tar,dp);
}


3:tabulation


#include <bits/stdc++.h> 



int solve(vector<int>&num , int target){
    vector<int>dp(target+1,0);

    dp[0]=1;

   //because uper dekho har ek no. ke liye solve call ho rha hai
    for(int i=1;i<=target;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0){
                dp[i]+=dp[i-num[j]];
            }
        }
    }
    
    return dp[target];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solve(num,tar);
}


spcae optimization is not possible because dp[i] is depending on dp[i-num[j]] so we dont know on which block it depends
