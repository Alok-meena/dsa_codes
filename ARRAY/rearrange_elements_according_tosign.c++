You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>positive(n/2);
        vector<int>negative(n/2);
        
        int i=0;
        int j=0;
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                positive[i++]=nums[k];
            }
            else if(nums[k]<0){
                negative[j++]=nums[k];
            }
        }
        
        vector<int>ans;
        int even=0;
        int odd=0;
        for(int i=0;i<n/2;i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }

        return ans;
    }
};
t.c:-O(n) and s.c:-O(2n) n/2 and n/2 for positive and negative and n for ans


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        
        int i=0;
        int j=0;
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                ans[2*i]=nums[k];
                i++;
            }
            else if(nums[k]<0){
               ans[2*j+1]=nums[k];
               j++;
            }
        }
        
        

        return ans;
    }
};
t.c:-O(n) and s.c:-O(n)
