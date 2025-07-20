368. Largest Divisible Subset
Solved
Medium
Topics
premium lock icon
Companies
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.









class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        vector<int>dp(n,1),hash(n);

        int maxi=0,lastidx=0;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }

            if(dp[i]>maxi){
                maxi=dp[i];
                lastidx=i;
            }
        }

        vector<int>ans;
        ans.push_back(nums[lastidx]);

        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            ans.push_back(nums[lastidx]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
