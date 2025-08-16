1004. Max Consecutive Ones III
Attempted
Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length


  brute force  : convert ques to longest subarray with atmost k zeros alright

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int zeros=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) zeros++;
                if(zeros<=k) len=max(len,j-i+1);
                else break;
            }
        }

        return len;
    }
};

t.c:-O(n^2) and s.c:-O(1) alright

optimized: t.c:-O(2*n) and s.c:-O(1)

to do in O(n) use if instead of inner while alright
