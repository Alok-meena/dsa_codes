
Code
Test Result
Testcase
Testcase
930. Binary Subarrays With Sum
Solved
Medium
Topics
premium lock icon
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length



brute : O(n) t.c and s.c

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        unordered_map<int,int>mp;
        int currsum=0;

        for(auto i:nums){
            currsum+=i;

            if(currsum==goal){
                count++;
            }

            if(mp.find(currsum-goal)!=mp.end()){
                count+=mp[currsum-goal];
            }

            mp[currsum]++;
        }

        return count;
    }
};




most optimized :

use code for window approach <=k - <=k-1 alright that/s it

class Solution {
public:
    int solve(vector<int>&nums,int goal){
        int count=0;
        int currsum=0;
        if(goal<0) return 0;

        int l=0,r=0;

        while(r<nums.size()){
            currsum+=nums[r];

            while(currsum>goal){
                currsum-=nums[l];
                l++;
            }

            if(currsum<=goal){
                count=count+(r-l+1);
            }
            r++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};
