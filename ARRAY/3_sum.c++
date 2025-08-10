15. 3Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105






brute force : t.c:-O(N^3) and s.c:-O(1) jo use hui only to return the ans which is required 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tar=0;
        set<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==tar){
                        ans.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }

        vector<vector<int>>a(ans.begin(),ans.end());

        return a;
    }
};


little optimized : O(n^2) t.c

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int tar=-nums[i];

            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==tar){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k--;j++;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(k>j and nums[k]==nums[k+1]) k--;
                }
                else if(sum>tar){
                    k--;
                }
                else j++;
            }
        }

        return ans;
    }
};

sorting is required for using 2 ptr approach

can use set also because to skip duplicates which is done above for each i j and k if equal to prev or next then skip it alright

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<n-2;i++){
            int tar=-nums[i];

            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==tar){
                    ans.insert({nums[i],nums[j],nums[k]});
                    k--;j++;
                }
                else if(sum>tar){
                    k--;
                }
                else j++;
            }
        }

        vector<vector<int>>a(ans.begin(),ans.end());

        return a;
    }
};

but t.c:-O(n^2 * logn) due to insertion of set but if we use unordered_set then it will be O(n^2) but worst case O(n^2) * O(n^2) === O(n^4) alright
