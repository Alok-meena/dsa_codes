33. Search in Rotated Sorted Array
Solved
Medium
Topics
Companies
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
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104







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
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
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





#include <bits/stdc++.h>
using namespace std;


bool binarysearch(vector<int>&v,int low,int high,int k){
    if(low>high){
        return false;
    }

    int mid=(low+high)/2;
    if(v[mid]==k) return true;
    
    if(v[mid]<k) return binarysearch(v,mid+1,high,k);
    return binarysearch(v,low,mid-1,k);
}
int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>v={2,3,4,5,1,2};
    int n=v.size();

    int low=0;
    int high=n-1;
    int val=1;

    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]==val){
            cout<<"find "<<v[mid]<<" at "<<mid;
            break;
        }
        //left part sorted
        if(v[low]<=v[mid]){
            //now if left is sorted then we have to decide to move to which part left or right so if the val is greater than low and less than mid then move to left
          //o/w move to right
            if(v[low]<=val && val<=v[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        //right part sorted
        else{
          //in this if right part is sorted and val is greater than or equal to mid and less than or equal to high then move to right o/w move to left
            if(v[mid]<=val && val<=v[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

    }

     t.c:-O(logn) and s.c:-O(1)
}
