class Solution {
    private:
    void permutation(vector<int> nums,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){ //to ise hamne pure nums ki size tk chlaya hai alright to swap with each ele alright
            swap(nums[index],nums[j]);
            permutation(nums,index+1,ans);
            swap(nums[index],nums[j]); //it is required only when the vector is passed by reference o/w if by value no need 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        permutation(nums,index,ans);
        return ans;
    }
};
