Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.



All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.



You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.



Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.


For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.




this is same as max no. of non-adjacent elements just difference is elements are present in circular 1st and last are adjacent handle in 2 cases
just make two array and in one take 1st and dont include last and reverse in second array send both to fun and then return max ans


#include <bits/stdc++.h> 

long long int solve(int idx,vector<int>&house){
    if(idx<0) return 0;

    if(idx==0) return house[idx];


    int exc=solve(idx-1,house)+0;

    int inc=solve(idx-2,house)+house[idx];

    return max(exc,inc);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();

    if(n==1) return valueInHouse[0]; //ye case jruri hai because ager hamen first ko choda aor last ko to dono cases me hi ye single vala cover nhi hoga that's why
    
    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(n-2,first),solve(n-2,second));
}

exponential


here directly most optimized approach is used alright

#include <bits/stdc++.h> 

long long int solve(vector<int>&nums,int n){
    long long int prev1=0;//because base case if n<0 then return 0
    long long int prev2=nums[0];

    for(int i=1;i<n;i++){
        long long int incl=prev1+nums[i];
        long long int excl=prev2+0;
        long long int ans=max(incl,excl);
        prev1=prev2;
        prev2=ans;
    }

    return prev2;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }

    vector<int>start,end;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            start.push_back(valueInHouse[i]);
        }
        if(i!=0){
            end.push_back(valueInHouse[i]);
        }
    }
    return max(solve(start,start.size()),solve(end,end.size()));
}
