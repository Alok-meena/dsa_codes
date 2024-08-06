
 A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]






using stl:

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int>ans;
    next_permutation(permutation.begin(),permutation.end());//it will automatically update the given array passed in it
    for(auto i:permutation){
        ans.push_back(i);
    }
    return ans;
}


1: i tried but does not work as it is not optimized

class Solution {
public:
    void permutation(vector<int>nums,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            permutation(nums,index+1,ans);
            swap(nums[index],nums[j]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums,0,ans);

        int index=-1;

        for(int i=0;i<ans.size();i++){
            if(ans[i]==nums){
                index=i+1;
                break;
            }
        }

        if(index>=ans.size()){
           sort(nums.begin(),nums.end());
        }
        else{
         nums=ans[index];
        }



    }
};


2: most optimized soln

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int index=-1;

        for(int i=n-2;i>=0;i--){//we have started from n-2 because we are comparig it with one element further
            if(permutation[i]<permutation[i+1]){
                index=i;
                break;
            }
        }
 
        //aor ager index==-1 hai to means ki ham abhi last permutation pe hai ex 654321 and to get first one just reverse it 123456

 
        if(index==-1){
            reverse(permutation.begin(),permutation.end());
            return permutation;
        }

        for(int i=n-1;i>index;i--){
            if(permutation[index]<permutation[i]){
                swap(permutation[index],permutation[i]);
                break;
            }
        }

        reverse(permutation.begin()+index+1,permutation.end());

        return permutation;
}
t.c:-O(n) and s.c:-O(1) here t.c is O(3n) due to 3 loops which is O(n)
