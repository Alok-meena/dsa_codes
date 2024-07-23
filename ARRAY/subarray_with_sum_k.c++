Sure, let's understand the differences between subarrays and subsequences with some examples to clarify the concepts.

Subarray
A subarray is a contiguous part of an array. This means that all elements of a subarray must be consecutive elements of the original array.

Example:

Given an array [1, 2, 3, 4], the possible subarrays include:

[1]
[2]
[3]
[4]
[1, 2]
[2, 3]
[3, 4]
[1, 2, 3]
[2, 3, 4]
[1, 2, 3, 4]
Key Points:

Subarrays are always contiguous.
The number of subarrays of an array of length n is n * (n + 1) / 2.
Subsequence
A subsequence is a sequence derived from another sequence by deleting some or no elements without changing the order of the remaining elements. This means that subsequences do not need to be contiguous but must maintain the order of elements as in the original array.

Example:

Given an array [1, 2, 3, 4], some possible subsequences include:

[1]
[2]
[3]
[4]
[1, 2]
[1, 3]
[1, 4]
[2, 3]
[2, 4]
[3, 4]
[1, 2, 3]
[1, 2, 4]
[1, 3, 4]
[2, 3, 4]
[1, 2, 3, 4]
Key Points:

Subsequences do not need to be contiguous.
The number of subsequences of an array of length n is 2^n (including the empty subsequence).
Visual Comparison
Let's consider an array [A, B, C, D].

Subarrays:

[A], [B], [C], [D]
[A, B], [B, C], [C, D]
[A, B, C], [B, C, D]
[A, B, C, D]
Subsequences:

[A], [B], [C], [D]
[A, B], [A, C], [A, D], [B, C], [B, D], [C, D]
[A, B, C], [A, B, D], [A, C, D], [B, C, D]
[A, B, C, D]
Conclusion
Subarrays are always contiguous and are a subset of the array elements.
Subsequences can be non-contiguous but must maintain the relative order of the original elements.



Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


1:brute force

  class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int current=0;
            for(int j=i;j<n;j++){
                current+=nums[j];
                if(current==k){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

t.c:-O(N^2) ans constant space complexity

2: optimized











  
