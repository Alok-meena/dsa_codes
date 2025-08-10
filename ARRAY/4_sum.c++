18. 4Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109





brute force : t.c:-O(n^4) + O(nlogn) alright

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int m=k+1;m<n;m++){
                        long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[m];
                        if(sum==(long long)target){
                            ans.insert({nums[i],nums[j],nums[k],nums[m]});
                        }
                    }
                }
            }
        }

        vector<vector<int>>a(ans.begin(),ans.end());

        return a;
    }
};

optimized O(n^3 * logn) due to set insertion




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1,m=n-1;
                while(k<m){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum==target){
                        ans.insert({nums[i],nums[j],nums[k],nums[m]});
                        k++;m--;
                    }
                    else if(sum>target){
                        m--;
                    }
                    else k++;
                }
            }
        }

        vector<vector<int>>a(ans.begin(),ans.end());

        return a;
    }
};

can skip duplicates like this also


t.c:-O(N^3) + O(NlogN)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        int n=nums.size();

        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1,m=n-1;
                while(k<m){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[m]});
                        k++;m--;
                        while(k<m and nums[k]==nums[k-1]) k++;
                        while(m>k and nums[m]==nums[m+1]) m--;
                    }
                    else if(sum>target){
                        m--;
                    }
                    else k++;
                }
            }
        }

        return ans;
    }
};
