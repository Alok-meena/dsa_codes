2873. Maximum Value of an Ordered Triplet I
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
 

Constraints:

3 <= nums.length <= 100
1 <= nums[i] <= 106



brute force t.c:-O(N^3)

Code
C++
#include <bits/stdc++.h>
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long value=(long long)(nums[i]-nums[j])*nums[k];
                    ans=max(ans,value);
                }
            }
        }
        return ans;
    }
};


optimized O(n)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxElement = 0, maxDiff = 0;
        for (long num : nums) {
           //this order should not be changed
            
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
            maxTriplet = max(maxTriplet, maxDiff * num);
        }
        return maxTriplet;
    }
};


what if we change the order

Breaking It Down by Steps
1️⃣ Updating maxTriplet
cpp
Copy
Edit
maxTriplet = max(maxTriplet, maxDiff * num);
Uses the previous maxDiff value to compute maxTriplet.

Ensures j < k order.

If we updated maxDiff before maxTriplet, the new maxDiff (for the current num) would be used incorrectly.

2️⃣ Updating maxDiff
cpp
Copy
Edit
maxDiff = max(maxDiff, maxElement - num);
Uses the previous maxElement to calculate maxDiff.

Ensures i < j order.

If we updated maxElement before maxDiff, the maxElement value would be from this iteration, breaking the correct order.

3️⃣ Updating maxElement
cpp
Copy
Edit
maxElement = max(maxElement, num);
Ensures maxElement is always the highest value seen so far.

Used in future iterations to calculate maxDiff.

What Happens if We Change the Order?
Wrong Order 1:
cpp
Copy
Edit
maxElement = max(maxElement, num);
maxDiff = max(maxDiff, maxElement - num);
maxTriplet = max(maxTriplet, maxDiff * num);
Issue: maxElement is updated before maxDiff
When calculating maxDiff, we are using a newly updated maxElement, which might be from the same iteration.

This violates the requirement that maxElement should be from an earlier index.

Wrong Order 2:
cpp
Copy
Edit
maxDiff = max(maxDiff, maxElement - num);
maxTriplet = max(maxTriplet, maxDiff * num);
maxElement = max(maxElement, num);
Issue: maxTriplet is updated before maxElement
maxTriplet is calculated using maxDiff, but maxDiff is based on an outdated maxElement.

This leads to a case where j > i is violated.

Key Takeaways
✅ The order ensures the correct sequence:

Compute maxTriplet first (ensuring j < k).

Update maxDiff next (ensuring i < j).

Update maxElement last (ensuring i is always earlier).

🚨 Changing the order leads to incorrect values because it violates i < j < k ordering.
