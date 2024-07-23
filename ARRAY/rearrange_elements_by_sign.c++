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
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 




class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int>ans;
       int n=nums.size()/2;
       int negative[n];
       int positive[n];
       int d=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            negative[d++]=nums[i];
        }
       }
       int f=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            positive[f++]=nums[i];
        }
       }

       int k=0;

       for(int i=0;i<nums.size()/2;i++){
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
       }
       return ans;

       
    }
};


2nd

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
