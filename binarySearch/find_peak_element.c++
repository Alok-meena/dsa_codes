162. Find Peak Element
Solved
Medium
Topics
Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.





brute force 

O(n) t.c and O(1) is the s.c alright

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if((i==0 or nums[i-1]<nums[i]) and (i==n-1 or nums[i]>nums[i+1])){
                return i;
            }
        }

        return -1;
    }
};






this runs correctly 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        // Binary search approach
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak lies in the left half
                high = mid;
            } else {
                // Peak lies in the right half
                low = mid + 1;
            }
        }
        
        return low;  // The peak element is at index `low`
    }
};

i dont understand this above one


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1;
        int h=nums.size()-2;
        int n=nums.size();

        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};

it is understandable here we have the 3 cases handled and binary serach on remaning part alright

or if we dont want this then 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1;
        int h=nums.size()-2;
        int n=nums.size();

        if(n==1) return 0;

        while(l<=h){
            int mid=(l+h)/2;

            if((mid-1>=0 and nums[mid]>nums[mid-1]) and (mid+1<=n-1 and nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid-1>=0 and nums[mid]>nums[mid-1]) l=mid+1;
            else h=mid-1;
        }
        return nums[0]>nums[n-1] and nums[0]>nums[1]?0:n-1;
    }
};

logn to bhai bs ye 3 case to alag se handle krne hi padenge alright

