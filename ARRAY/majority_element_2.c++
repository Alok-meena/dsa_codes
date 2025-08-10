229. Majority Element II
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?






class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;

        for(auto i:nums){
            if(cnt1==0 and i!=ele2){
                cnt1=1;
                ele1=i;
            }
            else if(cnt2==0 and i!=ele1){
                cnt2=1;
                ele2=i;
            }
            else if(ele1==i){
                cnt1++;
            }
            else if(ele2==i){
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
            }
        }

        cnt1=0,cnt2=0;

        for(auto i:nums){
            if(i==ele1) cnt1++;
            if(i==ele2) cnt2++;
        }

        vector<int>ans;
        if(cnt1>(n/3)) ans.push_back(ele1);
        if(cnt2>(n/3)) ans.push_back(ele2);

        return ans;
    }
};
