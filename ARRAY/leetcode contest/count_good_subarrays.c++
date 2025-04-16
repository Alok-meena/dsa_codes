2537. Count the Number of Good Subarrays
Attempted
Medium
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109



brute force :

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long goodSubarrays = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int pairs = 0;

            for (int j = i; j < n; j++) {
                // Count pairs using freq map
                pairs += freq[nums[j]]; //ab dekho nums = [3,1,4,3,2,2,4], k = 2 isme jab 3 vapas aayega to uska count pahle se 1 hai to pair bn gya bs
                //ese hi kr rhe hai ham aor jaise hi vapas aaya to pair bd jayega and if >=k hua to ans++ kr diya bs
                freq[nums[j]]++;

                if (pairs >= k)
                    goodSubarrays++;
            }
        }

        return goodSubarrays;
    }
};

here we are just traversing on all subarrays and counting each pair with i<j and a[i]==a[j]


t.c:-O(n^2) 
