Partitions with Given Difference
Difficulty: MediumAccuracy: 36.76%Submissions: 170K+Points: 4Average Time: 20m
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2



it's explanation is explained alright


class Solution {
  public:
    int solve(vector<int>&arr,int target,int idx,vector<vector<int>>&dp){
        if(idx==arr.size()){
            if(target==0){
                return 1;
            }
            else return 0;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];
        
        //include
        int inc=0,exc=0;
        if(arr[idx]<=target) inc=solve(arr,target-arr[idx],idx+1,dp);
        exc=solve(arr,target,idx+1,dp);
        
        dp[idx][target]=inc+exc;
        return dp[idx][target];
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum=0;
        for(auto i:arr) sum+=i;
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
        return solve(arr,target,0,dp);
    }
};

s1-s2=d alright then s1+s2=sum so s1=sum+d/2 alright and therefore sum+d should not be odd so it is checked before target is calculated alright and then 
we just have to check how many subsets with this target

we can also use sum-d as our formula but for that we have to also add a check for if sum<d then return 0 alright 
