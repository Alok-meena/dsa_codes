907. Sum of Subarray Minimums
Attempted
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104




brute force alrigt O(n^2)

class Solution {
public:
    int mod=1e9+7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int mini=INT_MAX;
                for(int k=j;k<=i;k++){
                    mini=min(mini,arr[k]);
                }
                sum=(sum+mini)%mod;
            }
        }

        return sum;
    }
};
