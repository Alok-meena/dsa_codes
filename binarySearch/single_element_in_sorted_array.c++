540. Single Element in a Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr=0;
        for(auto i:nums){
            xr=xr^i;
        }
        return xr;
    }
};

or 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1]) return nums[i];
            }
            else if(i==n-1){
                if(nums[i]!=nums[i-1]) return nums[i];
            }
            else{
                if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1]) return nums[i];
            }
        }

        return -1;
    }
};

t.c:-o(n) 

optimized t.c:-O(logn)

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];

        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        int i=0,j=n-1;

        while(i<=j){
            int mid=(i+j)/2;

            if(arr[mid]!=arr[mid+1] and arr[mid]!=arr[mid-1]) return arr[mid];

            if((mid%2!=0 and arr[mid]==arr[mid-1]) or (mid%2==0 and arr[mid]==arr[mid+1])){
                i=mid+1;
            }
            else j=mid-1;
        }
        return -1;
    }
};
