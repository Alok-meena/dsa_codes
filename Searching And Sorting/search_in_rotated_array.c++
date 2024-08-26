There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


1) burte force solution

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};

t.c:-O(n) and s.c:-O(1)

2) binarysearch O(logn)


class Solution {
public:
    int solve(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;
            
            //two cases as always either it will be left sorted or right sorted okkk
            //either left sorted

            //if true means left part is sorted to the the left of the mid o/w mid to high is sorted
            if(nums[low]<=nums[mid]){
                //now checck if target lies in this range or not
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;//so if this is the case we are eliminating the right half o/w eliminate the left half
                }
                else{
                    low=mid+1;
                }
            }
            //right sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;//eliminate the left half o/w elimiate the right half
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};

O(1) s.c




