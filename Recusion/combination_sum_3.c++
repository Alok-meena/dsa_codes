
Code
Test Result
Testcase
Testcase
216. Combination Sum III
Solved
Medium
Topics
premium lock icon
Companies
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60






class Solution {
public:
    void solve(int i,int tar,int k,vector<vector<int>>&ans,vector<int>v,vector<int>&nums){
        if(i>=nums.size()){
            if(tar==0 and v.size()==k) ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        solve(i+1,tar-nums[i],k,ans,v,nums);
        v.pop_back();

        solve(i+1,tar,k,ans,v,nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9,0);
        for(int i=0;i<9;i++){
            nums[i]=i+1;
        }

        vector<vector<int>>ans;
        vector<int>v;
        solve(0,n,k,ans,v,nums);

        return ans;
    }
};
