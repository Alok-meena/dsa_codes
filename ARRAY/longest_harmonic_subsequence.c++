
Code


Testcase
Testcase
Test Result
594. Longest Harmonious Subsequence
Solved
Easy
Topics
premium lock icon
Companies
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]

Output: 2

Explanation:

The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:

Input: nums = [1,1,1,1]

Output: 0

Explanation:

No harmonic subsequence exists.

 

Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109



to jab bhi max min ho length puchi ho then we dont need to genearte all subsequences alright dekho ager diff 1 hona chahihe max and min ka to apne subsequence 
me only 2 hi unique element honge alright so we will store their count in map and check if curr val+1 exist in map then store both count sum addition and max of ans
alright bs yhi to logic tha

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(auto i:nums) freq[i]++;

        int ans=0;

        for(auto i:freq){
            if(freq.count(i.first+1)){
                ans=max(ans,i.second+freq[i.first+1]);
            }
        }

        return ans;
    }
};

t.c:-O(n) and s.c:-O(n)
