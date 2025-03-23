Perfect Sum Problem
Difficulty: MediumAccuracy: 20.58%Submissions: 498K+Points: 4
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 103
0 ≤ target ≤ 103

just have to count the no. of subsets whose sum equals target alright

one way is using recursion saving all possible subsets and chhecking each subset sum if equal to target then do count++ alright 

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
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
        return solve(arr,target,0,dp);
        
    }
};
