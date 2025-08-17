1838. Frequency of the Most Frequent Element
Solved
Medium
Topics
premium lock icon
Companies
Hint
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int l=0,r=0;
        int n=nums.size();
        int count=0;
        long long sum=0;

        while(r<n){
            sum+=nums[r];

            long long total=1LL*nums[r]*(r-l+1);
            int changes=total-sum;
            
            if(1LL*(r-l+1)*nums[r]-sum>k){
                sum-=nums[l];
                l++;
            }
            count=max(count,r-l+1);
            r++;    
        }

        return count;
    }
};


and if we do decrement also then we have to use median concept


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // prefix sums to compute cost quickly
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int ans = 1;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // check window [l..r]
            while (l <= r) {
                int mid = (l + r) / 2; // median index
                long long median = nums[mid];

                // cost to make all nums[l..r] equal to median
                long long leftCost = median * 1LL * (mid - l) - (prefix[mid] - prefix[l]);
                long long rightCost = (prefix[r+1] - prefix[mid+1]) - median * 1LL * (r - mid);

                long long cost = leftCost + rightCost;

                if (cost <= k) {
                    ans = max(ans, r - l + 1);
                    break; // this window works, try bigger r
                } else {
                    l++; // shrink from left
                }
            }
        }

        return ans;
    }
};

t.c:-O(nlogn)
