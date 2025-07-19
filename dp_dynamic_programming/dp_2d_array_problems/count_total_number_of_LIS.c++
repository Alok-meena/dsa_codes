673. Number of Longest Increasing Subsequence
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
The answer is guaranteed to fit inside a 32-bit integer.



same to same printing lis code alright explained in copy







class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();

        vector<int>dp(n,1),count(n,1);

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    count[i]=count[prev];
                }
                else if(arr[prev]<arr[i] and 1+dp[prev]==dp[i]){  //mtlb pahle koi hai is count ke sath to mila lo o/w pahle jitna hi rhne do
                    count[i]+=count[prev];
                }
            }

            maxi=max(maxi,dp[i]);
        }

        int no=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) no+=count[i];
        }

        return no;
    }
};
