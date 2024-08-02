Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]





class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>output,vector<int>nums,int index){
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }

        //exclude
        solve(ans,output,nums,index+1);

        //include
        int element=nums[index];
        output.push_back(element);
        solve(ans,output,nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;//here we are not aware of the columns size so we use this type of initialization
        vector<int>output;//to push it into the ans
        solve(ans,output,nums,0);
        return ans;
    }
};
