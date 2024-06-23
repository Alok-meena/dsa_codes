
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
