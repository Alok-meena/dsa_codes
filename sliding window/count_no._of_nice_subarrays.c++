
Code


Test Result
Testcase
Testcase
1248. Count Number of Nice Subarrays
Attempted
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length


brute

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==1) cnt++;
                if(cnt==k) count++;
                else if(cnt>k) break;
            }
        }

        return count;
    }
};


optimzied


exact similar to binary subarray with sum k

class Solution {
public:
    int solve(vector<int>&nums,int goal){
        int count=0;
        int currsum=0;
        if(goal<0) return 0;

        int l=0,r=0;

        while(r<nums.size()){
            currsum+=(nums[r]%2);

            while(currsum>goal){
                currsum-=(nums[l]%2);
                l++;
            }

            if(currsum<=goal){
                count=count+(r-l+1);
            }
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
