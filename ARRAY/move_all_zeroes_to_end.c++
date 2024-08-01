Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]



using space we can store non zero elements and then store them at the front of the array and then store remaining places with zeroes

1st:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        int zero=0;
        

        while(zero<n){
            if(nums[zero]==0){
                int i=zero+1;
                while(i<n && nums[i]==0){
                    i++;
                    continue;
                }
                if(i<n){
                    swap(nums[i],nums[zero]);
                }
                zero++;
            }
            else{
                zero++;
            }
        }
    }
};

t.c:-O(n^2) worst case O(1) space complexity

2:
  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        

        int zero=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zero]);
                zero++;
            }
        }
    }
};

O(n) and O(1) are t.c and s.c



