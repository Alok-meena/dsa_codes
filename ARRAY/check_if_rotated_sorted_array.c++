1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
 

 

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100



only 2 pairs exit in this case
case 1 is : 1 2 3 4 5 in this case a[n-1]>a[0] alright o rotations alright
case 2 is : 4 5 1 2 3 in this case only pair exit in a[i-1]>a[i] only one should exist alright so if ans is <=1 then return true o/w false  alright
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }

        if(nums[n-1]>nums[0]) count++;

        if(count<=1) return true;
        return false;
    }
};

t.c:-O(n) and s.c:-O(1)
