992. Subarrays with K Different Integers
Attempted
Hard
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length


brute:

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count=0;
        
        int n=nums.size();

        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int j;
            
            for(j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==k) count++;
                else if(mp.size()>k) break;
            }
        }
        return count;
    }
};

optimized


same as preivous ques binary subarrays with sum k like 

with <=k diff int - <=k-1 diff int alright


class Solution {
public:
    int solve(vector<int>&nums,int k){
        int count=0;
        
        int n=nums.size();

        int l=0,r=0;

        unordered_map<int,int>mp;

        while(r<n){
            mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }

            if(mp.size()<=k) count+=(r-l+1);
            r++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
