
Code
Testcase
Testcase
Test Result
46. Permutations
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.





class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,ans);
            // swap(nums[idx],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        solve(0,nums,ans);

        return ans;
    }
};


t.c:-O(n*n!) and same s.c alright

because total permutations will be n! and the no. of times the elements are copied into the ans so O(n) factor is also included


class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,int idx){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(nums,ans,idx+1);
            swap(nums[i],nums[idx]); // can skip if nums is pass by value alright
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        int idx=0;

        solve(nums,ans,0);

        return ans;
    }
};

2nd time
