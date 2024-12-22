100464. Maximum Number of Distinct Elements After Operations
User Accepted:3367
User Tried:6617
Total Accepted:3493
Total Submissions:16318
Difficulty:Medium
You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

 

Example 1:

Input: nums = [1,2,2,3,3,4], k = 2

Output: 6

Explanation:

nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:

Input: nums = [4,4,4,4], k = 1

Output: 3

Explanation:

By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109


brute force

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int maxDistinctAfterOperations(vector<int>& nums, int k) {
    // Sort the array
    sort(nums.begin(), nums.end());
    
    // Use a set to store distinct values
    set<int> distinct;
    
    for (int num : nums) {
        // Try to find a distinct value in the range [num-k, num+k]
        for (int val = num - k; val <= num + k; ++val) {
            if (distinct.find(val) == distinct.end()) {
                distinct.insert(val);
                break; // Stop after finding the first available distinct value
            }
        }
    }
    
    return distinct.size();
}

t.c:-O(n*(k+1)logn) s.c:-O(n)



#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        unordered_set<int> distinct;   // Set to store distinct values
        
        int next_available = INT_MIN; // Tracks the next available distinct value
        
        for (auto num : nums) {
            // Restrict `next_available` to the range [num-k, num+k]
            next_available = max(next_available, num - k);
            
            if (next_available <= num + k) {
                distinct.insert(next_available);
                ++next_available; // Move to the next available value
            }
        }
        
        return distinct.size();
    }
};

here we are inserting the distinct elements to the set after performing the operations on each element

t.c:-O(nlogn) and s.c:-O(n)
