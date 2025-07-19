
Code
Test Result
Testcase
Testcase
2035. Partition Array Into Two Arrays to Minimize Sum Difference
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

 

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
 

Constraints:

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 107

dekho subarray ( subsequence with tar sum ) is true or not in array 

that que concept is used here so in that ques bottom up approach if gone downword then first row o/w last 

states that whether 0 - tar sum's are possible or not in the given array then just check which are possible if yes find s2 by subtracting from total sum

then find abs(s1-s2) and store min that's it



int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	 int sum=0;

        for(auto i:arr) sum+=i;
        
        vector<vector<int>>dp(arr.size()+2,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
          
        for(int idx=n-1;idx>=0;idx--){
            for(int target=1;target<=sum;target++){
                bool inc=false,exc=false;
                if(target-arr[idx]>=0 and arr[idx]<=target) inc=dp[idx+1][target-arr[idx]];
                exc=dp[idx+1][target];
                
                dp[idx][target]=inc or exc;
            }
        }
        
        vector<pair<int,int>>v;
        int mini=INT_MAX;

        for(int tar=0;tar<=sum;tar++){
            if(dp[0][tar]){
                int val=sum-tar;
                int diff=abs(tar-val);
                mini=min(mini,diff);
            }
        }

        return mini;
}



simple ques
