











1) i think this

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    long long int solve(vector<long long int>& nums,int i,int n){
        long long int sum=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            sum*=nums[j];
        }
        return sum;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        vector<long long int>ans;
        
        for(int i=0;i<nums.size();i++){
            long long int product=solve(nums,i,nums.size());
            ans.push_back(product);
        }
        return ans;
    }
};


O(n^2) t.c and O(2*n) s.c

